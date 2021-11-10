
#define servoSignalPin 9

int timeDelay = 1900;
int pulseDelay;

void setup() {

  pinMode(servoSignalPin, OUTPUT);
  
}

void loop() {

  // A servo needs 50 pulses every second i.e. it has a frequency of 50Hz (It needs one pulse every 20ms.)
  // Create a 20ms pulse (time_voltage_is_off + time_voltage_is_on = 20ms)

  // Create a pulse width of 1.45ms.
  // This pulse width determines the angle of the servo.
  digitalWrite(servoSignalPin, HIGH); // Turn the voltage ON
  delayMicroseconds(timeDelay); // Keep the voltage ON for 1.450 ms. 1450 is the value in micro seconds.

  pulseDelay = 20000 - timeDelay;
  digitalWrite(servoSignalPin, LOW); // Turn the voltage OFF
  delayMicroseconds(pulseDelay); // Keep the voltage OFF for 18.550 ms (20ms - 1.450ms = 18.550ms)

}
