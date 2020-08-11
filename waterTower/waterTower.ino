/***********************************************************
 * Controls for the water tower include:
 *  - Individual control for rgb LEDs
 *  - Hard-coded speed for the water pump
 * Different mode ideas:
 *  - Still
 *  - Up
 *  - Down
 *  - Party (One color up, one down, one still with possible varying speeds)
 * 
 **********************************************************/

#define RED   3
#define GREEN 5
#define BLUE  6
#define PUMP  9

// These will have to be changed after some testing is done to see
// how low of a duty cycle we can go before seeing the flash.
#define DOWN_FAST 25  // 10% duty cycle
#define DOWN      64  // 25% duty cycle
#define STILL     127 // 50% duty cycle
#define UP        191 // 75% duty cycle
#define UP_FAST   229 // 90% duty cycle

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(PUMP, OUTPUT);

  // the pump speed shouldn't be changed, so we can
  // start it here and leave it.
  analogWrite(PUMP, STILL);
}

void loop() {
    analogWrite(RED, STILL);
    analogWrite(GREEN, STILL);
    analogWrite(BLUE, STILL);
}
