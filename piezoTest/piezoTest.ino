int piezoPin = 10;

int doorOpenedAt = 1;
boolean warn = true;
int prevBeep = 0;
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:

}

void loop() {
  updatePiezo();
  delay(1000);


}


unsigned long nextBeep;
void updatePiezo() {
  long beepInterval = 10000;
  int buzTime = 200;

  long warn1 = 30000;
  long warn2 = 60000;
  long warn3 = 300000;

  int pitch1 = 1000;
  int pitch2 = 2000;
  int pitch3 = 3000;
  
  unsigned long timeOpen = millis() - doorOpenedAt;
  if (warn && millis() > nextBeep) {
    Serial.print("Going to beep ");
    if (timeOpen > warn3) {
      Serial.println("3");
      tone(piezoPin, pitch3, buzTime);
      delay(buzTime);
      tone(piezoPin, pitch3, buzTime);
      delay(buzTime);
      tone(piezoPin, pitch3, buzTime);

    } else if (timeOpen > warn2) {
      Serial.println("2");
      tone(piezoPin, pitch2, buzTime);
    } else if (timeOpen > warn1) {
      Serial.println("1");
      tone(piezoPin, pitch1, buzTime);
    } else {
    }
    nextBeep = millis() + beepInterval;

  }
}

