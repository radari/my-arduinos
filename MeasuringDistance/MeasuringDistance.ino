const unsigned int TRIG_PIN = 2;
const unsigned int ECHO_PIN = 4;

const unsigned int GREEN_PIN = 12;
const unsigned int YELLOW_PIN = 10;
const unsigned int RED_PIN = 8;

const unsigned int BAUD_RATE = 9600;

const unsigned int FAR_AWAY_MIN_CM = 100;
const unsigned int VERY_CLOSE_MAX_CM = 50;

const float MICROSECONDS_PER_CM = 29.155;
const float MOUNTING_GAP = 0.2;
const float SENSOR_OFFSET = MOUNTING_GAP * MICROSECONDS_PER_CM * 2;


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

  const unsigned long duration = measure_distance();
  float cm = 0;
  
  if (duration == 0) {
    cm = 0;
    Serial.println("Warning: We did not get a pulse from sensor.");
  } else {
    cm = microseconds_to_cm(duration);
    select_led(cm);
    output_distance(cm);
  }
  
  delay(500);
}

const unsigned long measure_distance() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  return pulseIn(ECHO_PIN, HIGH);
}

const float microseconds_to_cm(const unsigned long microseconds) {
  const float net_distance = max(0, microseconds - SENSOR_OFFSET);
  return net_distance / MICROSECONDS_PER_CM / 2;
}

void select_led(const float cm) {
  int result = B000;
  
  if (cm >= FAR_AWAY_MIN_CM) {
    result = B100;
  } else if (cm >= VERY_CLOSE_MAX_CM) {
    result = B010;
  } else {
    result = B001;
  }
  
  digitalWrite(RED_PIN, result & B001);
  digitalWrite(YELLOW_PIN, result & B010);
  digitalWrite(GREEN_PIN, result & B100);
}

void output_distance(const float cm) {
  Serial.print("Distance to nearest object: ");
  Serial.print(cm);
  Serial.println(" cm");
}
