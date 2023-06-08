#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpppm() {
  Serial.println("Posting PPM...");
  String url = "http://192.168.205.150:40027/alat-1-ppm";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  //Convert String data to Float
  buff["sensor1_ch4"] = sensor1ch4String.toFloat();
  buff["sensor1_co"] = sensor1coString.toFloat();
  buff["sensor1_h2"] = sensor1h2String.toFloat();

  buff["sensor2_co"] = sensor2coString.toFloat();

  buff["sensor3_ch4"] = sensor3ch4String.toFloat();

  buff["sensor4_nh3"] = sensor4nh3String.toFloat();

  buff["sensor5_h2"] = sensor5h2String.toFloat();

  buff["sensor6_co"] = sensor6coString.toFloat();
  buff["sensor6_h2"] = sensor6h2String.toFloat();
  buff["sensor6_c4h10"] = sensor6c4h10String.toFloat();

  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  
  int statusCode = http.POST(jsonParams);
  response = http.getString();
  Serial.println(response);
}
