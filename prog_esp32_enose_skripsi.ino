#include "global.h"
#include "bipAlarm.h"
#include "limit.h"
#include "GetData.h"
#include "connectWifi.h"
#include "postHttpadc.h"
#include "postHttpvolt.h"
#include "postHttpres.h"
#include "postHttprsfilt.h"
#include "postHttpro.h"
#include "postHttpratio.h"
#include "postHttpppm.h"
#include "postHttpmute.h"
#include "getHttp.h"

unsigned long ltacq, ltsend;

void setup() {
  Serial.begin(115200);
  pinMode(36,INPUT); //Sensor GGS-1530
  pinMode(39,INPUT); //Sensor GGS-2530
  pinMode(34,INPUT); //Sensor GGS-3530
  pinMode(35,INPUT); //Sensor GGS-4430
  pinMode(32,INPUT); //Sensor GGS-6530
  pinMode(33,INPUT); //Sensor GGS-10530
  pinMode(pinMute,INPUT_PULLUP); //pinMute
  pinMode(pinBuzzer,OUTPUT); //pinBuzzer
  digitalWrite(pinBuzzer, LOW);
  connectWifi();
}

void loop() {
  if(millis()-ltacq>5) { //Akuisisi tiap 5 ms
    nilaiTombol = digitalRead(pinMute);
    GetData();
    ltacq = millis();
  }
  if(millis()-ltsend>1000) { //Kirim data tiap 1 detik
    postHttpadc();
    postHttpvolt();
    postHttpres();
    postHttprsfilt();
    postHttpro(); 
    postHttpratio(); 
    postHttpppm();
    postHttpmute();
    getHttp();
    ltsend=millis();
  }
// === Program Buzzer ===
  if(nilaiTombol == 1){
    if (udara == "Udara Bersih") {
      digitalWrite(pinBuzzer, LOW);
    } else {
      frequency_1();
      frequency_2();
    }
  } else {
    if (udara == "Udara Bersih") {
      digitalWrite(pinBuzzer, LOW);
    } else {
      digitalWrite(pinBuzzer, LOW);
    }
  }
}
