boolean debug = true;
const char* WIFI_ssid_file = "/wifissid.txt";
const char* WIFI_password_file = "/wifipass.txt";
String WIFISSID;
String WIFIPASS;
boolean WIFIENABLED;
boolean WIFISETUP;

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <stdio.h>
#include "readWriteFile.h"
#include "mainPage.h"
#include "webserver.h"
#include "wifiSetup.h"

void setup() {
  if (debug) {
    Serial.begin(115200);
    Serial.println("Staring Up");
  }
  delay(1000);
  setupWifi();
  if (!WIFIENABLED) {
    WIFISETUP = true;
    Serial.println("No Wifi enabled");
    server.on("/", handleRoot);
    server.on("/action_page", handleForm);
    server.begin();
  }
}

void loop() {
  //if (WIFISETUP) {
    server.handleClient();
  /*} else {
    Serial.println("End Loop");
    delay(1000);
  }*/
}
