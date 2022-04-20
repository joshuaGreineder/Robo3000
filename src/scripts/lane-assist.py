#!/usr/bin/env python3

import numpy as np
import cv2
import math
import serial
import os
import time
import logging
import rospy
from std_msgs.msg import String
import keyboard
from geometry_msgs.msg import Twist

sensitivity = 15


def detect_edges(frame):
    # filter for blue lane lines
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    cv2.imshow("hsv", hsv)

    lower_blue = np.array([80, 80, 80])
    upper_blue = np.array([190, 255, 255])

    #lower_blue= np.array([78,158,124])
    #upper_blue = np.array([138,255,255])

    #lower_white = np.array([0, 0, 255-sensitivity])
    #upper_white = np.array([255, 255, 255])

    #lower_white = np.array([0, 0, 195])
    #upper_white = np.array([255, 255, 255])

    mask = cv2.inRange(hsv, lower_blue, upper_blue)
    cv2.imshow("blue mask", mask)

    # detect edges
    edges = cv2.Canny(mask, 200, 400)

    return edges


def region_of_interest(edges):
    height, width = edges.shape
    mask = np.zeros_like(edges)

    # only focus bottom half of the screen
    polygon = np.array([[
        (0, height * 1 / 2),
        (width, height * 1 / 2),
        (width, height),
        (0, height),
    ]], np.int32)

    cv2.fillPoly(mask, polygon, 255)
    cropped_edges = cv2.bitwise_and(edges, mask)
    return cropped_edges


def detect_line_segments(cropped_edges):
    # tuning min_threshold, minLineLength, maxLineGap is a trial and error process by hand
    rho = 1  # distance precision in pixel, i.e. 1 pixel
    angle = np.pi / 180  # angular precision in radian, i.e. 1 degree
    min_threshold = 10  # minimal of votes
    line_segments = cv2.HoughLinesP(cropped_edges, rho, angle, min_threshold,
                                    np.array([]), minLineLength=8, maxLineGap=4)

    return line_segments


def average_slope_intercept(frame, line_segments):
    """
    This function combines line segments into one or two lane lines
    If all line slopes are < 0: then we only have detected left lane
    If all line slopes are > 0: then we only have detected right lane
    """
    lane_lines = []
    if line_segments is None:
        logging.info('No line_segment segments detected')
        return lane_lines

    height, width, _ = frame.shape
    left_fit = []
    right_fit = []

    boundary = 1/3
    # left lane line segment should be on left 2/3 of the screen
    left_region_boundary = width * (1 - boundary)
    # right lane line segment should be on left 2/3 of the screen
    right_region_boundary = width * boundary

    for line_segment in line_segments:
        for x1, y1, x2, y2 in line_segment:
            if x1 == x2:
                logging.info(
                    'skipping vertical line segment (slope=inf): %s' % line_segment)
                continue
            fit = np.polyfit((x1, x2), (y1, y2), 1)
            slope = fit[0]
            intercept = fit[1]
            if slope < 0:
                if x1 < left_region_boundary and x2 < left_region_boundary:
                    left_fit.append((slope, intercept))
            else:
                if x1 > right_region_boundary and x2 > right_region_boundary:
                    right_fit.append((slope, intercept))

    left_fit_average = np.average(left_fit, axis=0)
    if len(left_fit) > 0:
        lane_lines.append(make_points(frame, left_fit_average))

    right_fit_average = np.average(right_fit, axis=0)
    if len(right_fit) > 0:
        lane_lines.append(make_points(frame, right_fit_average))

    # [[[316, 720, 484, 432]], [[1009, 720, 718, 432]]]
    logging.debug('lane lines: %s' % lane_lines)

    return lane_lines


def make_points(frame, line):
    height, width, _ = frame.shape
    slope, intercept = line
    y1 = height  # bottom of the frame
    y2 = int(y1 * 1 / 2)  # make points from middle of the frame down

    # bound the coordinates within the frame
    # if(slope >= 0):
    x1 = max(-width, min(2 * width, int((y1 - intercept) / slope)))
    x2 = max(-width, min(2 * width, int((y2 - intercept) / slope)))
    # else:
    #    print("infinity")
    #    x1 = x1
    #    x2 = x2
    return [[x1, y1, x2, y2]]


