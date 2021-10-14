## Exp01 - Move forward in a straight line

(Writeup in progress)

Use PWM (Pulse Width Modulation) to vary the speed of each wheel so that the robot moves forward in a fairly straight line instead of drifting left or right.



### Summary

A robot may drift to the right or left when moving forward. This can be caused by:<br>
1- The motors and gears are not identical and therefore turn at different speeds,<br>
2- The castor wheel<br>
3- Wheels are not identical,<br>
4- other factors

One way to fix this is to increase or reduce the speed of each motor separately. A motor's speed can be adjusted by increasing or reducing the voltage that it receives. PWM is a way to reduce the supply voltage without using a resistor. In this experiment I've used PWM in the Arduino sketch.

## Lessons Learned
1- Female jumper cables are unreliable. They need to be tightened.
2- This robot needs a strong power supply. 6V is not enough.

## Reference Resources

How to keep (female) jumper wires tight<br>
https://forum.pololu.com/t/how-to-keep-jumper-wires-tight/4565/2<br>

How to control DC motor with L298N driver and Arduino<br>
https://www.youtube.com/watch?v=dyZolgNOomk<br>



