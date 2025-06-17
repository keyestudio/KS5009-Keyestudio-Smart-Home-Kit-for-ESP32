#include <ESP32Servo.h>
Servo myservo;
#define servoPin 5

void setup() {
  myservo.attach(servoPin,500,2500);
  myservo.write(0);
  delay(300);
  myservo.write(90);
  delay(300);
  myservo.write(0);
  delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
}
