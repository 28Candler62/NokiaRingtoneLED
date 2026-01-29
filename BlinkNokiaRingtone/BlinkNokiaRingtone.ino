/*
NokiaRingtoneLED

Arduino blink LED according to Nokia ringtone pattern

https://en.wikipedia.org/wiki/Nokia_tune
pattern: 8th 8th qtr qtr | 8th 8th qtr qtr | 8th 8th qtr qtr | 3qtr

*/

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

const int QUARTER = 500;  // ms
const int EIGHTH  = 250;  // ms
const int THREE_QUARTER  = 750;  // ms
const int GAP     = 30;   // ms between notes
int notes [] = {EIGHTH, EIGHTH, QUARTER, QUARTER}; // single measure

void blink_note(int note) {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(note);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(GAP);                       // break between notes
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Repaeted measures
  for (int j=0; j<3; j++) {
    for (int i=0; i<sizeof notes/sizeof notes[0]; i++) {
    blink_note(notes[i]);
    }
  }

  // Final measure
  blink_note(THREE_QUARTER);

  // delay between iterations
  delay(2000); 
  
}
