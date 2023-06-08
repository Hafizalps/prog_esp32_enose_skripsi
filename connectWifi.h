#include <WiFi.h>

//Wifi & Password
const char* ssid = "MultiStore";
const char* password =  "87654321";

void connectWifi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.print(WiFi.localIP());
  Serial.println("Connected to the WiFi network");
}
