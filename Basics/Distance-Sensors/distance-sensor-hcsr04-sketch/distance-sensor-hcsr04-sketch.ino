


// HC-SR04 Ultrasonic sensor
// Requires a 5V input.
#define echoPin 4
#define trigPin 2


float distance;
int sample_time = 100; // Take a reading every 100 milliseconds.


///////// Helper Functions ////////////

float get_distance() {

  /*
   * This function returns the distance measured by
   * the ultrasonic sensor.
   * 
   * Output:
   *  distance in cm, type: float
   */

  float duration, distance;

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


///////////// End of helper functions ////////////////




void setup() {

  Serial.begin(9600);

  // define the pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}


void loop() {

    distance = get_distance();
    Serial.print("Distance: ");
    Serial.println(distance);

    delay(sample_time);
    
}
