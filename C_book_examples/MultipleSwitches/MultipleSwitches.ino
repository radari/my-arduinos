
#define switchesNumber 3               // define the number of switches as a constant

int switchesStates[switchesNumber];    // array storing current switches states
int inByte = 0;

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  Serial.begin(57600);
  
  // initiating each pins as input and filling switchesStates with zeroes
  for(int i = 0; i < switchesNumber; i++) {
    pinMode(i + 2, INPUT);   // the switch pin is setup as an input
    switchesStates[i] = 0;
  }
  
  sayHello(); // waiting for the processing program hello answer
}

void loop() {
  
  // if a valid byte is received from processing, read the digital in.
  if (Serial.available() > 0) {
    
    // get incoming byte
    inByte = Serial.read();
    
    for(int i = 0; i < switchesNumber; i++) {
      switchesStates[i] = digitalRead(i+2); // We are starting from pin 2
      Serial.write(i);                      // 1st byte = switch number (0 to 2)
      Serial.write(switchesStates[i]);      // 2nd byte = the switch i state
      delay(1000);
    }
  
  }

}

void sayHello() {
  while (Serial.available() <= 0) {
    Serial.print('Z');    // send a capital Z to Arduino to say "HELLO!"
    delay(500);
  }
}

