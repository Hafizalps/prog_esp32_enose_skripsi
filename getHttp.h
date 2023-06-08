#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <String.h>


void getHttp() {
  Serial.println();
  Serial.println("Getting...");
  
  HTTPClient http;
  http.begin("http://192.168.205.150:40027/buzzer-1");

  int httpCode = http.GET();                                        
  if (httpCode > 0) { //Check for the returning code
    char json[500];

    String payload = http.getString();
    
    payload.toCharArray(json, 500);
    StaticJsonDocument<200> doc;
    deserializeJson(doc, json);
    udara = doc["data"].as<String>();
    Serial.println(payload);
  }
  else {
    Serial.println("Error on HTTP request");
  }
}
