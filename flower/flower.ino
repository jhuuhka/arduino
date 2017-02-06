#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


const int led = 13;
const int rLed = D2;
const int gLed = D3;
const int bLed = D1;

const char* ssid = "sikssikssiks";
const char* password = "K155AK01RA";

int status = WL_IDLE_STATUS;     // the Wifi radio's status
int aResult;
int minResult = 1024;
int maxResult = 0;
int previousMillis;
ESP8266WebServer server(80);

void setup() {
  pinMode(led, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(gLed, OUTPUT);
  pinMode(bLed, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.begin();
  testLed();
}

void loop() {
  server.handleClient();
  
  if (previousMillis + 10000 < millis()) {
    Serial.println("Reset values");      
    updateLed();
    minResult = 1024;
    maxResult = 0;
    previousMillis = millis();
  
  }
  aResult = analogRead(A0);   
  if (aResult < minResult) minResult = aResult;
  if (aResult > maxResult) maxResult = aResult;
  
  delay(250);
}

void updateLed() {
  if (aResult < 100) {
    writeLed(HIGH, LOW, LOW);
  } else if (aResult > 100 && aResult < 500) {
    writeLed(LOW, HIGH, LOW);
  } else {
    writeLed(LOW, LOW, HIGH);
  }
}

void testLed() {
  writeLed(LOW, LOW, LOW);
  delay(250);
  writeLed(HIGH, LOW, LOW);
  delay(250);
  writeLed(LOW, HIGH, LOW);
  delay(250);
  writeLed(LOW, LOW, HIGH);
  delay(250);
  writeLed(HIGH, HIGH, HIGH);
  delay(250);
  writeLed(LOW, LOW, LOW);
  delay(250);
}

void writeLed(int rValue, int gValue, int bValue) {
  //debugLed(rValue, gValue, bValue);
  digitalWrite(rLed, rValue);
  digitalWrite(gLed, gValue);
  digitalWrite(bLed, bValue);
}

void debugLed(int rValue, int gValue, int bValue) {
  Serial.print("Red: ");
  Serial.print(rValue);
  Serial.print(". Blue: ");
  Serial.print(bValue);
  Serial.print(". Green: ");
  Serial.print(gValue);
  Serial.println();

}

void handleRoot() {
  digitalWrite(led, 1);
  String color = "red";
  if (aResult > 100) {
    color = "green";
  }
  if (aResult > 500) {
    color = "blue";
  }
  
  String s = "<html>";
  s += "<head><title>Flower</title><meta http-equiv='refresh' content='5'></head>";
  s += "<body>";
  s += "Joulukukka";
  s += "<br/>Updated: ";
  s += previousMillis;
  s += "</br>Current: ";
  s += aResult;
  s += ". Min: ";
  s += minResult;
  s += ". Max: ";
  s += maxResult;
  s += "</br>";
  s += "<span style='background-color: " + color + ";'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span>";
  s += "</body>";
  s += "</html>\n";

  server.send(200, "text/html", s);
  server.send(aResult);
  digitalWrite(led, 0);
}

