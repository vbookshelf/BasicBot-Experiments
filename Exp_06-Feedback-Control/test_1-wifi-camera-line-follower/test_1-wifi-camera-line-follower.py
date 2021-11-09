
import cv2
import mediapipe as mp
import numpy as np
import time
from time import sleep
import serial

# import the functions we will be using
from my_cv_utils_rev0 import *

# ........................................
# Set up serial communication between the
# Python code and the Arduino.

# Computer:
my_port = "/dev/cu.usbserial-1420"
# Raspberry Pi:
#my_port = "/dev/ttyUSB0"

ser = set_up_serial_comms(my_port)

# ........................................


# ........................................
# Set up the image feed


# [1] Video file:
#cap = cv2.VideoCapture('videos/hands.mp4')

# [2] Laptop Webcam:
# Using webcam number 0.
#cap = cv2.VideoCapture(0)
#video_width = 640
video_height = 480
#cap.set(3, video_width) # 3 is the id for width
#cap.set(4, video_height) # 4 is the id for height

# [3] Wifi cellphone camera via Android app:
# This is the IP address given in the Android app.
url = 'http://192.168.0.104:8080/shot.jpg'
video_width = 640

# ........................................



# Define the colours
WHITE_COLOR = (224, 224, 224)
BLACK_COLOR = (0, 0, 0)
RED_COLOR = (0, 0, 255)
GREEN_COLOR = (0, 128, 0)
BLUE_COLOR = (255, 0, 0)




# to draw the landmarks
mp_draw = mp.solutions.drawing_utils

# Set the drawing specs.
# the defaults also look fine.
draw_specs = mp_draw.DrawingSpec(color=WHITE_COLOR, thickness=2, circle_radius=2)

mp_pose = mp.solutions.hands
pose = mp_pose.Hands(static_image_mode=False,
               max_num_hands=1,
               min_detection_confidence=0.85,
               min_tracking_confidence=0.5)



# A video is just a sequence of images.
# Create a loop to loop through each image.

start_time = 0
x_center = video_width/2
line_thickness = 100 # in pixels
x_left = x_center - (line_thickness/2)
x_right = x_center + (line_thickness/2)

status = "centered"

while True:

	# Get one frame.
	# 'success' is a boolean that indicates if the image was read.
	# 'image' is the image frame that was read.
	#success, image = cap.read()
	
	# Get the image frame from the cellphone camera
	image = get_image_from_cellphone_camera(url, video_width)
	
	# flip the image so that it's like looking in a mirror.
	image = cv2.flip(image, 1)
	
	# draw the lines
	image = cv2.line(image, (int(x_center), 0), (int(x_center), video_height), WHITE_COLOR, 1)
	image = cv2.line(image, (int(x_left), 0), (int(x_left), video_height), WHITE_COLOR, 1)
	image = cv2.line(image, (int(x_right), 0), (int(x_right), video_height), WHITE_COLOR, 1)
	


	# Convert the image from BGR to RGB.
	# Note that we don't display this RGB image. We display
	# the original BGR image.
	image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

	# process the image and store the results in an object
	results = pose.process(image_rgb)

	
	# draw a rectangle on the screen
	cv2.rectangle(image, (25, 130), (100, 200), BLUE_COLOR, cv2.FILLED)
	
	


	# This is how to create a black background and
	# a white background.
	h, w, c = image.shape
	black_image = np.zeros((h, w, c))
	white_image = np.zeros((h, w, c)) + 255

	# Choose to display the original image or show the hand landmarks
	# against a black or a white background.
	display_image = image
	#display_image = black_image
	# display_image = white_image



	#print(results.multi_hand_landmarks)



	if results.multi_hand_landmarks:

		# We can have multiple hands.
		# Therefore, we need to loop through the hands
		for hand_landmarks in results.multi_hand_landmarks:
			
			x_list = []
			y_list = []

			# draw the lanmarks on the image as dots only
			#mp_draw.draw_landmarks(display_image, hand_landmarks)


			# draw dots and the connections between them
			mp_draw.draw_landmarks(display_image, hand_landmarks, mp_pose.HAND_CONNECTIONS,
								draw_specs, draw_specs)


			# Get each separate point.
			# We can put the ids into a list and return them.
			for id, lm in enumerate(hand_landmarks.landmark):

				# These values have been normalized from 0 to 1.
				# We need to convert them to coordinates.
				#print(lm)

				# convert to coordinates
				h, w, c = image.shape
				x = int(lm.x * w)
				y = int(lm.y * h)

				#print(id, x, y)
				
				# add the x and y coords to a list
				x_list.append(x)
				y_list.append(y)
				
					

			#print(y_list)
			
			# This is how we check if a finger or the thumb is
			# up or down.
			# ......................................
			
			# By following this link you will find a diagram that shows which index values
			# correspond to which points on a hand:
			# https://google.github.io/mediapipe/solutions/hands#resources
			
			# This are the landmark that we will be using:
			
			# 0 - wrist

			
			
			# This if statement checks that the keypoints we need
			# have been detected.	
			if len(x_list) != 0:
				
				# If the left or right wrist landmark is more than 10% (slack_amt) to the
				# right of the x center-line...
				if (x_list[0] > x_right):
					
					status = 'too_far_right' # robot needs to turn left
					print(status)
				
				# If the left or right wrist landmark is more than 10% (slack_amt) to the
				# left of the x center-line...
				elif (x_list[0] < x_left):
					
					status = 'too_far_left' # robot needs to turn right
					print(status)
					
				elif ((x_list[0] > x_left) and (x_list[0] < x_right)):
					
					status = 'centered' 
					print('centered')
					
					
			
			
			
			# Example:	
			# This how to read a message sent by the Arduino.
			# Decode the message and strip out leading or trailing whitespace.
			# This message could be used to control what happens below.
			# If an integer or float was sent as a string, it can be converted
			# back to a number as follows: float(arduino_message)
			
			# arduino_message = ser.readline().decode('utf-8').rstrip()
			
	
			
			# ser.name returns the name of the port that's
			# actually being used.
			# Here I'm using it as a way to check that serial communication
			# has been established.
			if ser.name:
			
				if status == 'too_far_right':
				
					# --> Send a communication to the Arduino.
					# Note that we add a newline character because
					# the Arduino code reads up to a newline character.
					ser.write(b"too_far_right\n")
					
				
				if status == 'too_far_left':
				
					# --> Send a communication to the Arduino.
					ser.write(b"too_far_left\n")
					
					
				
			
			
			# write the number of fingers onto the webccam image
			cv2.putText(image, str(status), (50, 180), cv2.FONT_HERSHEY_PLAIN, 3,
			WHITE_COLOR, 3)


	# Get the frame rate
	current_time = time.time()
	fps = 1/(current_time - start_time)
	start_time = current_time
	
	print(fps)

	# Uncomment this line to display the frame rate on the image (top left corner)
	cv2.putText(display_image, str(int(fps)), (70, 50), cv2.FONT_HERSHEY_PLAIN, 3,(255,255,255), 3)


	# Display the webcam video frame
	cv2.imshow('Video', display_image)



	# Press q on the keyboard to close the video
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break
		
		
	# This delay specifies how often we will take sensor readings - that
	# we will then use to adjust the robot.
	# This delay is important. It prevents the robot from behaving erractically.
	sleep(0.2)
		