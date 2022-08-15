//this is mostly example code so don't expect it to be very optimized. 
//also, i'm shit at coding so... yeah. 
#include <WiFi.h>
#include "WiFiUdp.h" //no idea if this is required lol
#include "NTP.h"


const char *ssid     = "WIFI_NAME";
const char *password = "WIFI_PASSWORD";

WiFiUDP wifiUdp;
NTP ntp(wifiUdp);

int y = 0;
int mo = 0;
int d = 0;
int h = 0;
int m = 0;
int s = 0;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting ...");
    delay(500);
    }

  Serial.println("Connected");  
  ntp.isDST(false);
  ntp.timeZone(-7, 0);
  ntp.begin();
  Serial.println("start NTP");
  updateNTP();
  
  }

void loop() {
  updateNTP();
  
  printTime();
  } 

void updateNTP() {
  ntp.update();
  y = ntp.year();
  mo = ntp.month();
  d = ntp.day();
  h = ntp.hours();  
  m = ntp.minutes();
  s = ntp.seconds();
  Serial.println("Synced time through NTP");
  }

void printTime() {
  Serial.print(d);
  Serial.print("/");
  Serial.print(mo);
  Serial.print("/");
  Serial.println(y);
  Serial.print("The exact time is ");
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.println(s);
  }

void writeNixie(int tubeNumber, int digit, bool state) {
  int boolIndex = (10 * (tubeNumber - 1) + digit);
  bool dispBits[boolIndex] = {state};
  }

void clearNixies() {
  for (int i = 0; i < 96; i++) {
        bool dispBits[i] = {LOW};
    }
  }

void writeShiftR(int clkPin, int dataPin) {
  for (int i = 95; i >= 0; i--) {
      digitalWrite(clkPin, HIGH);
      digitalWrite(dataPin, dispBits[i]);
      digitalWrite(clkPin, LOW);
    }
  }