def display_lines(frame, lines, line_color=(0, 255, 0), line_width=20):
    line_image = np.zeros_like(frame)
    if lines is not None:
        for line in lines:
            for x1, y1, x2, y2 in line:
                cv2.line(line_image, (x1, y1), (x2, y2),
                         line_color, line_width)
    line_image = cv2.addWeighted(frame, 0.8, line_image, 1, 1)
    return line_image

# lane_lines_image = display_lines(frame, lane_lines)
# cv2.imshow("lane lines", lane_lines_image)


def detect_lane(frame):
    edges = detect_edges(frame)
    cropped_edges = region_of_interest(edges)
    line_segments = detect_line_segments(cropped_edges)
    lane_lines = average_slope_intercept(frame, line_segments)

    return lane_lines


def display_heading_line(frame, steering_angle, line_color=(0, 0, 255), line_width=10):
    heading_image = np.zeros_like(frame)
    height, width, _ = frame.shape

    # figure out the heading line from steering angle
    # heading line (x1,y1) is always center bottom of the screen
    # (x2, y2) requires a bit of trigonometry

    # Note: the steering angle of:
    # 0-89 degree: turn left
    # 90 degree: going straight
    # 91-180 degree: turn right
    steering_angle_radian = steering_angle / 180.0 * math.pi
    x1 = int(width / 2)
    y1 = height
    x2 = int(x1 - height / 2 / math.tan(steering_angle_radian))
    y2 = int(height / 2)

    cv2.line(heading_image, (x1, y1), (x2, y2), line_color, line_width)
    heading_image = cv2.addWeighted(frame, 0.8, heading_image, 1, 1)

    return heading_image


def compute_steering_angle(frame, lane_lines):
    """ Find the steering angle based on lane line coordinate
        We assume that camera is calibrated to point to dead center
    """
    if len(lane_lines) == 0:
        logging.info('No lane lines detected, do nothing')
        return -90

    height, width, _ = frame.shape
    if len(lane_lines) == 1:
        logging.debug(
            'Only detected one lane line, just follow it. %s' % lane_lines[0])
        x1, _, x2, _ = lane_lines[0][0]
        x_offset = x2 - x1
    else:
        _, _, left_x2, _ = lane_lines[0][0]
        _, _, right_x2, _ = lane_lines[1][0]
        # 0.0 means car pointing to center, -0.03: car is centered to left, +0.03 means car pointing to right
        camera_mid_offset_percent = 0.02
        mid = int(width / 2 * (1 + camera_mid_offset_percent))
        x_offset = (left_x2 + right_x2) / 2 - mid

    # find the steering angle, which is angle between navigation direction to end of center line
    y_offset = int(height / 2)

    # angle (in radian) to center vertical line
    angle_to_mid_radian = math.atan(x_offset / y_offset)
    # angle (in degrees) to center vertical line
    angle_to_mid_deg = int(angle_to_mid_radian * 180.0 / math.pi)
    # this is the steering angle needed by picar front wheel
    steering_angle = angle_to_mid_deg + 90

    logging.debug('new steering angle: %s' % steering_angle)
    return steering_angle


def display_heading_line(frame, steering_angle, line_color=(0, 0, 255), line_width=5, ):
    heading_image = np.zeros_like(frame)
    height, width, _ = frame.shape

    # figure out the heading line from steering angle
    # heading line (x1,y1) is always center bottom of the screen
    # (x2, y2) requires a bit of trigonometry

    # Note: the steering angle of:
    # 0-89 degree: turn left
    # 90 degree: going straight
    # 91-180 degree: turn right
    steering_angle_radian = steering_angle / 180.0 * math.pi
    x1 = int(width / 2)
    y1 = height
    if(math.tan(steering_angle_radian) != 0):
        x2 = int(x1 - height / 2 / math.tan(steering_angle_radian))
    else:
        x2 = 90
    y2 = int(height / 2)

    cv2.line(heading_image, (x1, y1), (x2, y2), line_color, line_width)
    heading_image = cv2.addWeighted(frame, 0.8, heading_image, 1, 1)

    return heading_image


