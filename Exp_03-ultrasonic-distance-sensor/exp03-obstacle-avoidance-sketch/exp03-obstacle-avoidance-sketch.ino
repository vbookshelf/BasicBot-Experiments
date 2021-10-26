

// Motor A
#define enaPin 3
#define in1Pin 8
#define in2Pin 9


// Motor B
#define enbPin 5
#define in3Pin 11
#define in4Pin 12

// HC-SR04 Ultrasonic sensor
// Requires a 5V input.
#define echoPin 4
#define trigPin 2


float duration, distance;



///////// Helper Functions ////////////

float get_distance() {

  /*
   * This function returns the distance measured by
   * the ultrasonic sensor.
   * 
   * Output:
   *  distance in cm, type: float
   */

  float distance;

  // Start with everything off
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mesaure the response from the Echo Pin

  duration = pulseIn(echoPin, HIGH);

  // Use the duration to determine the distance
  // Use 343 m/s as the speed of sound
  // the signal from the trig pin goes out then returns, thats why we divide the duration by 2.
  distance = (duration / 2) * 0.0343;

  return distance;
  
}

void move_forward() {

  // B|-------|A

  // If both wheels are turning at the same speed then
  // the robot will move forward in a straight line.
  // To get almost the same speed on both motors
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


///////////// End of helper functions //////////////////




void setup() {

  // initialize the serial monitor
  Serial.begin(9600);
  
  pinMode(enaPin, OUTPUT);
  pinMode(in1Pin, OUTPUT); 
  pinMode(in2Pin, OUTPUT); 

  pinMode(enbPin, OUTPUT);
  pinMode(in3Pin, OUTPUT); 
  pinMode(in4Pin, OUTPUT); 
  
  // define the pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  
}

void loop() {


    // Ultrasonic sensor
   distance = get_distance(); 
  
  // Send the result to the serial monitor
  Serial.print("Distance = ");

   if (distance >= 400 || distance <= 2) {
    Serial.println("Out of range");
  }

  else {
    Serial.print(distance);
    Serial.println(" cm");
    //delay(500);
  }

  // A 100cm limit is better because this is a wide robot. If it
  // turns left too late the right front corner can still run into the wall.
  if (distance >= 100) {
    
    move_forward();
    
    // Including a delay means the sensor is not reading
    // a distance during the delay. The robot can run into something during the delay.
    //delay(1000);
  }

  else {
    
    rotate_left();

    // Including a delay means the sensor is not reading
    // a distance during the delay. The robot can run into something during the delay.
    //delay(500);
  }

  delay(10);

}
