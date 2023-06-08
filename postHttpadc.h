#include <HTTPClient.h>
#include <ArduinoJson.h>

void postHttpadc() {
  Serial.println("Posting ADC...");
  String url = "http://192.168.205.150:40027/alat-1-adc";
  HTTPClient http;
  String response;

  StaticJsonDocument<1024> buff;
  String jsonParams;
  
  //Convert String data to Float
  buff["sensor1_adc"] = sensor1adcString.toFloat();
  buff["sensor2_adc"] = sensor2adcString.toFloat();
  buff["sensor3_adc"] = sensor3adcString.toFloat();
  buff["sensor4_adc"] = sensor4adcString.toFloat();
  buff["sensor5_adc"] = sensor5adcString.toFloat();
  buff["sensor6_adc"] = sensor6adcString.toFloat();

  serializeJson(buff, jsonParams);
  Serial.println(jsonParams);

  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  
  int statusCode = http.POST(jsonParams);
  response = http.getString();
  Serial.println(response);
}
