

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    message = (char*)data;
    if (message.indexOf("button1") >= 0) {
      sliderValue11 = "90";
      sliderValue12 = "90";
      sliderValue13 = "180";
      sliderValue14 = "90";
      sliderValue15 = "90";
      sliderValue16 = "0";
      sliderValue17 = "90";
      sliderValue18 = "90";
      sliderValue19 = "180";
      sliderValue20 = "90";
      sliderValue21 = "90";
      sliderValue22 = "0";
      dutyCycle11 = map(sliderValue11.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle11);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("button2") >= 0) {
      sliderValue11 = "90";
      sliderValue12 = "120";
      sliderValue13 = "90";
      sliderValue14 = "90";
      sliderValue15 = "60";
      sliderValue16 = "90";
      sliderValue17 = "90";
      sliderValue18 = "120";
      sliderValue19 = "90";
      sliderValue20 = "90";
      sliderValue21 = "60";
      sliderValue22 = "90";
      dutyCycle11 = map(sliderValue11.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle11);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("button3") >= 0) {
      sliderValue11 = "90";
      sliderValue12 = "120";
      sliderValue13 = "90";
      sliderValue14 = "90";
      sliderValue15 = "140";
      sliderValue16 = "80";
      sliderValue17 = "90";
      sliderValue18 = "120";
      sliderValue19 = "90";
      sliderValue20 = "90";
      sliderValue21 = "60";
      sliderValue22 = "90";
      dutyCycle11 = map(sliderValue11.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle11);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("11s") >= 0) {
      sliderValue11 = message.substring(3);
      dutyCycle11 = map(sliderValue11.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle11);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("12s") >= 0) {
      sliderValue12 = message.substring(3);
      dutyCycle12 = map(sliderValue12.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle12);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("13s") >= 0) {
      sliderValue13 = message.substring(3);
      dutyCycle13 = map(sliderValue13.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle13);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("14s") >= 0) {
      sliderValue14 = message.substring(3);
      dutyCycle14 = map(sliderValue14.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle14);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
     if (message.indexOf("15s") >= 0) {
      sliderValue15 = message.substring(3);
      dutyCycle15= map(sliderValue15.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle15);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("16s") >= 0) {
      sliderValue16 = message.substring(3);
      dutyCycle16= map(sliderValue16.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle16);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("17s") >= 0) {
      sliderValue17 = message.substring(3);
      dutyCycle17 = map(sliderValue17.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle17);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("18s") >= 0) {
      sliderValue18 = message.substring(3);
      dutyCycle18 = map(sliderValue18.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle18);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("19s") >= 0) {
      sliderValue19 = message.substring(3);
      dutyCycle19 = map(sliderValue19.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle19);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("20s") >= 0) {
      sliderValue20 = message.substring(3);
      dutyCycle20 = map(sliderValue20.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle20);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
     if (message.indexOf("21s") >= 0) {
      sliderValue21 = message.substring(3);
      dutyCycle21 = map(sliderValue21.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle21);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("22s") >= 0) {
      sliderValue22 = message.substring(3);
      dutyCycle22 = map(sliderValue22.toInt(), 0, 180, SERVOMIN,SERVOMAX);
      Serial.println(dutyCycle22);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (strcmp((char*)data, "getValues") == 0) {
      notifyClients(getSliderValues());
    }
  }
}
