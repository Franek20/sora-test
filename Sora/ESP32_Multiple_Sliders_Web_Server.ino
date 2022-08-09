/* 
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-web-server-websocket-sliders/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#define SERVOMIN  140 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  585 // this is the 'maximum' pulse length count (out of 4096)
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include <Arduino_JSON.h>

Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x40);
// Replace with your network credentials
const char* ssid = "FunBox2-29BF";
const char* password = "99F43553C172C5D623A16D5C7D";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
// Create a WebSocket object

AsyncWebSocket ws("/ws");


String message = "";
String sliderValue11 = "90";
String sliderValue12 = "120";
String sliderValue13 = "180";
String sliderValue14 = "90";
String sliderValue15 = "60";
String sliderValue16 = "0";
String sliderValue17 = "90";
String sliderValue18 = "120";
String sliderValue19 = "180";
String sliderValue20 = "90";
String sliderValue21 = "60";
String sliderValue22 = "0";

int  dutyCycle11;
int  dutyCycle12;
int  dutyCycle13;
int  dutyCycle14;
int  dutyCycle15;
int  dutyCycle16;
int  dutyCycle17;
int  dutyCycle18;
int  dutyCycle19;
int  dutyCycle20;
int  dutyCycle21;
int  dutyCycle22;
//Json Variable to Hold Slider Values
JSONVar sliderValues;

//Get Slider Values
String getSliderValues(){
  sliderValues["sliderValue11"] = String(sliderValue11);
  sliderValues["sliderValue12"] = String(sliderValue12);
  sliderValues["sliderValue13"] = String(sliderValue13);
  sliderValues["sliderValue14"] = String(sliderValue14);
  sliderValues["sliderValue15"] = String(sliderValue15);
  sliderValues["sliderValue16"] = String(sliderValue16);
  sliderValues["sliderValue17"] = String(sliderValue17);
  sliderValues["sliderValue18"] = String(sliderValue18);
  sliderValues["sliderValue19"] = String(sliderValue19);
  sliderValues["sliderValue20"] = String(sliderValue20);
  sliderValues["sliderValue21"] = String(sliderValue21);
  sliderValues["sliderValue22"] = String(sliderValue22);
  String jsonString = JSON.stringify(sliderValues);
  return jsonString;
}
String output26State = "off";
String output27State = "off";
// Initialize SPIFFS
void initFS() {
  if (!SPIFFS.begin()) {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  else{
   Serial.println("SPIFFS mounted successfully");
  }
}

// Initialize WiFi
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void notifyClients(String sliderValues) {
  ws.textAll(sliderValues);
}

#include "message.h"

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   //Serial.print("Angle: ");Serial.print(ang);
   //Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}
void setup() {
  Serial.begin(115200);
  board1.begin();
  board1.setPWMFreq(60); 
  initFS();
  initWiFi();

  initWebSocket();
  // Web Server Root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send(SPIFFS, "/index.html", "text/html");
  });
  

  server.serveStatic("/", SPIFFS, "/");

  // Start server
  server.begin();

}

void loop() {

  board1.setPWM(0, 0, angleToPulse(sliderValue11.toInt()) );
  board1.setPWM(1, 0, angleToPulse(sliderValue12.toInt()) );
  board1.setPWM(2, 0, angleToPulse(sliderValue13.toInt()) );
  board1.setPWM(3, 0, angleToPulse(sliderValue14.toInt()) );
  board1.setPWM(4, 0, angleToPulse(sliderValue15.toInt()) );
  board1.setPWM(5, 0, angleToPulse(sliderValue16.toInt()) );
  board1.setPWM(6, 0, angleToPulse(sliderValue17.toInt()) );
  board1.setPWM(7, 0, angleToPulse(sliderValue18.toInt()) );
  board1.setPWM(8, 0, angleToPulse(sliderValue19.toInt()) );
  board1.setPWM(9, 0, angleToPulse(sliderValue20.toInt()) );
  board1.setPWM(10, 0, angleToPulse(sliderValue21.toInt()) );
  board1.setPWM(11, 0, angleToPulse(sliderValue22.toInt()) );
 ws.cleanupClients();
}
