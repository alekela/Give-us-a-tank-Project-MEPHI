#include <Servo.h>

Servo servo;
int degree = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(4, OUTPUT);
    servo.write(0);
    servo.attach(4);

}

void loop() {
  // put your main code here, to run repeatedly:
  
    servo.write(90);
    delay(1500);
    servo.write(180);
    delay(1500);
    servo.write(0);
    delay(1500);
}
