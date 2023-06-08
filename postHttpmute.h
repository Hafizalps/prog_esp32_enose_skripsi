#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpmute() {
  Serial.println("Posting Mute Button Condition...");
  String url = "http://192.168.205.150:40027/alat-1-mute";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  buff["status_tombol"] = tombolmuteString.toFloat();
  
  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  
  int statusCode = http.POST(jsonParams);
  response = http.getString();
  Serial.println(response);
}
