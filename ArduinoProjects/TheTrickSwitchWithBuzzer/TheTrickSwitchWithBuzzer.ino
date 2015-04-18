/* 
  Pushbutton Sketch

Reads the capacitor voltage at digital pin 12 and turns on and off a light-emitting diode (LED) connected to digital pin 8.
It sounds when LED is turned off
*/
#include "pitches.h"

// constants
const int buttonPin = 12;    // the number of the pushbutton pin
const int ledPin =8;         // the number of the LED pin
const int buzzerPin = 4;     // the number of the buzzer pin

// variables
int buttonStatus = 0;       // variable for reading the pushbutton status

bool readyForAction = false; 

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  // initialize the LED pins as an outputs
  pinMode(ledPin, OUTPUT);  

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
    
    if (readyForAction == false) {
      readyForAction = true;
    }
  } else {
    // turn LED off
    digitalWrite(ledPin, LOW);
    
    if (readyForAction == true) {
      tone(buzzerPin, NOTE_B3, 4);
      tone(buzzerPin, NOTE_D5, 8);
      tone(buzzerPin, NOTE_B3, 4);
      readyForAction = false;
    }

  }    
}

