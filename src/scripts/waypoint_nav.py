#!/usr/bin/env python3

# Import needed packages:
import numpy as np
import math
from geopy.distance import geodesic
import serial
import os
import time
import logging
import rospy
from std_msgs.msg import String
import keyboard
from geometry_msgs.msg import Twist
import cv2


'''
 Method description: Takes current latitude and longitude, target latitude and longitude,
                     and heading angle. The output is the the change in your angle needed
                     to go towards the target coordinates.

 Parameters: lat1, long1 > Latitude and Longitude of current point
             lat2, long2 > Latitude and Longitude of target  point
             headX       > current heading angle

 Returns: Degree of a direction from current point to target point
'''


def getOffset(lat1, long1, lat2, long2, headX):
    dLat = math.radians(lat2 - lat1)
    dLon = math.radians(long2 - long1)

    lat1 = math.radians(lat1)
    lat2 = math.radians(lat2)

    current = (lat1, long1)
    target = (lat2, long2)

    y = math.sin(dLon) * math.cos(lat2)
    x = math.cos(lat1) * math.sin(lat2) - math.sin(lat1) * \
        math.cos(lat2) * math.cos(dLon)

    brng = math.degrees(math.atan2(y, x))

    # fix negative degrees
    if (brng < 0):
        brng = 360 - abs(brng)

    return brng - headX, geodesic(current, target).feet


initialize = True
msg = Twist()


while(True):
    # PUBLISHER
    # Create publishing node
    rospy.init_node('waypoint_nav')
    # Set the topic it will publish to
    pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)

    # LIVE LOCATION DATA
    # Find location information...Needed updated to pull live information.
    lat1 = 40.006147
    long1 = -76.343179
    heading = 48
	
	# Target coordinate
    lat2 = 40.006445
    long2 = -76.342737

    # Get waypoint direction and distance data
    distance = getOffset(lat1, long1, lat2, long2, heading)[1]
    changeHeading = getOffset(lat1, long1, lat2, long2, heading)[0]

    # Start up - set robot towards waypoint RUN ONCE
    if(initialize):
        while(abs(changeHeading) > 5):
            changeHeading = getOffset(lat1, long1, lat2, long2, heading)[0]
            msg.linear.x = .5
            msg.angular.z = math.radians(changeHeading)
            pub.publish(msg)
        initialize = False

    # MAIN ROUTINE
    distance = getOffset(lat1, long1, lat2, long2, heading)[1]
    changeHeading = getOffset(lat1, long1, lat2, long2, heading)[0]
	
    msg.linear.x = 4
    msg.angular.z = math.radians(changeHeading)
    pub.publish(msg)

	# Stop if waypoint is reached
    if(distance < 2):
            break

    print("distance: " + str(distance))
    print("change in heading: " + str(changeHeading))

    # PRINT DATA
    '''
    print("-------------------------------------------------------------") 
    print("Current coordinates: " + str(lat1) + " , " + str(long1)) 
    print("Target coordinates: " + str(lat2) + " , " + str(long2)) 

    print("Current heading direction: " + str(heading)) 
    print() 
    print("Distance: " + str(direction[1]) + "   |   Change in angle needed: " + str(direction[0]) + " degrees") 


    '''
