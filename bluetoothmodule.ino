char value;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
   value = Serial.read();
   Serial.print(value);
   if (value == 'W'){
      digitalWrite(13, HIGH);
    }
    else if(value == 'w'){
      digitalWrite(13, LOW);
    }
  }
  
}
