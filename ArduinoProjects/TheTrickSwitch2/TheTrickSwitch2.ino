/* 
  Pushbutton Sketch

Reads the capacitor voltage at digital pin 2 and turns on and off a light-emitting diode (LED) connected to digital pin 12.
*/

// constants
const int buttonPin = 12;    // the number of the pushbutton pin
const int ledPin =8;         // the number of the LED pin
const int ledControlPin = 4; // the number of the control LED pin

// variables
int buttonStatus = 0;       // variable for reading the pushbutton status

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  // initialize the LED pins as an outputs
  pinMode(ledPin, OUTPUT);  
  pinMode(ledControlPin, OUTPUT); 
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the status of the pushbutton value
  buttonStatus = digitalRead(buttonPin);
  
  // check if the pushbutton is pressed
  // if it is, the buttonStatus is HIGH
  if (buttonStatus == HIGH) {
    // turn LED on
    digitalWrite(ledPin, HIGH);
    // turn off the control LED
    digitalWrite(ledControlPin, LOW);
  } else {
    // turn LED off
    digitalWrite(ledPin, LOW);
    // turn on the control LED
    digitalWrite(ledControlPin, HIGH);
  }    
}

