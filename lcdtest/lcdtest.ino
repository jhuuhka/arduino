#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int temperaturePin = A0;

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
  lcd.setCursor(8, 1);
  lcd.print(temperature);
  delay(1000);
}

int getTemperature() {
  int sensorVal = analogRead(temperaturePin);
  // send the 10-bit sensor value out the serial port
  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  // convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;

  // Send the voltage level out the Serial port
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // convert the voltage to temperature in degrees C
  // the sensor changes 10 mV per degree
  // the datasheet says there's a 500 mV offset
  // ((volatge - 500mV) times 100)
  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
  return temperature;
}

