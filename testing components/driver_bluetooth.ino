// Двигатель A 
int enA = 12;
int in1 = 11;
int in2 = 10;
// Двигатель B
int enB = 7;
int in3 = 8;
int in4 = 9;
char value;
 
void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
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
}
 
void loop()
{
// Установка двигателя A и B на максимальную скорость (0 ... 255)
  analogWrite(enA, 255);   
  analogWrite(enB, 255);
  if (Serial.available()){
    value = Serial.read();
    Serial.print(value);
    if (value == 'F'){
      // А вперед
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      // Б вперед
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if(value == 'B'){
      // А назад
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      // Б назал
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (value == 'R'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
  
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (value == 'L'){
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
  
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }
    else{
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
  }
  else if (isalnum(value) == 0){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}
