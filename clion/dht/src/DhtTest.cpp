#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN D6
DHT dht(DHTPIN, DHTTYPE);


void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);

}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Loop");
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.print(t);Serial.print(", ");Serial.print(h);Serial.println();
    delay(1000);
}