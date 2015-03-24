/*
  measuringTimeMicros is a small program measuring the uptime in ms and us
  and printing it to the serial monitor each 250ms in order not to be too verbose.
  */
void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  Serial.print("Time in ms: ");
  Serial.println(millis());   // prints the current uptime in ms
  Serial.print("Time in us: ");
  Serial.println(micros());  // prints the current uptime in us
  
  delay(250);
}
