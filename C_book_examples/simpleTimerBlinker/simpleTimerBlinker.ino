#include <SimpleTimer.h>

SimpleTimer timer;  // the timer object construction
boolean currentLEDState;
int ledPin = 8;

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);

  currentLEDState = false;
  pinMode(ledPin, OUTPUT);
  timer.setInterval(1200, blink); 
}

void loop() {
  timer.run();
}

// a function to be executed periodically
void blink() {
  if (!currentLEDState) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  currentLEDState = !currentLEDState; // invert the boolean
}
