// Example 01 : Blinking LED
const unsigned int LED = 13; // LED connected to digital pin 13
const unsigned int TIME_ON = 1000; // 1 seconds
const unsigned int TIME_OFF = 5000; // 5 seconds


void setup()
{
  pinMode(LED, OUTPUT); // sets the digital pin as output
}

void loop()
{
  digitalWrite(LED, HIGH);  // turns the LED on
  delay(TIME_ON);              // waits for some seconds
  digitalWrite(LED, LOW);   // turns the LED off
  delay(TIME_OFF);
}

