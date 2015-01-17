const unsigned int LED_BIT0 = 12;
const unsigned int LED_BIT1 = 10;
const unsigned int LED_BIT2 = 8;

const unsigned int TIME_OFF = 3000; // 3 seconds

void setup() {
  pinMode(LED_BIT0, OUTPUT);
  pinMode(LED_BIT1, OUTPUT);
  pinMode(LED_BIT2, OUTPUT);
  
  randomSeed(analogRead(A0));
  long result = random(1, 7);
  output_result(result);
}

void loop(){
}

void output_result(const long result) {
  digitalWrite(LED_BIT0, result & B001);
  digitalWrite(LED_BIT1, result & B010);
  digitalWrite(LED_BIT2, result & B100);
  
  delay(TIME_OFF);
  digitalWrite(LED_BIT0, LOW);
  digitalWrite(LED_BIT1, LOW);
  digitalWrite(LED_BIT2, LOW);
}
