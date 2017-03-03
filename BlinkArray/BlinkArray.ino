/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/

int led = D3;
int dArray[9] = {D0, D1, D2, D3, D4, D5, D6, D7, D8};
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  for (int i = 0; i < 8; i++) {
    pinMode(dArray[i], OUTPUT);  
  }
  
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 0; i < 9; i++) {
    delay(500);
    Serial.print(i);Serial.println("->");Serial.print(dArray[i]);Serial.println();
    digitalWrite(dArray[i], HIGH);
    delay(1000);
    digitalWrite(dArray[i], LOW);  
    
  }
  
}
