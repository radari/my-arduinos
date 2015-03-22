/* 
  Blink250ms Program
  Turns a LED connected to digital pin 8 on for 250ms, then off for 1s, infinitely.
  */
  
int ledPin = 8;

void setup() {
  pinMode(13, OUTPUT);
  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
