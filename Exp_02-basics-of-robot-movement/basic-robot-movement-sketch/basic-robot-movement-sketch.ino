

// Motor A
#define enaPin 3
#define in1Pin 8 // If in1Pin is HIGH then Motor A moves forward.
#define in2Pin 9


// Motor B
#define enbPin 5
#define in3Pin 11 
#define in4Pin 12 // If in4Pin is HIGH then Motor B moves forward.



float duration, distance;



///////// Helper Functions ////////////

void move_forward() {

  // B|-------|A

  // To get the same speed on both motors
  // these are the PWM values:
  // Motor A: 128
  // Motor B: 190 

  // Motor B is ON.
  // Motor A is ON.

  // Full stop before changing motor direction
  analogWrite(enaPin, 0);
  analogWrite(enbPin, 0);

  // 1- Set the direction of rotation

  // Motor A - rotating forwards
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);

  // Motor B - rotating forwards
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
  

  // 2- Start the motors and set their speed
  
  analogWrite(enaPin, 128); // speed set to 0
  analogWrite(enbPin, 190);
  
}

void reverse() {

  // B|-------|A

  // To get the same speed on both motors
  // these are the PWM values:
  // Motor A: 128
  // Motor B: 190 

  // Motor B is ON.
  // Motor A is ON.

  // Full stop before changing motor direction
  analogWrite(enaPin, 0);
  analogWrite(enbPin, 0);

  // 1- Set the direction of rotation

  // Motor A - rotating backwards
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);

  // Motor B - rotating backwards
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  

  // 2- Start the motors and set their speed
  
  analogWrite(enaPin, 128); // speed set to 0
  analogWrite(enbPin, 190);
  
}

void turn_left() {

  // B|-------|A


  // Motor B is ON.
  // Motor A is OFF.
  // Therefore, the pivot point is Wheel A.

  // Full stop before changing motor direction
  analogWrite(enaPin, 0);
  analogWrite(enbPin, 0);

  // 1- Set the direction of rotation

  // Motor A - stopped
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);

  // Motor B - rotating backwards
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  

  // 2- Start the motors and set their speed
 
  analogWrite(enaPin, 0); // Motor A - speed set to 0
  analogWrite(enbPin, 128);
  
}


void turn_right() {

  // The delay needed for the robot to turn 360 degrees
  // is approx. 6000ms. This varies depending on the surface.

  // Motor A is OFF.
  // Motor B is ON.
  // Therefore, the pivot point is Wheel A.

  // Full stop before changing motor direction
  analogWrite(enaPin, 0);
  analogWrite(enbPin, 0);

  // 1- Set the direction of rotation

  // Motor A - stopped
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);

  // Motor B - rotating forwards
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
  

  // 2- Start the motors and set their speed
  
  analogWrite(enaPin, 0); // Motor A speed set to 0
  analogWrite(enbPin, 128);
  
}


void rotate_left() {

  // B|-------|A


  // Motor B is ON, moving backwards.
  // Motor A is ON, moving forwards.
  // The pivot point is half way between Wheel A and Wheel B.

  // Full stop before changing motor direction
  analogWrite(enaPin, 0);
  analogWrite(enbPin, 0);

  // 1- Set the direction of rotation

  // Motor A - rotating forwards
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);

  // Motor B - rotating backwards
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  

  // 2- Start the motors and set their speed
 
  analogWrite(enaPin, 128); 
  analogWrite(enbPin, 128);
  
}

//////////////// END ///////////////////




void setup() {
  
  // Motor A
  pinMode(enaPin, OUTPUT);
  pinMode(in1Pin, OUTPUT); 
  pinMode(in2Pin, OUTPUT);

  // Motor B
  pinMode(enbPin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  // When the robot is switched on rotate 360 degrees, counter-clockwise, once only.
  rotate_left();
  delay(2800);
  
}

void loop() {

  /*
  In each iteration we are specifying the sequence of actions
  we want to happen AND how long we want each action to take.
  If we don't specify how long we want the action to take then
  the robot won't perform that action.
  We specify "how long" by adding a delay after that action.
  */



  //rotate_left();
  //delay(2800);

  move_forward();
  delay(2000);

  reverse();
  delay(1000);

  rotate_left();
  delay(1400);

  move_forward();
  delay(1000);
  
}
