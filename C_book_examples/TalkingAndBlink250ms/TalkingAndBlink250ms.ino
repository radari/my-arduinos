/* 
    TalkingAndBlink250ms Program
    Turns a LED connected to digital pin 8 on for 250ms, then off for 1s, infinitely.
    In both steps, the Arduino Board send data to the console of the IDE for information purpose.
*/
  
byte ledPin = 8;

void setup() {
    pinMode(13, OUTPUT);

    pinMode(ledPin, OUTPUT);        // initialize the digital pin as an output
    Serial.begin(9600);             // Serial commmunication setup at 9600 baud
}

void loop() {
    digitalWrite(ledPin, HIGH);     // turn the LED ONon

    Serial.print("the pin ");
    Serial.print(ledPin);
    Serial.println(" is on");

    delay(250);                     // wait for 250ms

    digitalWrite(ledPin, LOW);      // turn the LED off

    Serial.print("the pin ");
    Serial.print(ledPin);
    Serial.println(" is off");

    delay(1000);                    // wait for 1s
}
