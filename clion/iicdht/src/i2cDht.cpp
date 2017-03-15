#include <Arduino.h>
#include <Adafruit_ssd1306syp.h>
#include <DHT.h>
#include <Fonts/FreeSans24pt7b.h>
#include <Fonts/FreeSans12pt7b.h>

#define DHTTYPE DHT22
#define DHTPIN 10
#define SDA_PIN 9
#define SCL_PIN 8

DHT dht(DHTPIN, DHTTYPE);

Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);
void setup() {
    Serial.begin(115200);
    dht.readTemperature();

    display.initialize();
    display.setTextSize(1);
    display.setFont(&FreeSans12pt7b);
    display.setCursor(0,40);
    display.print("Hello world!");
    display.update();
    delay(3000);
    display.setFont(&FreeSans24pt7b);

}
void loop() {
    float t = dht.readTemperature();
    display.clear();
    display.setCursor(0,50);

    display.print(t, 1);
    display.print("C");
    display.update();
    delay(3000);
    display.clear();
    display.setCursor(0,50);
    display.print("   ...");
    display.update();
    delay(300);
    display.update();
}
