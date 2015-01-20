// digital pins to use
const unsigned int LED_1 = 3;
const unsigned int LED_2 = 6;
const unsigned int LED_3 = 9;
const unsigned int LED_4 = 11;

void setup() {
  
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  
}

void loop() {
  fade(LED_1);
  fade(LED_2);
  fade(LED_3);
  fade(LED_4);
} 

void fade(const int LED) {
  // fade in from min to max in increments of 5 points
  for(int fadeValue = 0; fadeValue <= 255; fadeValue +=5) {
    // sets the value (range from 0 to 255)
    analogWrite(LED, fadeValue);
    // wait for 30 milliseconds to see the effect
    delay(30);
  }
  
  // fade out from max to min in decrements of 5 points
  for(int fadeValue = 255; fadeValue >= 0; fadeValue -=5) {
    // sets the value (range from 0 to 255)
    analogWrite(LED, fadeValue);
    // wait for 30 milliseconds to see the effect
    delay(30);
  }
}
