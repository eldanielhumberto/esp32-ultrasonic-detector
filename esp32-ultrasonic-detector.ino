#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <HTTPClient.h>
#include <secrets.h>

#define SOUND_SPEED 0.034

int echoPin = 18;
int triggerPin = 5;

int duration;
int distanceCm;

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);

  Serial.println("Connecting to Wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wifi successfully");
}

void loop() {
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distanceCm = duration * SOUND_SPEED/2;
  if (distanceCm < 150) {
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;

      http.begin(SERVER_URL);
      String sendData = "Movement";
      http.POST(sendData);

      http.end();
    }

    delay(5000);
  }

  delay(100);
}
