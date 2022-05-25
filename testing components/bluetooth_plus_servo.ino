#include <Servo.h>

char value;
Servo servo;
int degree = 0;



void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  servo.attach(10);
  servo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    value = Serial.read();
  
    Serial.print(value);
    Serial.println(degree);
    if ((value == 'R') && (degree < 180)){
      degree = degree + 1;
      servo.write(degree);
    }
    if((value == 'L') && (degree > 0)){
      degree = degree - 1;
      servo.write(degree);
    }
  }

}
