const unsigned int X_AXIS_PIN = A4;
const unsigned int Y_AXIS_PIN = A3;
const unsigned int Z_AXIS_PIN = A2;
const unsigned int BAUD_RATE = 9600;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(BAUD_RATE);
}

void loop() {
  Serial.print("X: ");
  Serial.print(analogRead(X_AXIS_PIN));
  Serial.print(" Y: ");
  Serial.print(analogRead(Y_AXIS_PIN));
  Serial.print(" Z: ");
  Serial.println(analogRead(Z_AXIS_PIN));
  delay(2000);
}