def stabilize_steering_angle(curr_steering_angle, new_steering_angle, num_of_lane_lines,
                             max_angle_deviation_two_lines=5, max_angle_deviation_one_lane=1):
    """
    Using last steering angle to stabilize the steering angle
    This can be improved to use last N angles, etc
    if new angle is too different from current angle, only turn by max_angle_deviation degrees
    """
    if num_of_lane_lines == 2:
        # if both lane lines detected, then we can deviate more
        max_angle_deviation = max_angle_deviation_two_lines
    else:
        # if only one lane detected, don't deviate too much
        max_angle_deviation = max_angle_deviation_one_lane

    angle_deviation = new_steering_angle - curr_steering_angle
    if abs(angle_deviation) > max_angle_deviation:
        stabilized_steering_angle = int(curr_steering_angle
                                        + max_angle_deviation * angle_deviation / abs(angle_deviation))
    else:
        stabilized_steering_angle = new_steering_angle
    logging.info('Proposed angle: %s, stabilized angle: %s' %
                 (new_steering_angle, stabilized_steering_angle))
    return stabilized_steering_angle


if __name__ == '__main__':

    rospy.init_node('lane_vision')
    pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)

    cap = cv2.VideoCapture(0)
    width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
    height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
    curr_steering_angle = 90

    # Camera Matrix
    mtx = np.array([[878.77419906, 0., 252.28234033],
                    [0., 807.06689799, 387.71265873],
                    [0., 0., 1.]])

    # Distortion Coefficient
    dist = np.array(
        [-0.02653373, 0.26730063, 0.00569894, 0.0331745, -0.2249799])

    # Not needed yet, but may be helpful in the future
    rotation_vectors = np.array([[-0.25265206],
                                 [-0.37538554],
                                 [1.4827682]])

    translation_vectors = np.array([[0.11436085],
                                    [-0.16678751],
                                    [0.44949997]])

    while(True):
        ret, frame = cap.read()

        height, width, _ = frame.shape

        # Create optimal_camera_matrix specific to current frame
        optimal_camera_matrix, roi = cv2.getOptimalNewCameraMatrix(
            mtx, dist, (width, height), 1, (width, height))

        # Undistort the image
        undistorted_image = cv2.undistort(
            frame, mtx, dist, None, optimal_camera_matrix)

        blur = cv2.GaussianBlur(undistorted_image, (5, 5), cv2.BORDER_DEFAULT)

        edges = detect_edges(blur)

        roi = region_of_interest(edges)

        lines = detect_line_segments(roi)

        lane_lines = average_slope_intercept(frame, lines)

        lane_lines_image = display_lines(frame, lane_lines)
        steering_angle = compute_steering_angle(frame, lane_lines)

        new_steering_angle = compute_steering_angle(frame, lane_lines)
        curr_steering_angle = stabilize_steering_angle(
            curr_steering_angle, new_steering_angle, len(lane_lines))

        final = display_heading_line(lane_lines_image, curr_steering_angle)

        msg = Twist()

        if len(lane_lines) == 0:
            logging.info('No lane lines detected, do nothing')
            msg.linear.x = 0
            msg.linear.y = 0
            msg.linear.z = 0
            msg.angular.z = 0
        else:
            msg.linear.x = .5
            msg.linear.y = 0
            msg.linear.z = 0
            if(((curr_steering_angle-90) >= -10) and ((curr_steering_angle-90) <= 10)):
                msg.angular.z = 0
            else:
                msg.angular.z = math.radians(curr_steering_angle-90)

        print(str(math.radians(curr_steering_angle-90)))

        pub.publish(msg)

        # curr_steering_angle
        cv2.imshow("lane lines", final)
        #cv2.imshow('final', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        # if keyboard.is_pressed("w"):
         #   sensitivity = sensitivity + 1
          #  print(sensitivity)
        # if keyboard.is_pressed("s"):
         #   sensitivity = sensitivity - 1
          #  print(sensitivity)
