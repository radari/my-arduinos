const unsigned int LED_BIT0 = 8;
const unsigned int LED_BIT1 = 10;
const unsigned int LED_BIT2 = 12;

const unsigned int BUTTON_PIN = 7;

const unsigned int TIME_OFF = 3000; // 3 seconds

void setup() {
  pinMode(13, OUTPUT);
  
  pinMode(LED_BIT0, OUTPUT);
  pinMode(LED_BIT1, OUTPUT);
  pinMode(LED_BIT2, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
  randomSeed(analogRead(A0));
}

int current_value = 0;
int old_value = 0;

void loop() {
  current_value = digitalRead(BUTTON_PIN);
  if (current_value != old_value && current_value == HIGH) {
    output_result(random(1, 7));
    delay(50);
  }
  old_value = current_value;
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
