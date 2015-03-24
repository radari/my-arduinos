/*
  measuringTime is a small program measuring the uptime and printing it
  to the serial monitor each 250ms in order not to be too verbose.
  */
void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  Serial.print("Time: ");
  Serial.println(millis());   // prints the current uptime
  delay(250);
}
