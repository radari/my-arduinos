const int switchPin = 2;   // pin of the digital input related to the switch
int switchState = 0;       // storage variable for current switch state
int inByte = 0;

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
  pinMode(switchPin, INPUT);   // the switch pin is setup as an input
  sayHello();
}

void loop() {
  
  // if a valid byte is received from processing, read the digital in.
  if (Serial.available() > 0) {
    // get incoming byte
    inByte = Serial.read();
    switchState = digitalRead(switchPin);
    
    // send switch state to Arduino
    Serial.write("0");
    Serial.write(switchState);
  }
}

void sayHello() {
  while (Serial.available() <= 0) {
    Serial.print('Z');    // send a capital Z to Arduino to say "HELLO!"
    delay(200);
  }
}

