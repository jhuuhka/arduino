#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN D6
DHT dht(DHTPIN, DHTTYPE);


void setup() {
    Serial.begin(115200);
}

void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.print(t);Serial.print(", ");Serial.print(h);Serial.println();
    delay(1000);
}