#include <Arduino.h>
#include <LiquidCrystal.h>

int getTemperature();
int getAvgTemperature();
void updateLcd();
void updateSerial();
void updateFrzLcd();
void updateLed();
void updatePiezo();
void updateUptime();
String getTimeStr(unsigned long millis, boolean showSec);
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int temperaturePin = A0;
int freezerPin = 8;
int fridgePin = 9;
int piezoPin = 10;

unsigned long nextBeep;
long beepInterval = 10000;
int buzTime = 200;
long warn1 = 30000;
long warn2 = 60000;
long warn3 = 300000;
int pitch1 = 1000;
int pitch2 = 2000;
int pitch3 = 3000;


int freezerLed = 11;
int fridgeLed = 12;
int redLed = 13;

int samples = 30;
int temperatureArray[30];

int loopCounter = 0;
int allLow = 100;
int allHigh = 0;
int avgTemperature = 0;

int freezerDoor = HIGH;
int fridgeDoor = HIGH;

unsigned long doorOpenedAt;
boolean doorOpen;
unsigned long prevBeep;

void setup() {
    Serial.begin(115200);
    pinMode(freezerPin, INPUT);
    pinMode(fridgePin, INPUT);
    pinMode(freezerLed, OUTPUT);
    pinMode(fridgeLed, OUTPUT);
    pinMode(redLed, OUTPUT);


    lcd.begin(16, 2);
    lcd.print("Hello");
    lcd.setCursor(0, 1);
    lcd.print("World!");

    digitalWrite(freezerLed, HIGH);
    delay(250);
    digitalWrite(fridgeLed, HIGH);
    delay(250);
    digitalWrite(redLed, HIGH);
    delay(250);
}

void loop() {

    freezerDoor = digitalRead(freezerPin);
    fridgeDoor = digitalRead(fridgePin);

    if (doorOpen == false && (freezerDoor == LOW || fridgeDoor == LOW)) {
        doorOpenedAt = millis();
        doorOpen = true;
    }

    doorOpen = (freezerDoor == LOW || fridgeDoor == LOW);

    int temperature = getTemperature();
    if (avgTemperature != 0 && temperature > avgTemperature + 10) {
        temperature = avgTemperature;
    }
    temperatureArray[loopCounter] = temperature;
    if (loopCounter == samples - 1) {
        getAvgTemperature();
        updateLcd();
        updateSerial();
        loopCounter = 0;
    } else {
        loopCounter++;
    }

    updateFrzLcd();
    updateLed();
    updatePiezo();
    delay(1000);
}

void updateLed() {
    digitalWrite(freezerLed, !freezerDoor);
    digitalWrite(fridgeLed, !fridgeDoor);
    digitalWrite(redLed, avgTemperature > 19);
}

void updatePiezo() {
    unsigned long timeOpen = millis() - doorOpenedAt;
    Serial.print("Piezo. "); Serial.print("Millis "); Serial.print(millis()); Serial.print(". Door open"); Serial.print(doorOpen); Serial.print(". Door opened at"); Serial.print(doorOpenedAt); Serial.print(". Next beep at"); Serial.print(nextBeep); Serial.println();
    if (doorOpen && millis() > nextBeep) {
        Serial.println("Going to beep. TimeOpen "); Serial.println(timeOpen);
        if (timeOpen > warn3) {
            tone(piezoPin, pitch3, buzTime);
            delay(buzTime);
            tone(piezoPin, pitch3, buzTime);
            delay(buzTime);
            tone(piezoPin, pitch3, buzTime);
        } else if (timeOpen > warn2) {
            tone(piezoPin, pitch2, buzTime);
        } else if (timeOpen > warn1) {
            tone(piezoPin, pitch1, buzTime);
        }
        nextBeep = millis() + beepInterval;
    }
}

void updateLcd() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tmp");
    lcd.setCursor(4, 0);
    lcd.print("Lo");
    lcd.setCursor(7, 0);
    lcd.print("Hi");

    lcd.setCursor(0, 1);
    lcd.print(avgTemperature);
    lcd.setCursor(4, 1);
    lcd.print(allLow);
    lcd.setCursor(7, 1);
    lcd.print(allHigh);

    updateUptime();
}

void updateUptime() {
    String result;
    lcd.setCursor(10, 0);
    lcd.print("Uptime");
    lcd.setCursor(10, 1);
    lcd.print(getTimeStr(millis(), false));
    lcd.print("     ");
}

String getTimeStr(unsigned long value, boolean showSec) {
    String result;
    int seconds = value / 1000;
    int hours = seconds / 3600;
    int mins = (seconds / 60) % 60;

    if (hours > 0) {
        result = String(hours) + "h";
        if (mins < 10) {
            result += "0";
        }
        result += String(mins) + "m";
    } else if (seconds > 59) {
        result = String(mins) + "m";
        if (showSec) {
            seconds %= 60;
            if (seconds < 10) {
                result += "0";
            }
            result += String(seconds) + "s";
        }
    } else {
        result = String(seconds) + "s";
    }
    Serial.print("Uptime: "); Serial.print(value); Serial.print("->"); Serial.print(result); Serial.println();
    return result;
}

void updateFrzLcd() {
    if (doorOpen) {
        String msg;
        if (fridgeDoor == LOW && freezerDoor == HIGH) {
            msg = "Fridge";
        } else if (fridgeDoor == HIGH && freezerDoor == LOW) {
            msg = "Freezer";
        } else {
            msg = "Fri/Frzr";
        }
        lcd.setCursor(10,0);
        lcd.print(msg);
        lcd.setCursor(10,1);
        unsigned long since = millis() - doorOpenedAt;
        lcd.print(getTimeStr(since, true));
        lcd.print("       ");
    } else {
        updateUptime();
    }
}
void updateSerial() {
    Serial.print("Average: ");
    Serial.print(avgTemperature);
    Serial.print(". Low: ");
    Serial.print(allLow);
    Serial.print(". High: ");
    Serial.print(" ");
    Serial.print(allHigh);
    Serial.print(".");
    Serial.println();
}

int getAvgTemperature() {
    int sum = 0;
    for (int i = 0; i < samples; i++) {
        int singleTemp = temperatureArray[i];
        sum += singleTemp;
    }
    avgTemperature = sum / samples;
    allLow = min(allLow, avgTemperature);
    allHigh = max(allHigh, avgTemperature);
}


int getTemperature() {
    int sensorVal = analogRead(temperaturePin);
    float voltage = (sensorVal / 1024.0) * 5.0;
    float temperature = (voltage - .5) * 100;
    //Serial.print(temperature); Serial.print(" ");
    return temperature;
}
