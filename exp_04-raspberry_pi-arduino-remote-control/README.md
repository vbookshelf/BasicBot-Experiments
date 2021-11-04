## Exp_04 - Remote Control Using Raspberry Pi and Arduino

In progress...

<br>

<br>
<img src="https://github.com/vbookshelf/Serenity-Robotics-Experiments/blob/main/images/remote-control.jpg" width="400"></img>
<br>

### Objectives

1- Remotely control the robot's movement over wifi - by pressing the arrow keys on a computer keyboard.<br>
2- Learn how to use a Raspberry Pi together with an Arduino.


### Summary
The Raspberry Pi runs the Python code and acts as the compute module. The Arduino runs a sketch and acts as the control module for the motors and the distance sensor. The first step is to connect to the Raspberry Pi from a computer, using the VNC virtual desktop. Both the computer and Raspberry Pi need to be on the same wifi network. Using the remote desktop, launch the Python code. Then press the arrow keys on the computer keyboard to move the robot. If the disatnce sensor detects an obstacle less than or equal to 20cm away, the robot will automatically stop moving forward.


### Lessons Learned

- In terms of workflow, it's more efficient to do all coding and functional testing on a computer and then transfer the code to the Raspberry Pi.<br>
- For the key-presses to be sent from the Raspberry Pi (or from the computer when testing) to the Arduino, the Pygame window must always have focus (i.e. it must be selected). If the robot is not working the most probable cause is that the Pygame window has lost focus.<br>
- When using Pygame, the robot can't be controlled via SSH.<br>
- Power to the Raspberry Pi must always be connected last. Try not to plug in cables when the raspberry Pi is ON.<br>
- The Arduino IDE needs to be opened on the Raspberry Pi in order to check what port to use for the serial communication. Some tutorials say to use port "/dev/ttyAMA0" but that did not work fro me. The port that worked was "/dev/ttyUSB0". Sometimes I found that the Arduino changed this name to "/dev/ttyUSB1".<br>
- Make sure the the Arduino serial monitor is closed or the serial communication between the Python code and the Arduino won't work.<br>
- In previous experiments the power for the Arduino was supplied from the 5V supply on the L298N motor driver to the 5V pin on the Arduino. However, when the Arduino is connected to a computer (or a Raspberry Pi) when updating a sketch there is a risk that the current can flow from the Arduino to the motors. This hight current draw could damage the Arduino (and the Raspberry Pi). To prevent this, in this experiment I've not made any connection to the 5V pin on the Arduino. Instead the Arduino is powered via the USB cable from the Raspberry Pi. The Raspberry Pi is powered by a rechargeable powerbank rated at 5V, 2.4A (2.5A is recommmended).



<br>

## Reference Resources

- ExplainingComputers<br>
Raspberry Pi Devastator Robot<br>
https://www.explainingcomputers.com/pi_devastator_videos.html

- ExplainingComputers<br>
Raspberry Pi Zumo Robot<br>
https://www.explainingcomputers.com/rasp_pi_robotics.html

- Pi Spy<br>
Install Arduino IDE on Raspberry Pi<br>
https://www.youtube.com/watch?v=xWCwJXz4B4I

- vbookshelf Repo<br>
Raspberry Pi Resources for Beginners<br>
https://github.com/vbookshelf/Raspberry-Pi-Resources-for-Beginners

- vbookshelp Repo<br>
Arduino Computer Vision Finger Counter<br>
https://github.com/vbookshelf/Arduino-Computer-Vision-Finger-Counter


<br>
