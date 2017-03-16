#include <Arduino.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ESP8266WebServer.h>

uint8_t redPin = D2;
uint8_t greenPin = D3;
uint8_t bluePin = D4;
uint8_t dhtPin = D5;
uint8_t dhtType = DHT22;
uint8_t piezoPin = D6;

DHT dht(dhtPin, dhtType);

void setColor(uint8_t *color) ;
void rgbTest();

struct limits {
    float mid;
    float high;

} limit {23.5, 24.5};

struct statuses {
    float temp;
    float humidity;
    int beepCount;
    String status;
    String uptime;

} status { 0.0, 0.0, 0, "blue", "0"};

struct beeps {
    unsigned long first;
    unsigned long next;
    unsigned long interval;
    unsigned int freq;
    unsigned int duration;
    int maxCount;
} beep {0,0, 10000, 1000, 300, 5};

ESP8266WebServer server(80);

uint8_t dRed[] = {0, 1, 1};
uint8_t dGreen[] = {1, 0, 1};
uint8_t  dBlue[3] = {1, 1, 0};
uint8_t  dYellow[] = {0, 0, 1};
uint8_t  dPurple[] = {0, 1, 0};
uint8_t  dAqua[] = {1 , 0, 0};
uint8_t  dWhite[] = {0 , 0, 0};
uint8_t dBlack[] = {1 , 1, 1};

const char* ssid = "..";
const char* password = "..";
const char* otaPassword = "..";
const char* www_username = "..";
const char* www_password = "..";

IPAddress mini1Ip(192, 168, 8, 193);
IPAddress gatewayIp(192, 168, 8, 1);
IPAddress dnsIp(192, 168, 8, 1);
IPAddress subnetIp(255, 255, 0, 0);


void dhtRead();
void rgbSet();
void buzzer();
JsonObject& prepareResponse(JsonBuffer& jsonBuffer) ;
String getTimeStr(unsigned long value, boolean showSec) ;

void handleRoot() {
    StaticJsonBuffer<500> jsonBuffer;
    JsonObject& json = prepareResponse(jsonBuffer);

    String response;
    json.prettyPrintTo(response);
    //server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "text/plain", response);

}

JsonObject& prepareResponse(JsonBuffer& jsonBuffer) {
    JsonObject& root = jsonBuffer.createObject();

    // Check if any reads failed and exit early (to try again).
    root["temperature"] = status.temp;
    root["humidity"] = status.humidity;
    root["status"] = status.status;
    root["beepCount"] = status.beepCount;
    root["uptime"] = status.uptime;
    return root;
}


void handleNotFound(){
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += server.uri();
    message += "\nMethod: ";
    message += (server.method() == HTTP_GET)?"GET":"POST";
    message += "\nArguments: ";
    message += server.args();
    message += "\n";
    for (uint8_t i=0; i<server.args(); i++){
        message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }
    server.send(404, "text/plain", message);
}

void setup() {

    Serial.begin(115200);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    setColor(dBlack);
    WiFi.mode(WIFI_STA);
    WiFi.config(mini1Ip, dnsIp, gatewayIp, subnetIp);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("Trying to connecting");
        setColor(dAqua);
        delay(300);
        setColor(dBlack);
        Serial.println("Connection Failed! Rebooting...");
        delay(1000);
    }
    server.on("/", handleRoot);
    server.onNotFound(handleNotFound);
    server.begin();
}




void loop() {
    dhtRead();
    rgbSet();
    buzzer();
    server.handleClient();
    status.uptime = getTimeStr(millis(), true);
    delay(1000);
}

void dhtRead() {
    float aTemp = dht.readTemperature();

    Serial.println(aTemp, 1);
    if (!isnan(aTemp)) {
        status.temp = aTemp;
        status.humidity = dht.readHumidity();
    }
}

void rgbSet() {
    if (status.temp >= limit.high) {
        setColor(dRed);
        status.status = "red";
        Serial.println("red");
    } else if (status.temp >= limit.mid) {
        setColor(dGreen);
        status.status = "green";
        Serial.println("green");
    } else {
        Serial.println("blue");
        status.status = "blue";
        setColor(dBlue);
    }
}

void buzzer() {
    unsigned long currentMillis = millis();
    if (status.temp < limit.high) {
        beep.first = millis();
        status.beepCount = 0;

        beep.next = currentMillis;

        return;
    }
    if (beep.first == 0) {
        beep.first = currentMillis;
        beep.next = currentMillis;
    }

    if (currentMillis > beep.next) {
        unsigned long beepCount = ( currentMillis - beep.first) / beep.interval;
        status.beepCount = beepCount;
        beepCount = ((beepCount)<(beep.maxCount)?(beepCount):(beep.maxCount));
        beep.next = currentMillis + beep.interval;

        for (int i = 0; i < beepCount; i++) {
            tone(piezoPin, beep.freq, beep.duration);
            Serial.print("beep: ");Serial.print(i);
            delay(beep.duration);
        }
    }
}


void setColor(uint8_t color[]) {
    digitalWrite(redPin, color[0]);
    digitalWrite(greenPin, color[1]);
    digitalWrite(bluePin, color[2]);
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



