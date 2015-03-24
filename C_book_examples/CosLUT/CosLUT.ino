float cosLUT[(int) (360.0 * 1 / 0.5)];
const float DEG2RAD = PI / 180;

const float cosinePrecision = 0.5;
const int cosinePeriod = (int) (360.0 * 1 / cosinePrecision);


void setup() {
  // It's to turn integrated led off. 
  pinMode(13, OUTPUT);
  
  initCosineLUT();
}

void loop() {
  // nothing for now!
}

void initCosineLUT() {
  for (int i = 0; i < cosinePeriod; i++) {
    cosLUT[i] = (float) cos(i * DEG2RAD * cosinePrecision);
  }
}

float myFastCosine(float angle) {
  return cosLUT[(int) (angle * 1 / cosinePrecision) % cosinePeriod];
}



