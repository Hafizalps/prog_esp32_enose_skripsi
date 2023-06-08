#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpro() {
  Serial.println("Posting RO...");
  String url = "http://192.168.205.150:40027/alat-1-ro";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  //Convert String data to Float
  buff["sensor1_ro"] = sensor1roString.toFloat();
  buff["sensor2_ro"] = sensor2roString.toFloat();
  buff["sensor3_ro"] = sensor3roString.toFloat();
  buff["sensor4_ro"] = sensor4roString.toFloat();
  buff["sensor5_ro"] = sensor5roString.toFloat();
  buff["sensor6_ro"] = sensor6roString.toFloat();

  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  
  int statusCode = http.POST(jsonParams);
  response = http.getString();
  Serial.println(response);
}
