#!/usr/bin/env python3

# Import required modules
import cv2
import numpy as np
import os
import glob
import keyboard
from PIL import Image


pressed = False
interval = 0
cap = cv2.VideoCapture(0)

while(True):
    ret, frame = cap.read()
    if(keyboard.is_pressed('p')):

    	img = Image.fromarray(frame)
    	np_img = np.array(img)
    	cv2.imwrite("Pictures/" + str(interval) +'.jpg', np_img)
    	interval += 1

    cv2.imshow("Image", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
