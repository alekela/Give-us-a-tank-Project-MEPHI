#include <Servo.h>

char value;
Servo servo;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  servo.attach(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  int degree = 40;
  /*int degree = 0;
  servo.write(0);
  for (int i = 1; i < 180; i *= 2){
    servo.write(i);
    delay(1500);
    servo.write(0);
    delay(1500);
  }
*/

   value = Serial.read();
   Serial.write(value);
   if (value == 'R'){
    if (degree < 180){
      degree++;
      servo.write(90);
    }
   }
    if(value == 'L'){
      if (degree > 0){
      degree--;
      servo.write(45);
      }
    }
  
}
