
import cv2
import numpy as np
import urllib.request
import imutils

import serial

	
	
	


def get_image_from_cellphone_camera(url, video_width):
	
	"""
	This function returns the feed from a cellphone camera as a numpy array.
	Launch the server on the "IP Webcam" android app before using this function.
	The laptop/Raspberry Pi and the cellphone need to be on the same wifi network.
		
	# Ref Tutorial by pantechsolutions: 
	# https://www.youtube.com/watch?v=lXeiicHhtNs
	
	# Android app: 
	# https://play.google.com/store/apps/details?id=com.pas.webcam&hl=en_ZA&gl=US
	
	
	Required package imports:
	--------------------------
	# import urllib.request
	# import cv2
	# import numpy as np
	# import imutils
	
	Package install instructions:
	-----------------------------
	OpenCV: $ sudo pip3 install opencv-python
	imutils: $ sudo pip3 install imutils
	urllib: Did not need to be installed.
	
	
	Arguments:
	----------
	
	url -- The url taken from the app. shot.jpg is added
	because we are taking continuous screen shots.
	Example:
	# url = 'http://192.168.0.102:8080/shot.jpg'
	
	video_width -- the required width of the output video image, integer
	Example: 
	If the specified width is 640 then the output image shape 
	will be: 480x640.
	
	Returns:
	--------
	
	image -- the image frame as a numpy array with shape: (h, video_width, 3)
	The height gets assigned automatically by the android app.
	The image looks to be in RGB format.
	
	"""
	
	# open the url
	image_path = urllib.request.urlopen(url)
	
	# get the image (cellphone screen shot) as a numpy array
	np_image = np.array(bytearray(image_path.read()), dtype=np.uint8)
	
	# decode the array to create an image
	image = cv2.imdecode(np_image, -1)
	
	# resize the image
	image = imutils.resize(image, width=video_width)
	
	return image
	
	
	

def set_up_serial_comms(my_port):
	
	"""
	This function sets up serial comms between a
	Python script and the Arduino.
	
	
	Required package imports:
	--------------------------
	# import serial
	
	Package install instructions:
	-----------------------------
	
	
	
	Arguments:
	----------
	
	my_port -- The port being used in the Arduino IDE.
	
	# To get the port name:
	# Make sure that the Arduino is connected to the laptop.
	# In the Arduino IDE select Tools and look at the port name.
	# You will see: /dev/cu.usbmodem14201 (Arduino Uno)
	# The port name is: dev/cu.usbmodem14201
	# Note that when you use a different USB connection on your computer,
	# the port name may also change and your code won't work.
	
	
	Returns:
	--------
	
	ser -- serial connection object

	"""
	

	# timeout=1 means that if there's an issue with the serial connection,
	# after 1 second it will timeout and it won't freeze up the entire script.
	ser = serial.Serial(my_port, 9600, timeout=1)
	
	# Flush the buffer of any additional information.
	ser.flush()
	
	
	# ser.name returns the name of the port that's
	# actually being used.
	# See: https://pythonhosted.org/pyserial/shortintro.html#opening-serial-ports
	# Here I'm using it as a way to check that serial communication
	# has been established.
	
	# if serial communication has been established
	if ser.name:
		
		# get the name of the port being used
		port = ser.name
		
		# print a status message
		print(f'Serial comms established on port: {port}')
	
	
	return ser
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	