// digital pins to use
const unsigned int LED_1 = 3;
const unsigned int LED_2 = 6;
const unsigned int LED_3 = 9;
const unsigned int LED_4 = 11;

const unsigned int TIMES = 2;
const unsigned int ONE = 100;
const unsigned int BOTH = 10;

void setup() {
  
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  
}

void loop() {
  digitalWrite(LED_1, HIGH);
  delay(ONE);
  digitalWrite(LED_2, HIGH);
  delay(BOTH);
  digitalWrite(LED_1, LOW);
  delay(ONE);
  digitalWrite(LED_3, HIGH);
  delay(BOTH);
  digitalWrite(LED_2, LOW);
  delay(ONE);
  digitalWrite(LED_4, HIGH);
  delay(BOTH);
  digitalWrite(LED_3, LOW);
  delay(ONE);
  digitalWrite(LED_3, HIGH);
  delay(BOTH);
  digitalWrite(LED_4, LOW);
  delay(ONE);
  digitalWrite(LED_2, HIGH);
  delay(BOTH);
  digitalWrite(LED_3, LOW);
  delay(ONE);
  digitalWrite(LED_1, HIGH);
  delay(BOTH);
  digitalWrite(LED_2, LOW);
  delay(ONE);
  digitalWrite(LED_1, LOW);
}


