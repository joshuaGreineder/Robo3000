import cv2
import matplotlib.pyplot as plt
import numpy as np
import time
import numpy as np
import cv2
import math
import serial
import os
import time
import logging


def nothing(x):
    pass


cap = cv2.VideoCapture(0)

cv2.namedWindow('image')
# Hue is from 0-179 for Opencv
cv2.createTrackbar('BLeft_x', 'image', 221, 600, nothing)
cv2.createTrackbar('BLeft_y', 'image', 0, 500, nothing)
cv2.createTrackbar('BRight_x', 'image', 373, 600, nothing)
cv2.createTrackbar('BRight_y', 'image', 0, 1000, nothing)
cv2.createTrackbar('TLeft_x', 'image', 31, 200, nothing)
cv2.createTrackbar('TLeft_y', 'image', 0, 1000, nothing)
cv2.createTrackbar('TRight_x', 'image', 685, 1000, nothing)
cv2.createTrackbar('TRight_y', 'image', 0, 1000, nothing)


number = 0
while(True):
    _, frame = cap.read()

    height, width, _ = frame.shape

    IMAGE_H = height
    IMAGE_W = width
    line_color = (0, 255, 0)
    line_width = 20

    src = np.float32([[0, IMAGE_H], [754, IMAGE_H], [0, 0], [IMAGE_W, 0]])
    # src = np.float32([[0, IMAGE_H], [1207, IMAGE_H], [0, 0], [IMAGE_W, 0]])
    # dst = np.float32([[569, IMAGE_H], [711, IMAGE_H], [0, 0], [IMAGE_W, 0]])

    # dst = np.float32([[441+20, 350], [573-35, 350], [-90, IMAGE_H], [IMAGE_W+50, IMAGE_H]])

    # get current positions of all trackbars
    BLeft_x = cv2.getTrackbarPos('BLeft_x', 'image')
    BLeft_y = cv2.getTrackbarPos('BLeft_y', 'image')
    BRight_x = cv2.getTrackbarPos('BRight_x', 'image')
    BRight_y = cv2.getTrackbarPos('BRight_y', 'image')
    TLeft_x = cv2.getTrackbarPos('TLeft_x', 'image')
    TLeft_y = cv2.getTrackbarPos('TLeft_y', 'image')
    TRight_x = cv2.getTrackbarPos('TRight_x', 'image')
    TRight_y = cv2.getTrackbarPos('TRight_y', 'image')

    # dst = np.float32([[400, 0], [600, 0], [-500, IMAGE_H], [1485, IMAGE_H]])
    dst = np.float32([[225, 0], [418, 0], [-105, IMAGE_H], [768, IMAGE_H]])

    # Used for modifying warping manually
    # dst = np.float32([[BLeft_x, BLeft_y], [BRight_x, BRight_y],[-TLeft_x, IMAGE_H], [TRight_x, IMAGE_H]])
    # dst = np.float32([[221, 0],[373, 0],[-31, IMAGE_H],[685, IMAGE_H]])
    print(dst)

    M=cv2.getPerspectiveTransform(src, dst)  # The transformation matrix
    Minv=cv2.getPerspectiveTransform(dst, src)  # Inverse transformation
    cv2.line(frame, (146, 152), (440, 154), line_color, 1)
    cv2.line(frame, (440, 154), (839, 458), line_color, 1)
    cv2.line(frame, (-273, 456), (839, 458), line_color, 1)
    cv2.line(frame, (-273, 456), (146, 152), line_color, 1)

    # cv2.line(frame, (0, 350), (IMAGE_W, 350), (0,0,0), 3)
    # cv2.line(frame, (410, 400), (610, 400), (255,255,255), 3)
    # cv2.line(frame, (335, 450), (670, 450), (255,255,255), 3)
    # cv2.line(frame, (260, 500), (745, 500), (255,255,255), 3)
    # cv2.line(frame, (190, 550), (820, 550), (255,255,255), 3)
    # cv2.line(frame, (120, 600), (890, 600), (255, 255, 255), 3)

    # Apply np slicing for ROI crop
    img=frame[154: (188 + IMAGE_H), 0: IMAGE_W]
    warped_img=cv2.warpPerspective(
        img, M, (IMAGE_W, IMAGE_H))  # Image warping
    #cv2.line(warped_img, (91, 0), (91, IMAGE_H), line_color, 1)
    #cv2.line(warped_img, (497, 0), (497, IMAGE_H), line_color, 1)
    warped_img=cv2.flip(warped_img, 0)

    cv2.imshow("Warped", warped_img)
    cv2.imshow("Frame", frame)

    k=cv2.waitKey(5) & 0xFF
    if k == 27:
        break
cv2.destroyAllWindows()
