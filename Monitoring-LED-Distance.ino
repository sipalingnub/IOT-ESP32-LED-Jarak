#include <WiFi.h>
#include "ThingSpeak.h"

// WiFi settings
const char* ssid = "Kost Blok M";
const char* password = "keputih14a";

// ThingSpeak
unsigned long channelID = 3098553;         // ganti dengan Channel ID
const char* writeAPIKey = "ALP8LYZQUR0PW1JW"; // ganti dengan Write API Key

WiFiClient client;

// Ultrasonic pins
const int trigPin = 5;
const int echoPin = 18;

// LED pin
const int ledPin = 2;

void setup() {
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // WiFi connect
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

float readDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms
  float distance = duration * 0.034 / 2; // cm
  return distance;
}

void loop() {
  float distance = readDistanceCM();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED logic
  if (distance > 0 && distance < 10.0) {
    digitalWrite(ledPin, HIGH);
    delay(200);
  } else {
    digitalWrite(ledPin, LOW);
    delay(500);
  }

  // Upload to ThingSpeak
  int httpCode = ThingSpeak.writeField(channelID, 1, distance, writeAPIKey);
  if (httpCode == 200) {
    Serial.println("Data sent to ThingSpeak");
  } else {
    Serial.println("Failed to send data. HTTP error code: " + String(httpCode));
  }

  delay(15000); // ThingSpeak limit: update setiap 15 detik
}
