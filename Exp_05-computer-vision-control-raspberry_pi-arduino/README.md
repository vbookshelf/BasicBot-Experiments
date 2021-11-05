## Exp_05 - Computer Vision with Raspberry Pi 3A+ and Arduino

In progress....

<br>

<br>
<img src="https://github.com/vbookshelf/Serenity-Robotics-Experiments/blob/main/images/cellphone-cam-pic.jpg" width="500"></img>
<br>

### Objectives
- Learn how to run computer vision models on a Raspberry Pi 3 A+.
- Learn how to connect a cellphone camera to a Raspberry Pi over wifi.
- Use hand signals to move the robot. When three fingers are help up to the camera the robot should move forward. When four fingers are help up the robot should reverse. When a fist is help up the robot should stand still.


### Summary

The first challenge was to get all the required computer vision packages installed on the Raspberry Pi. I've listed the steps that I followed in the attached pdf file.

Connecting the cellphone camera to the Raspberry Pi via Wifi was very easy when using the "IP Webcam" app. Once the connection was made the OpenCV Python code setup is the same as when one is using a computer webcam.

Mediapipe models can be run on a CPU. This fact allows us to use these models on the Raspberry Pi 3. In this experiment I've used the Mediapipe hand detection model for inference. The setup is not fast and robust but everything works. The user is able to make the robot move forard, move backward or stand still by using hand signals.


### Lessons Learned

- A fixed focus camera may be a better choice when a camera needs to be mounted on a moving robot. The auto focus camera was constantly re-focusing.
- Using the front camera on the phone was a very good way to be able to see what the Ai model is seeing - because the image is displayed on the screen facing the person who is giving hand signals to the robot. For example, if the image goes dark or the hand can't be differentiated from the background - the user will immediately know why the robot is not responding.
- There are two ways to install OpenCV on the Raspberry Pi. One takes hours and the other can be completed in a few minutes. I used the quick method.
- The Raspberry Pi is often slow when packages are being installed. Don't be in a rush to reboot it if you think that nothing is happening - be patient.
- Connect the Raspberry Pi to mains power before installing packages.
- If you don't display the ouput video (e.g. cv2.imshow(my_video, image)) then the inference code will run faster on the Raspberry Pi.



<br>

## Reference Resources

- Pi Spy<br>
Install Arduino IDE on Raspberry Pi<br>
https://www.raspberrypi-spy.co.uk/2020/12/install-arduino-ide-on-raspberry-pi/

- SPARKLERS : We Are The Makers<br>
Easiest way to install OpenCV for python in Raspberry pi within few minutes<br>
https://www.youtube.com/watch?v=xlmJsTeZL3w

- How to install Mediapipe on Raspberry Pi 3 and 4<br>
mediapipe-rpi4 0.8.8<br>
https://pypi.org/project/mediapipe-rpi4/

- Jeremy Morgan<br>
How to Install OpenCV on a Raspberry Pi<br>
https://www.jeremymorgan.com/tutorials/raspberry-pi/how-to-install-opencv-raspberry-pi/

- pantechsolutions<br>
Camera interface with RPi - USB | Mobile Camera<br>
(Explains how to connect a cellphone camera to a computer (or Raspberry Pi) via wifi.<br>
This is helpful if you don't have a USB webcam or a Raspberry Pi camera.)<br>
https://www.youtube.com/watch?v=lXeiicHhtNs

- vbookshelf Repo<br>
Raspberry Pi Resources for Beginners<br>
https://github.com/vbookshelf/Raspberry-Pi-Resources-for-Beginners

- vbookshelp Repo<br>
Arduino Computer Vision Finger Counter<br>
https://github.com/vbookshelf/Arduino-Computer-Vision-Finger-Counter



<br>
