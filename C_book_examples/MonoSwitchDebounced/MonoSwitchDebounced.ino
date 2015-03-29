const int switchPin = 2;   // pin of the digital input related to the switch
const int ledPin = 8;      // pin of the digital output related to the LED

int switchState = 0;       // storage variable for current switch state

int lastSwitchState= LOW;

// variables related to the debouncing system
long lastDebounceTime = 0;
long debounceDelay = 50;

boolean debug = true; 

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  pinMode(ledPin, OUTPUT);     // the led pin is setup as an output
  pinMode(switchPin, INPUT);   // the switch pin is setup as an input

  Serial.begin(9600);          // Serial commmunication setup at 9600 baud
}

void loop() {
  
  // read the state of the digital pin
  int readInput = digitalRead(switchPin);
  
  // if freshly read state is different than the last debounced value
  if (readInput != lastSwitchState){
    // reset the debounce counter by storing the current uptime ms
    lastDebounceTime = millis();
    if (debug) {
      Serial.print("lastDebounceTime :");
      Serial.println(lastDebounceTime);
    }
  }
  
  // if the time since the last debounce is greater than the debounce delay
  if ( (millis() - lastDebounceTime) > debounceDelay ) {
    // store the value because it is a debounced one and we are safe
    switchState = readInput;
  }

  // store the last read state for the next loop comparison purpose
  lastSwitchState = readInput;
  
  if (debug) {
      Serial.print("readInput : ");
      Serial.print(readInput);
      Serial.print(" switchState : ");
      Serial.print(switchState);
      Serial.print(" lastSwitchState : ");
      Serial.println(lastSwitchState);
  }
  // modify the LED state according to the switch state
  if (switchState == HIGH) {        // test if the switch is pushed or not
    digitalWrite(ledPin, HIGH);     // turn the LED ON if it is currently pushed
    Serial.println("Turning the LED ON");
  } else {
    digitalWrite(ledPin, LOW);      // turn the LED OFF if it is not currently pushed
    Serial.println("Turning the LED OFF");
  }
  
}
