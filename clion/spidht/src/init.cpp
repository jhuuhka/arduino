#include <Arduino.h>

#include <DHT.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>

#define DHTTYPE DHT22
#define DHTPIN 4
DHT dht(DHTPIN, DHTTYPE);


#define OLED_DC 5  //OLED -- D/C
#define OLED_CS 1  //Not connect
#define OLED_CLK 8 //OLED -- SCL
#define OLED_MOSI 7 //OLED -- SDA
#define OLED_RESET 6//OLED -- RST
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

float h, t;


void setup() {
    Serial.begin(115200);
    Serial.println("Display initialize start");
    display.begin(SSD1306_SWITCHCAPVCC);  // Switch OLED
    display.clearDisplay(); // display OLED
    display.setTextSize(2);
    display.setTextWrap(false);
    display.setTextColor(WHITE);
    display.println("Hello");
    display.println("World");
    display.display();
    Serial.println("Display initialized");
    do {
        Serial.print(h);
        Serial.print(isnan(h));
        Serial.println();
        h = dht.readHumidity();
        t = dht.readTemperature();
        delay(500);
    } while (isnan(h));

}

void loop () {
    Serial.println("Loop.");
    h = dht.readHumidity();
    t = dht.readTemperature();
    Serial.println(t);
    display.clearDisplay();
    display.setCursor(0, 0);
//    display.print("Time: "); display.print(millis()/1000); display.println();
    display.print("Tmp: "); display.print(t, 1);display.println();
    display.print("Hum: "); display.print(h, 0);display.println();
    display.display();
    delay(1000);
}