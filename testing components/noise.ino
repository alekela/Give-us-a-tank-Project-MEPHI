

int d = 1000;
int mas[7] = {262, 294, 330, 349, 392, 440, 494};
int delays[7] = {195, 1700, 1519, 1432, 1275, 1136, 1014};

//Volume vol;

void setup() {
  // put your setup code here, to run once:
  //vol.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 7; i++){
    tone(11, mas[i]);
    delay(delays[i]);
  }
  tone(11, 0);
  delay(5000);
}
