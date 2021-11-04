
# Ref tutorial:
# ExplainingComputers
# Episode 4: https://www.explainingcomputers.com/pi_devastator_videos.html

# Pygame is used to create games.
# Here we are using it to detect when a user presses or
# releases a key.

import pygame
import serial




# .......................................
# Set up serial comms between this 
# python script and the Arduino.


# To get the port name to enter below:
# Make sure that the Arduino is connected to the laptop.
# In the Arduino IDE select Tools and look at the port name.
# You will see: /dev/cu.usbmodem14201 (Arduino Uno)
# The port name is: dev/cu.usbmodem14201
# Note that when you use a different USB connection on your computer,
# the port name may also change and your code won't work.

# timeout=1 means that if there's an issue with the serial connection,
# after 1 second it will timeout and it won't freeze up the entire script.

##################################

# Change this to your port

# Port that was used when running the code on a local computer.
# The Arduino must be connected.
#my_port = "/dev/cu.usbserial-1420"

# Port that was used when running the code on the Raspberry Pi.
# The Arduino must be connected.
# The code did not work when using port "/dev/ttyAMA0"
my_port = "/dev/ttyUSB0"

##################################


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


	
# .......................................





# We must open a Pygame window to allow it to detect user events.
# In Pygame, user interactions are called events.
# Pygame can only detect an event if a Pygame window is
# open and it has the focus (i.e. it is selected).
# We can specify any window size. Here we have specified 240x160 (height, width).
screen = pygame.display.set_mode([240, 160])

while True:
	
    
    # loop through a list containing the events
	for event in pygame.event.get():
        
		# if the user presses a key down
		if event.type == pygame.KEYDOWN:
			
			if event.key == pygame.K_RIGHT:
				print('Right')
				# Send a communication to the Arduino.
				# Note that we add a newline character because
				# the Arduino code reads up to a newline character.
				ser.write(b"right\n")
			
			if event.key == pygame.K_LEFT:
				print('Left')
				# Send a communication to the Arduino.
				# Note that we add a newline character because
				# the Arduino code reads up to a newline character.
				ser.write(b"left\n")
			
			if event.key == pygame.K_UP:
				print('Up')
				# Send a communication to the Arduino.
				# Note that we add a newline character because
				# the Arduino code reads up to a newline character.
				ser.write(b"up\n")
			
			if event.key == pygame.K_DOWN:
				print('Down')
				# Send a communication to the Arduino.
				# Note that we add a newline character because
				# the Arduino code reads up to a newline character.
				ser.write(b"down\n")
			
			# quit pygame if q is pressed
			if event.key == pygame.K_q:
				print('Goodbye')
				pygame.quit()
    
		# if the user releases a key (after pressing it)
		elif event.type == pygame.KEYUP:
			print('Key-up detected')
			# Send a communication to the Arduino.
			# Note that we add a newline character because
			# the Arduino code reads up to a newline character.
			ser.write(b"key-up\n")
			
			