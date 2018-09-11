# -*- coding: utf-8 -*-

from picamera import PiCamera
from picamera.array import PiRGBArray
import time
import cv2
import serial
import numpy as np

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=0)

def Mask(input):
    lower_red = np.array([0, 150, 150])
    higher_red = np.array([179, 255, 255])
    kernel = np.uint8(np.ones((3, 3)))
    output_i = cv2.inRange(input, lower_red, higher_red)
    output_e = cv2.erode(output_i, kernel)
    output_d = cv2.dilate(output_e, kernel)

    return output_d

def core(input):
    image, contours, hierarchy = cv2.findContours(input, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
    if len(contours) <= 0:
        point = [0, 0]
        size = [0, 0]
        return point, size
    else:
        cnt = contours[0]
        
    for i in range(len(contours)):
        if len(contours[i]) >= len(cnt):
            cnt = contours[i]
            
    if len(cnt) <= 6:
        point = [0, 0]
        size = [0, 0]
        return point, size
    
    ellipse = cv2.fitEllipse(cnt)
    point = ellipse[0]
    size = ellipse[1]

    return point, size

def light_center(image):
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    gray = Mask(hsv)
    center, size = core(gray)

    return center, size

camera = PiCamera()
camera.resolution = (720, 480)
camera.shutter_speed = 3000
camera.iso = 200
camera.framerate = 30

stop = 0
back = 1
slow = 0

rawCapture = PiRGBArray(camera, size=(720, 480))

for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
    image = frame.array
    center, size= light_center(image)
    center_l = int(center[0]) - 360
    center_r = 360 - int(center[0])
    rawCapture.truncate(0)
    
    if (size[1] == 0 and center[0] == 0 and back == 0):
            ser.write('b'.encode('utf-8'))
            #print("over.back,%d,%d" % (center[0], size[1]))
            time.sleep(1.5)
            ser.write('w'.encode('utf-8'))
            time.sleep(0.2)
            back = 1
            slow = 0
    elif (size[1] >= 60 and stop == 0):
        ser.write('s'.encode('utf-8'))
        time.sleep(1)
        ser.write('m'.encode('utf-8'))
        #print("found.stop,%d,%d" % (center[0], size[1]))
        stop = 1
        slow = 1
    elif (size[1] >= 50 and stop == 1 and slow == 1):
        if (center_r >=150 and center_l <= 0):
            ser.write('q'.encode('utf-8'))
            #print("s.left,%d,%d" % (center[0], size[1]))
            back = 0
            slow = 1
        elif (center_l >= 150 and center_r <= 0):
            ser.write('e'.encode('utf-8'))
            #print("s.left,%d,%d" % (center[0], size[1]))
            back = 0
            slow = 1
        else:
            ser.write('m'.encode('utf-8'))
            #print("s.forward,%d,%d" % (center[0], size[1]))
            back = 0
            slow = 1
    elif (slow == 0):
        if (center[0] == 0 and size[1] == 0):
            ser.write('R'.encode('utf-8'))
            #print("RIGHT,%d,%d" % (center[0], size[1]))
            stop = 0
        elif (center_r >=50 and center_l <= 0):
            ser.write('l'.encode('utf-8'))
            #print("left,%d,%d" % (center[0], size[1]))
            stop = 0
        elif (center_l >= 50 and center_r <= 0):
            ser.write('r'.encode('utf-8'))
            #print("right,%d,%d" % (center[0], size[1]))
            stop = 0
        else:
            ser.write('f'.encode('utf-8'))
            #print("forward,%d,%d" % (center[0], size[1]))
            stop = 0
    else:
        #print("others")
        #print(stop, back, slow)
        slow = 0
        
ser.write('s'.encode('utf-8'))
