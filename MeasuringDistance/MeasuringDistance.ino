const unsigned int TRIG_PIN = 2;
const unsigned int ECHO_PIN = 4;

const unsigned int GREEN_PIN = 12;
const unsigned int YELLOW_PIN = 10;
const unsigned int RED_PIN = 8;

const unsigned int BAUD_RATE = 9600;

const unsigned int FAR_AWAY_MIN_CM = 100;
const unsigned int VERY_CLOSE_MAX_CM = 50;


void setup() {
  // Needed to turn off pin 13 LED
  pinMode(13, OUTPUT);
  // Comm
  Serial.begin(BAUD_RATE);
  // Sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // LEDs
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void loop() {
  // Turn off LEDs
  turn_off_leds();
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  const unsigned long duration = pulseIn(ECHO_PIN, HIGH);
  unsigned long cm = 0;
  
  if (duration == 0) {
    cm = 0;
    Serial.println("Warning: We did not get a pulse from sensor.");
  } else {
    cm = microseconds_to_cm(duration);
    select_led(cm);
    Serial.print("Distance to nearest object: ");
    Serial.print(cm);
    Serial.println(" cm");
    Serial.print(microseconds_to_inches(duration));
    Serial.println(" in");
  }
  
  delay(500);
}

unsigned long microseconds_to_inches(const unsigned long microseconds) {
  return microseconds / 74 / 2;
}


unsigned long microseconds_to_cm(const unsigned long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void turn_off_leds() {
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
}

void select_led(const unsigned long cm) {
  if (cm >= FAR_AWAY_MIN_CM) {
    digitalWrite(GREEN_PIN, HIGH);
  } else if (cm >= VERY_CLOSE_MAX_CM) {
    digitalWrite(YELLOW_PIN, HIGH);
  } else {
    digitalWrite(RED_PIN, HIGH);
  }
}
