// Example 01 : Blinking LED
const unsigned int LED = 13; // LED connected to digital pin 13
const unsigned int PAUSE = 3000; // 3 seconds

void setup()
{
  pinMode(LED, OUTPUT); // sets the digital pin as output
}

void loop()
{
  digitalWrite(LED, HIGH);  // turns the LED on
  delay(PAUSE);              // waits for some seconds
  digitalWrite(LED, LOW);   // turns the LED off
  delay(PAUSE);
}

