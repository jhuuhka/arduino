void setup() {
  Serial.begin(115200);
    for (int i = 0; i < 1200; i += 1) {
  //for (int i = 4100; i < 4300; i += 1) {

    Serial.print(i); Serial.print("->"); Serial.print(getTimeStr(i * 1000, false)); Serial.println();
    delay(100);
  }




}

void loop() {

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



