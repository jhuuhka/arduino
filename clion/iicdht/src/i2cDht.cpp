#include <Arduino.h>
#include <Adafruit_ssd1306syp.h>
#include <DHT.h>

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
    display.setTextSize(5);
    display.print(" ...");
    display.update();
    delay(3000);

}
void loop() {
    float t = dht.readTemperature();
    display.clear();
    display.setCursor(0, 0);

    display.print(t, 1);
    display.update();
    delay(3000);
    display.clear();
    display.setCursor(10,2);
    display.print("...");
    display.update();
    delay(300);
    display.update();
}
