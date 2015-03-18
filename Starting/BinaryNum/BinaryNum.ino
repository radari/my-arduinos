// digital pins to use
const unsigned int LED_BIT0 = 6;
const unsigned int LED_BIT1 = 8;
const unsigned int LED_BIT2 = 10;
const unsigned int LED_BIT3 = 12;

// Serial comm
const unsigned int BAUD_RATE = 9600;


void setup() {
  
  pinMode(LED_BIT0, OUTPUT);
  pinMode(LED_BIT1, OUTPUT);
  pinMode(LED_BIT2, OUTPUT);
  pinMode(LED_BIT3, OUTPUT);
  
  // Serial comm
  Serial.begin(BAUD_RATE);
}

void loop() {
  if (Serial.available() > 0) {
    int number = Serial.read();
    if (number < '0') {
      Serial.println("Number lower than 0");
    } else if (number > '9') {
      Serial.println("Number higher than 9");
    } else {
      output_number(number);
    }
  }
}

void output_number(const int number) {
  digitalWrite(LED_BIT0, number & B0001);
  digitalWrite(LED_BIT1, number & B0010);
  digitalWrite(LED_BIT2, number & B0100);
  digitalWrite(LED_BIT3, number & B1000);
}
