## Exp_03 - Ultrasonic Distance Sensor

(In Progress...)

<br>

<br>
<img src="https://github.com/vbookshelf/Serenity-Robotics-Experiments/blob/main/images/distance-sensor-pic.jpg" width="400"></img>
<br>

### Objective

Learn how to use the HC-SR04 Ultrasonic Sensor for collision avoidance.

### Examples

- This Arduino sketch demonstrates basic obstacle avoidance. The robot moves forward. When it detects an obstacle it keeps turning left until no obstacle is detected. Then it moves forward.<br>
https://github.com/vbookshelf/Serenity-Robotics-Experiments/tree/main/Exp_03-ultrasonic-distance-sensor/exp03-obstacle-avoidance-sketch

- This Arduino sketch shows how to use your hand to push the robot back and pull it forward without touching it.<br>
https://github.com/vbookshelf/Serenity-Robotics-Experiments/blob/main/Exp_03-ultrasonic-distance-sensor/exp03-no-touch-push-pull-sketch/exp03-no-touch-push-pull-sketch.ino

<br>
<img src="https://github.com/vbookshelf/Serenity-Robotics-Experiments/blob/main/images/exp03.gif" width="400"></img>
<br>



### Lessons Learned
- If the robot approaches a wall at a shallow angle (less than 45 degrees), the sound will not be reflected back to the sensor. Because of this the robot will collide with the wall.

- This sensor has many other applications. For example, it could be used as part of a touchless hand sanitizer dispenser. When the sensor detects the hand close to the bottle, a servo motor arm presses on the bottle to release the sanitizing fluid. 



<br>

## Reference Resources

Using the HC-SR04 Ultrasonic Distance Sensor with Arduino - Everything you need to know!<br>
https://www.youtube.com/watch?v=6F1B_N6LuKw<br>

How HC-SR04 Ultrasonic Sensor Works & Interface It With Arduino<br>
https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/


<br>
