## Exp01 - Move forward in a straight line

<br>

### Objective

Use PWM (Pulse Width Modulation) to vary the speed of each wheel so that the robot moves forward in a fairly straight line instead of drifting left or right


### Summary

The robot drifted to the left when moving forward. This could have been caused by:<br>

1- The motors and gears are not identical and therefore turn at different speeds,<br>
2- The castor wheel<br>
3- Wheels that are not identical,<br>
4- other factors

One way to fix this is to increase or reduce the speed of each wheel separately. A motor's speed can be adjusted by increasing or reducing the voltage that it receives. PWM is a way to reduce the supply voltage without using a resistor. In this experiment I've used PWM in the Arduino sketch.

### Lessons Learned

1- Female jumper cables are unreliable. The connection is often loose which means that sometimes the circuit works and sometimes it doesn't. I've found that the same thing happens with the female connections on hobby servo motors. The solution is to remove the black casing and tighten the connection as show in this article:<br>
https://forum.pololu.com/t/how-to-keep-jumper-wires-tight/4565/2<br>
Note that this tightening may need to be repeated each time a male connector is inserted and removed.<br>

2- This robot needs a strong power supply. If the supply is too weak the LEDs may be on but the motors will not be turning. I found that a 6V supply is not enough. I used 10.8V.<br>

<br>

## Reference Resources

How to keep (female) jumper wires tight<br>
https://forum.pololu.com/t/how-to-keep-jumper-wires-tight/4565/2<br>

How to control DC motor with L298N driver and Arduino<br>
https://www.youtube.com/watch?v=dyZolgNOomk<br>



