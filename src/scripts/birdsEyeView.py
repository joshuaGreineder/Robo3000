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


#frame = cv2.imread("1497904268_6094430436_12df6205fb_b.jpg")
cap = cv2.VideoCapture(0)
times = 0
while(True):
    _, frame = cap.read()

    height, width, _ = frame.shape

    IMAGE_H = height
    IMAGE_W = width
    line_color = (0, 255, 0)
    line_width = 20

    src = np.float32([[0, IMAGE_H], [754, IMAGE_H], [0, 0], [IMAGE_W, 0]])
    dst = np.float32([[225, 0], [418, 0], [-105, IMAGE_H], [768, IMAGE_H]])

    M = cv2.getPerspectiveTransform(src, dst)  # The transformation matrix
    Minv = cv2.getPerspectiveTransform(dst, src)  # Inverse transformation
    cv2.line(frame, (146, 152), (440, 152), line_color, 4)
    cv2.line(frame, (440, 152), (839, 458), line_color, 4)
    cv2.line(frame, (-273, 458), (839, 458), line_color, 4)
    cv2.line(frame, (-273, 458), (146, 152), line_color, 4)

    # Apply np slicing for ROI crop
    # Apply np slicing for ROI crop
    img = frame[154:(188 + IMAGE_H), 0:IMAGE_W]
    warped_img = cv2.warpPerspective(
        img, M, (IMAGE_W, IMAGE_H))  # Image warping
    warped_img = cv2.flip(warped_img, 0)
    print("Times run: ")
    print(times)
    
    times += 1
    # plt.imshow(cv2.cvtColor(warped_img, cv2.COLOR_BGR2RGB))  # Show results
    cv2.imshow("Warped", warped_img)
    cv2.imshow("Frame", frame)
    # plt.show()

    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
