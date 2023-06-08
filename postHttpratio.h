#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpratio() {
  Serial.println("Posting Ratio...");
  String url = "http://192.168.205.150:40027/alat-1-ratio"; 
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  //Convert String data to Float
  buff["sensor1_ratio"] = sensor1ratioString.toFloat();
  buff["sensor2_ratio"] = sensor2ratioString.toFloat();
  buff["sensor3_ratio"] = sensor3ratioString.toFloat();
  buff["sensor4_ratio"] = sensor4ratioString.toFloat();
  buff["sensor5_ratio"] = sensor5ratioString.toFloat();
  buff["sensor6_ratio"] = sensor6ratioString.toFloat();

  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  
  int statusCode = http.POST(jsonParams);
  response = http.getString();
  Serial.println(response);
}
