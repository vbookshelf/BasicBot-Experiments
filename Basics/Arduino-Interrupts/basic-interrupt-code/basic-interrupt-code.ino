
/*
 * This sketch shows how to use an interrupt.
 * 
 * Ref Tutorials:

  Level Up Your Arduino Code: External Interrupts
  Sparkfun
  https://www.youtube.com/watch?v=J61_PKyWjxU
  
  Arduino Robot Car with Speed Sensors - Using Arduino Interrupts
  Dronebotworkshop
  https://www.youtube.com/watch?v=oQQpAACa3ac
  
  attachInterrupt()
  Arduino docs
  https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/

 */

int led_state = LOW;
int state;
int btn_pin = 2; // pins 2 and 3 on the Arduino Uno support interrupts.
int led_pin = 7;

void setup() {

  Serial.begin(9600);

  // Declare pin 2 as a PULLUP resistor.
  // This means that it has a 5V supply i.e. it is HIGH.
  // To make it LOW we must connect it to ground by pressing the switch.
  pinMode(btn_pin, INPUT_PULLUP);

  pinMode(led_pin, OUTPUT);

  // Trigger the interrupt when btn_pin falls from HIGH to LOW.
  attachInterrupt(digitalPinToInterrupt(btn_pin), toggle_led, FALLING); // toggle_led is a function

  // FALLING - for when the pin goes from high to low
  // LOW - to trigger the interrupt whenever the pin is low
  // CHANGE - to trigger the interrupt whenever the pin changes value
  // RISING - to trigger when the pin goes from low to high

}

void loop() {

  // Don't name this variable led_state as it will cause errors in the interrupt execution.
  state = digitalRead(btn_pin);
  Serial.println(state);

  // The interrupt will trigger even when he code is running this delay.
  delay(5000);
  
}


// This is the interrupt function thats gets executed when
// the interrupt is triggered.
void toggle_led() {
  
  // Change the state to it's opposite condition.
  // Debouncing may be a problem. You may press the button once but
  // the button may register more than one press.
  led_state = !led_state;

  // Turn the led on if it's off or turn the led off if it's on.
  digitalWrite(led_pin, led_state);
}
