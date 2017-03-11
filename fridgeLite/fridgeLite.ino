int freezerPin = 12;
int fridgePin = 13;

int piezoPin = 4;

int freezerLed = 2;
int fridgeLed = 3;



unsigned long nextBeep;
long beepInterval = 10000;
int buzTime = 200;
long warn1 = 30000;
long warn2 = 60000;
long warn3 = 300000;
int pitch1 = 1000;
int pitch2 = 2000;
int pitch3 = 3000;


int freezerDoor = HIGH;
int fridgeDoor = HIGH;

unsigned long doorOpenedAt;
boolean doorOpen;
unsigned long prevBeep;

void setup() {
  pinMode(freezerPin, INPUT);
  pinMode(fridgePin, INPUT);
  pinMode(freezerLed, OUTPUT);
  pinMode(fridgeLed, OUTPUT);

  digitalWrite(freezerLed, HIGH);
  delay(250);
  digitalWrite(fridgeLed, HIGH);
  delay(250);
  digitalWrite(fridgeLed, HIGH);
  delay(250);
  digitalWrite(freezerLed, HIGH);
  delay(250);
  Serial.begin(115200);

}

void loop() {

  freezerDoor = digitalRead(freezerPin);
  fridgeDoor = digitalRead(fridgePin);

  Serial.print("Freezer: ");Serial.print(freezerDoor);Serial.print("Fridge: ");Serial.print(fridgeDoor);Serial.println();
  
  if (doorOpen == false && (freezerDoor == LOW || fridgeDoor == LOW)) {
    doorOpenedAt = millis();
    doorOpen = true;
  }

  doorOpen = (freezerDoor == LOW || fridgeDoor == LOW);

  updateLed();
  updatePiezo();
  delay(1000);
}

void updateLed() {
  digitalWrite(freezerLed, !freezerDoor);
  digitalWrite(fridgeLed, !fridgeDoor);
}

void updatePiezo() {
  unsigned long timeOpen = millis() - doorOpenedAt;
  if (doorOpen && millis() > nextBeep) {
    if (timeOpen > warn3) {
      tone(piezoPin, pitch3, buzTime);
      delay(buzTime);
      tone(piezoPin, pitch3, buzTime);
      delay(buzTime);
      tone(piezoPin, pitch3, buzTime);
    } 
    else if (timeOpen > warn2) {
      tone(piezoPin, pitch2, buzTime);
    } 
    else if (timeOpen > warn1) {
      tone(piezoPin, pitch1, buzTime);
    }
    nextBeep = millis() + beepInterval;
  }
}
