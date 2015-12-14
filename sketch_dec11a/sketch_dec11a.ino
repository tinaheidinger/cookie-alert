#include <SoftwareSerial.h>
SoftwareSerial XBee(0, 1); //RX, TX
int LDR_pin = 1;
int lightSensorVal = 0;
int lightThreshold = 250;
boolean boxClosed = true;
unsigned long verificationTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // button
  pinMode(7, INPUT);
  digitalWrite(7, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
   lightSensorVal = analogRead(LDR_pin);
   if (boxClosed && (lightSensorVal > lightThreshold)) {
      // oh noo, someone opened the cookie box!
      boxClosed = false;
      // 2 seconds time to disarm alarm system
      verificationTime = millis() + 2000;
   }
   
   if (verificationTime > 0 && millis() > verificationTime) {
      // alarm system has not been disarmed within 2 seconds
      Serial.println("o");
      verificationTime = 0;
      // buzzer plays 1 seconds 440 Hz tone
      digitalWrite(5, HIGH);
      tone(5, 440, 1000);
    }

   if (!boxClosed && (lightSensorVal < lightThreshold)) {
      // box has been closed
      boxClosed = true;
      Serial.println("c");
      digitalWrite(5, LOW);
      verificationTime = 0;
    }

    if (0 == digitalRead(7)) {
      // button
      verificationTime = 0;
      }
}
