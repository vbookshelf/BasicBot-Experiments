
// The two jumpers on the LM298 H-Bridge have been removed.
// The speed of each motor can now be varied using PWM.

// Note:
// 1- Disconnect the 5V supply from the H-Bridge to the Arduino before upoading a sketch.
// 2- The robot drifts to one side because the speed of the wheels are different. Here we will
// adjust the motor speeds to make the bot move straight.

// Motor 2
#define enaPin 3 // PWM pin
#define in1Pin 8
#define in2Pin 9


// Motor 1
#define enbPin 5 // PWM pin
#define in3Pin 11
#define in4Pin 12


void setup() {

  pinMode(enaPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  pinMode(enbPin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  

}

void loop() {

  // Move forward

  // Adjust the speed of motor 2
  analogWrite(enaPin, 190); // the range is 0-255
  
  // Set the direction of rotation - motor 2
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);

  // Adjust the speed of motor 1
  analogWrite(enbPin, 255); // the range is 0-255

  // Set the direction of rotation - motor 1
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
  delay(2000);

}
