#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttprsfilt() {
  Serial.println("Posting RES Filter...");
  String url = "http://192.168.205.150:40027/alat-1-rsfilt";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  //Convert String data to Float
  buff["sensor1_rsfilt"] = sensor1rsfiltString.toFloat();
  buff["sensor2_rsfilt"] = sensor2rsfiltString.toFloat();
  buff["sensor3_rsfilt"] = sensor3rsfiltString.toFloat();
  buff["sensor4_rsfilt"] = sensor4rsfiltString.toFloat();
  buff["sensor5_rsfilt"] = sensor5rsfiltString.toFloat();
  buff["sensor6_rsfilt"] = sensor6rsfiltString.toFloat();

  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  
  int statusCode = http.POST(jsonParams);
  response = http.getString();
  Serial.println(response);
}
