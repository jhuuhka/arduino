#include <Arduino.h>

/**
 * Switch colors for common cathode RGB led.
 */

uint8_t redPin = D1;
uint8_t greenPin = D2;
uint8_t bluePin = D3;

void setColor(uint8_t *color) ;

//Colors for common cathode leds.
uint8_t dRed[] = {0, 1, 1};
uint8_t dGreen[] = {1, 0, 1};
uint8_t dBlue[] = {1, 1, 0};
uint8_t dYellow[] = {0, 0, 1};
uint8_t dPurple[] = {0, 1, 0};
uint8_t dAqua[] = {1 , 0, 0};


void setup() {
    Serial.begin(115200);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop() {
    setColor(dRed);
    delay(1000);
    setColor(dGreen);
    delay(1000);
    setColor(dBlue);
    delay(1000);
    setColor(dYellow);
    delay(1000);
    setColor(dPurple);
    delay(1000);
    setColor(dAqua);
    delay(1000);
}

void setColor(uint8_t *color) {
    digitalWrite(redPin, color[0]);
    digitalWrite(greenPin, color[1]);
    digitalWrite(bluePin, color[2]);
}