// digital pins to use
const unsigned int LED_1 = 2;
const unsigned int LED_2 = 6;
const unsigned int LED_3 = 8;
const unsigned int LED_4 = 11;
const unsigned int LED_5 = 12;
const unsigned int LED_6 = 9;
const unsigned int LED_7 = 7;
const unsigned int LED_8 = 4;

const unsigned int WAITING = 100;

void setup() {
  
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);
  pinMode(LED_8, OUTPUT);
  
}

void loop() {
  for(int number = B00000001; number <= B10000000; number = number<<1) {
    digitalWrite(LED_1, number & B00000001);
    digitalWrite(LED_2, number & B00000010);
    digitalWrite(LED_3, number & B00000100);
    digitalWrite(LED_4, number & B00001000);
    digitalWrite(LED_5, number & B00010000);
    digitalWrite(LED_6, number & B00100000);
    digitalWrite(LED_7, number & B01000000);
    digitalWrite(LED_8, number & B10000000);

    delay(WAITING);
  }
  
}




