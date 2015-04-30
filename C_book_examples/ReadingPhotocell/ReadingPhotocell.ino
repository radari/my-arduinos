int photoCellPin = 0;    // pin number where the photocell is connected
int photoCellValue = 0;  // variable storing the voltage value measured at photoCellPin pin

float voltage = 0;

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);

  Serial.begin(9600);          // Serial commmunication setup at 9600 baud
}

void loop() {
  photoCellValue = analogRead(photoCellPin);    // read and store the read value at potPin pin
  
  voltage = (5.0 / 1023.0) * (float)photoCellValue;
  Serial.print("value: ");
  Serial.print(photoCellValue);
  Serial.print(" voltage: ");
  Serial.println(voltage);
  
  delay(100);    // this small break waits for the ADC to stabilize is often used
}
