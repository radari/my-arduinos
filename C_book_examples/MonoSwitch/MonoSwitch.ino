const int switchPin = 2;   // pin of the digital input related to the switch
const int ledPin = 8;      // pin of the digital output related to the LED

int switchState = 0;       // storage variable for current switch state


void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  pinMode(ledPin, OUTPUT);     // the led pin is setup as an output
  pinMode(switchPin, INPUT);   // the switch pin is setup as an input

  Serial.begin(9600);          // Serial commmunication setup at 9600 baud
}

void loop() {
  switchState = digitalRead(switchPin);    // read the state of the digital pin 2
  
  Serial.print("the switch state is ");
  Serial.println(switchState);
  
  if (switchState == HIGH) {     // test if the switch is pushed or not
    digitalWrite(ledPin, HIGH);  // turn the LED ON if it is currently pushed
  } else {
    digitalWrite(ledPin, LOW);   // turn the LED OFF if it is not currently pushed
  }    
}
