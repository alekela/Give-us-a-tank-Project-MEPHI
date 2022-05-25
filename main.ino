#include <Servo.h>

Servo servo_gun;
Servo servo_head;

char value;


int angle_head;
int angle_gun;
int state = 0;
int laser = 4;
// Двигатель B
int enB = 7;
int in4 = 8;
int in3 = 9;
// Двигатель A 
int enA = 12;
int in1 = 11;
int in2 = 10;
int zoomer = 13;
int light_green = 14;
int light_yellow = 15;
int light_red = 16;


void setup() {
  Serial.begin(38400);
  pinMode(zoomer, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  pinMode(light_green, OUTPUT);
  pinMode(light_yellow, OUTPUT);
  pinMode(light_red, OUTPUT);
  pinMode(laser, OUTPUT);
  servo_gun.attach(6);
  servo_head.attach(5);
  angle_head = 90;
  angle_gun = 180;
  state = 0;
  servo_gun.write(angle_gun);
  servo_head.write(angle_head);
  digitalWrite(light_green, HIGH);
  digitalWrite(light_yellow, LOW);
  digitalWrite(light_red, LOW);
}


void loop() {
  if (Serial.available()){
   value = Serial.read();
   Serial.print(value);
   if (value == 'W'){
      state = 1; // режим наводки 
  
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
   }
   else if (value == 'w'){
      state = 0;
      
      while (angle_gun < 180 || angle_head != 90){
        if (angle_gun < 180){
          angle_gun += 2;
          delay(10);
        }
        if (angle_head < 90){
          angle_head += 2;
          delay(10);
        }
        if (angle_head > 90){
          angle_head -= 2;
          delay(10);
        }
        servo_gun.write(angle_gun);
        servo_head.write(angle_head);
      }
   }
   
   if (state == 0){
      digitalWrite(light_green, HIGH);
      digitalWrite(light_yellow, LOW);
      digitalWrite(light_red, LOW);
      
      if (value != 'S'){
        if (value == 'F'){
          // А вперед
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          // Б вперед
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
        }
        if(value == 'B'){
          // А назад
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          // Б назал
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
        }
        if (value == 'L'){
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
      
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
        }
        if (value == 'R'){
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
        }
        if (value == 'G'){
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
      
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
        }
        if (value == 'I'){
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
        }
        if (value == 'H'){
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
        }
        if (value == 'J'){
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
        }
      }
      else{
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
      }
   }
   if (state == 1){
      digitalWrite(light_green, LOW);
      digitalWrite(light_yellow, HIGH);
      digitalWrite(light_red, LOW);
      
      if (value == 'B' && angle_gun < 180){
        angle_gun += 2;
      }
      else if (value == 'F' && angle_gun > 70){
        angle_gun -= 2;
      }
      else if (value == 'R' && angle_head < 180){
        angle_head += 2;
      }
      else if (value == 'L' && angle_head > 0){
        angle_head -= 2;
      }
      
      servo_head.write(angle_head);
      servo_gun.write(angle_gun);

      if (value == 'V'){
        digitalWrite(light_green, LOW);
        digitalWrite(light_yellow, LOW);
        digitalWrite(light_red, HIGH);
        
        digitalWrite(laser, HIGH);
        tone(zoomer, 600); // поставить звук выстрела
        delay(400); // задержка при выстреле
        noTone(zoomer);
        digitalWrite(laser, LOW);
        delay(1000); // задержка после выстрела

        digitalWrite(light_green, LOW);
        digitalWrite(light_yellow, HIGH);
        digitalWrite(light_red, LOW);
      }
      
   }

  }
  else if (isalnum(value) == 0){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    servo_head.write(90);
    servo_gun.write(180);
    digitalWrite(laser, LOW);
    digitalWrite(light_green, LOW);
    digitalWrite(light_yellow, LOW);
    digitalWrite(light_red, LOW);

  }
}
