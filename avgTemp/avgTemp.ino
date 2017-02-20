#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int temperaturePin = A0;
int samples = 100;
int temperatureArray[100];
int loopCounter = 0;
int allLow = 100;
int allHigh = 0;
int avgTemperature = 0;

void setup() {
  Serial.begin(115200);
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);

  // Print a message to the LCD.
  lcd.print("Hello");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("World!");
}

void loop() {
  int temperature = getTemperature();
  lcd.setCursor(14, 0);
  lcd.print(samples - loopCounter);
  temperatureArray[loopCounter] = temperature;
  if(loopCounter == samples - 1) {    
    getAvgTemperature();    
    updateLcd();
    updateSerial();
    loopCounter = 0;
  } else {
    loopCounter++;
  }
  delay(1000);
  
}

void updateLcd() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp");
  lcd.setCursor(6, 0);
  lcd.print("Lo");
  lcd.setCursor(10, 0);
  lcd.print("Hi");
  
  lcd.setCursor(0, 1);
  lcd.print(avgTemperature);
  lcd.setCursor(6, 1);
  lcd.print(allLow);
  lcd.setCursor(10, 1);
  lcd.print(allHigh);
  
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
  for (int i=0; i<10; i++) {
    int singleTemp = temperatureArray[i];
    sum += singleTemp;    
  }
  avgTemperature = sum / 10;
  allLow = min(allLow, avgTemperature);
  allHigh= max(allHigh, avgTemperature);
}


int getTemperature() {
  int sensorVal = analogRead(temperaturePin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  //Serial.print(temperature);
  //Serial.print(" ");
  return temperature;
}

