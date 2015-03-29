int potPin = 0;   // pin number where the potentiometer is connected
int potValue = 0;  // variable storing the voltage value measured at potPin pin

float voltage = 0;

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);

  Serial.begin(9600);          // Serial commmunication setup at 9600 baud
}

void loop() {
  potValue = analogRead(potPin);    // read and store the read value at potPin pin
  
  voltage = (5.0 / 1023.0) * (float)potValue;
  Serial.print("value: ");
  Serial.print(potValue);
  Serial.print(" voltage: ");
  Serial.print(voltage);
}
