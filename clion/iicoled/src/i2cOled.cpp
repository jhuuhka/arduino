#include <Arduino.h>
#include <Adafruit_ssd1306syp.h>
#define SDA_PIN 9
#define SCL_PIN 8
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);
void setup() {
    Serial.begin(115200);
    delay(1000);
    display.initialize();
}
void loop() {

    display.clear();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("text size 1");
    display.setTextColor(BLACK, WHITE); // 'inverted' text
    display.setTextSize(2);
    display.println("Size 2 inve3rted");
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.print("Size 3 white");
    display.update();
    delay(3000);
    display.clear();
    display.update();
    delay(500);
    display.setCursor(0,0);
    display.setTextSize(3);
    display.print("3");
    display.setTextSize(4);
    display.print("4");
    display.setTextSize(5);
    display.print("5");
    display.setTextSize(6);
    display.print("6");
    display.update();
    delay(3000);
    display.clear();
    display.update();
    delay(500);
    display.setCursor(0, 0);
    display.setTextSize(7);
    display.print("7");
    display.update();
    delay(3000);
    display.clear();
    display.update();
    delay(500);
    display.setCursor(0, 0);
    display.setTextSize(8);
    display.print("8");
    display.update();
    delay(3000);
    display.clear();
    display.update();
    delay(500);


}
