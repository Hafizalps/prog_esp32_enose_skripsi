#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpvolt() {
  Serial.println("Posting Volt...");
  String url = "http://192.168.205.150:40027/alat-1-v";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  //Convert String data to Float
  buff["sensor1_volt"] = sensor1voltString.toFloat();
  buff["sensor2_volt"] = sensor2voltString.toFloat();
  buff["sensor3_volt"] = sensor3voltString.toFloat();
  buff["sensor4_volt"] = sensor4voltString.toFloat();
  buff["sensor5_volt"] = sensor5voltString.toFloat();
  buff["sensor6_volt"] = sensor6voltString.toFloat();

  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  
  int statusCode = http.POST(jsonParams);
  response = http.getString();
  Serial.println(response);
}
