#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);  // указываем пины rx и tx

void setup()  {
  mySerial.begin(38400);
  Serial.begin(38400);
  delay(500);
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
