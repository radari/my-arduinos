// digital pins to use
const unsigned int LED_1 = 3;
const unsigned int LED_2 = 6;
const unsigned int LED_3 = 9;
const unsigned int LED_4 = 11;

const unsigned int WAITING = 100;

void setup() {
  
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  
}

void loop() {
  for(int number = B0001; number <= B1000; number = number<<1) {
    digitalWrite(LED_1, number & B0001);
    digitalWrite(LED_2, number & B0010);
    digitalWrite(LED_3, number & B0100);
    digitalWrite(LED_4, number & B1000);
    delay(WAITING)
  }
}




