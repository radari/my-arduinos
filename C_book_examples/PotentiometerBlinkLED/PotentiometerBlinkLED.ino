int potPin = 0;           // pin number where the potentiometer is connected
const int ledPin = 8;     // pin of the digital output related to the LED
int potValue = 0;         // variable storing the voltage value measured at potPin pin

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  pinMode(ledPin, OUTPUT);    // define ledPin pin as an output
}

void loop() {
  potValue = analogRead(potPin);    // read and store the read value at potPin pin
  
  digitalWrite(ledPin, HIGH);       // turn on the LED
  delay(potValue);                  // pause the program during potValue millisecond
  digitalWrite(ledPin, LOW);        // turn off the LED
  delay(potValue);                  // pause the program during potValue millisecond
}
