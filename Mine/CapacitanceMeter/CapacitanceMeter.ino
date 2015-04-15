

// constant
const int analogPin = 0;



void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);

  // Serial comm
  Serial.begin(9600);
}

void loop() {
  Serial.print("Read value: ");
  Serial.println(analogRead(analogPin));
  
  delay(1000);


}
