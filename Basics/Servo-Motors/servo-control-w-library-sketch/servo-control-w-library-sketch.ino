

// With this library we can drive up to 12 servos at the same time.


// Include the servo library
#include <Servo.h>

// Create a servo object
Servo myServo;

int angle;

void setup() {

  // min = pulse duration at 0 degrees
  // max = pulse duration at 180 degrees
  // Find the above values by experimentation.
  myServo.attach(8, 600, 2500); // (pin, min, max)

}

void loop() {

  // Here we are moving the servo to three different angles
  // with a 1 second delay between each move.

  angle = 0; // angle in degrees
  myServo.write(angle);
  delay(1000);

  angle = 45; // angle in degrees
  myServo.write(angle);
  delay(1000);

  angle = 90; // angle in degrees
  myServo.write(angle);
  delay(1000);

  angle = 180; // angle in degrees
  myServo.write(angle);
  delay(1000);

}
