#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpres() {
  Serial.println("Posting RES...");
  String url = "http://192.168.205.150:40027/alat-1-rs";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  //Convert String data to Float
  buff["sensor1_rs"] = sensor1resString.toFloat();
  buff["sensor2_rs"] = sensor2resString.toFloat();
  buff["sensor3_rs"] = sensor3resString.toFloat();
  buff["sensor4_rs"] = sensor4resString.toFloat();
  buff["sensor5_rs"] = sensor5resString.toFloat();
  buff["sensor6_rs"] = sensor6resString.toFloat();

  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  
  int statusCode = http.POST(jsonParams);
  response = http.getString();
  Serial.println(response);
}
