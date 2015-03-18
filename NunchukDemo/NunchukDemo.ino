#include <Wire.h>
#include "nunchuk.h"

const unsigned int BAUD_RATE = 19200;

Nunchuk nunchuk;
int sensorValue = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(13,OUTPUT);
  nunchuk.initialize();
}

void loop() {
  sensorValue = analogRead(A5);
  Serial.print(sensorValue);
  delay(2000);
  //if (nunchuk.update()) {
  //  Serial.print(nunchuk.joystick_x());
  //  Serial.print(" ");
  //  Serial.print(nunchuk.joystick_y());
  //  Serial.print(" ");
  //  Serial.print(nunchuk.x_acceleration());
  //  Serial.print(" ");
  //  Serial.print(nunchuk.y_acceleration());
  //  Serial.print(" ");
  //  Serial.print(nunchuk.z_acceleration());
  //  Serial.print(" ");
  //  Serial.print(nunchuk.z_button());
  //  Serial.print(" ");
  //  Serial.println(nunchuk.c_button());
  //}
}
