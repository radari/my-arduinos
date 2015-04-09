const unsigned int BAUD_RATE = 9600;

const unsigned int trigPin = 7;
const unsigned int echoPin = 5;

void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  // Comm
  Serial.begin(BAUD_RATE);
  // Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  const unsigned long duration = measure_distance();
  Serial.print("Duration (microsecond): ");
  Serial.print(duration);
  Serial.print(" cm: ");
  Serial.print(microseconds_to_cm(duration));
  Serial.print(" cm: ");
  Serial.println(seconds_to_cm(duration/1000000.0));

  delay(100);
}

const unsigned long measure_distance() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigPin, LOW);
  
  return pulseIn(echoPin, HIGH);
}


const float microseconds_to_cm(const unsigned long microseconds) {
  // read this formula in a datasheet
  return microseconds / 58.0;
}

const float seconds_to_cm(const float seconds) {
  // sound speed under room temperature
  return (seconds * 343.21) / 2.0 * 100;
}
