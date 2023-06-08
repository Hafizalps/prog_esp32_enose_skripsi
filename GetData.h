unsigned long lt,dt;

//Variabel String
String sensor1adcString, sensor2adcString, sensor3adcString, sensor4adcString, sensor5adcString, sensor6adcString;
String sensor1voltString, sensor2voltString, sensor3voltString, sensor4voltString, sensor5voltString, sensor6voltString;
String sensor1resString, sensor2resString, sensor3resString, sensor4resString, sensor5resString, sensor6resString;
String sensor1rsfiltString, sensor2rsfiltString, sensor3rsfiltString, sensor4rsfiltString, sensor5rsfiltString, sensor6rsfiltString;
String sensor1roString, sensor2roString, sensor3roString, sensor4roString, sensor5roString, sensor6roString;
String sensor1ratioString, sensor2ratioString, sensor3ratioString, sensor4ratioString, sensor5ratioString, sensor6ratioString;
String sensor1ch4String, sensor1coString, sensor1h2String;
String sensor2coString;
String sensor3ch4String;
String sensor4nh3String;
String sensor5h2String;
String sensor6coString, sensor6h2String, sensor6c4h10String;
String tombolmuteString;

void GetData() {
  //Data raw sensor
  for (int i = 0; i < 6; i++) {
    raw[i] = analogRead(pin_input[i]);    
  }
  //Mapping ke voltase 0-3300mV
  for (int i = 0; i < 6; i++) {
    V[i] = raw[i]*3.3/4095;
    mV[i] = V[i]*1000;
  }
  //V to R
  for (int i = 0; i< 6; i++) {
    if((3.3-V[i])>0){
      Rakhir[i] = V[i]/(3.3-V[i])*Rawal[i];
    }
  }

  dt = micros()-lt;
  lt = micros();

  //low pass RC Time 1 Second
  for (int i = 0; i < 6; i++) {
    RFilt[i] = RFilt[i]+(Rakhir[i]-RFilt[i])*(0.03);
    RFilt[i] = fLimit(RFilt[i], 400, 1, 50);
  }

  /*START SENSOR GGS-1530*/
  if (millis() < tensec || ratio1530 > 1) {
     Ro1 = Ro1*pow((RFilt[0]/Ro1),0.02); //Rnow = RFiltCO
  }   
  Ro1 = fLimit(Ro1, 250, 1, 50);
  ratio1530 = RFilt[0]/Ro1;
  ppm1530[0] = pow(10, ((-4.1685*(ratio1530)) + 4.3659)); //Senyawa CH4
  ppm1530[1] = pow(10, ((-5.7627*(ratio1530)) + 5.9661)); //Senyawa CO
  ppm1530[2] = pow(10, ((-3.4118*(ratio1530)) + 3.3765)); //Senyawa H2
  /*END SENSOR GGS-1530*/

  /*START SENSOR GGS-2530*/
  if (millis() < tensec || ratio2530 > 1) {
     Ro2 = Ro2*pow((RFilt[1]/Ro2),0.01); //Rnow = RFiltCO
  }     
  Ro2 = fLimit(Ro2, 250, 1, 50);
  ratio2530 = RFilt[1]/Ro2;
  ppm2530 = pow(10, ((-3.3778*(ratio2530)) + 3.2311)); //Senyawa CO
  /*END SENSOR GGS-2530*/

  /*START SENSOR GGS-3530*/
  if (millis() < tensec || ratio3530 > 1) {
     Ro3 = Ro3*pow((RFilt[2]/Ro3),0.02); //Rnow = RFiltCO
  }
  Ro3 = fLimit(Ro3, 250, 1, 50);
  ratio3530 = RFilt[2]/Ro3;
  ppm3530 = pow(10, ((-3.876*(ratio3530)) + 4.1163)); //Senyawa CH4
  /*END SENSOR GGS-3530*/

  /*START SENSOR GGS-4430*/
  if (millis() < tensec || ratio4430 > 1) {
     Ro4 = Ro4*pow((RFilt[3]/Ro4),0.02); //Rnow = RFiltCO
  }
  Ro4 = fLimit(Ro4, 250, 1, 50);
  ratio4430 = RFilt[3]/Ro4; // Rs/Ro
  ppm4430 = pow(10, ((-3.3778*(ratio4430)) + 3.2311)); //Senyawa NH3
  /*END SENSOR GGS-4430*/

  /*START SENSOR GGS-6530*/
  if (millis() < tensec || ratio6530 > 1) {
     Ro5 = Ro5*pow((RFilt[4]/Ro5),0.04); //Rnow = RFiltCO
  }
  Ro5 = fLimit(Ro5, 250, 1, 50);
  ratio6530 = RFilt[4]/Ro5;
  ppm6530 = pow(10, ((8.6561*pow(ratio6530, 2)) - (12.041*(ratio6530))+3.3882)); //Senyawa H2
  /*END SENSOR GGS-6530*/

  /*START SENSOR GGS-10530*/
  if (millis() < tensec || ratio10530 > 1) {
     Ro6 = Ro6*pow((RFilt[5]/Ro6),0.02); //Rnow = RFiltCO
  }
  Ro6 = fLimit(Ro6, 250, 1, 50);
  ratio10530 = RFilt[5]/Ro6;
  ppm10530[0] = pow(10, ((-2.2537*(ratio10530)) + 2.1494)); //Senyawa CO
  ppm10530[1] = pow(10, ((-2.4232*(ratio10530)) + 2.4054)); //Senyawa H2
  ppm10530[2] = pow(10, ((-3.022*(ratio10530)) + 3.0247)); //Senyawa C4H10
  /*END SENSOR GGS-10530*/

  //Convert to String
  sensor1adcString = String(raw[0]);
  sensor2adcString = String(raw[1]);
  sensor3adcString = String(raw[2]);
  sensor4adcString = String(raw[3]);
  sensor5adcString = String(raw[4]);
  sensor6adcString = String(raw[5]);

  sensor1voltString = String(mV[0]);
  sensor2voltString = String(mV[1]);
  sensor3voltString = String(mV[2]);
  sensor4voltString = String(mV[3]);
  sensor5voltString = String(mV[4]);
  sensor6voltString = String(mV[5]);

  sensor1resString = String(Rakhir[0]);
  sensor2resString = String(Rakhir[1]);
  sensor3resString = String(Rakhir[2]);
  sensor4resString = String(Rakhir[3]);
  sensor5resString = String(Rakhir[4]);
  sensor6resString = String(Rakhir[5]);

  sensor1rsfiltString = String(RFilt[0]);
  sensor2rsfiltString = String(RFilt[1]);
  sensor3rsfiltString = String(RFilt[2]);
  sensor4rsfiltString = String(RFilt[3]);
  sensor5rsfiltString = String(RFilt[4]);
  sensor6rsfiltString = String(RFilt[5]);

  sensor1roString = String(Ro1);
  sensor2roString = String(Ro2);
  sensor3roString = String(Ro3);
  sensor4roString = String(Ro4);
  sensor5roString = String(Ro5);
  sensor6roString = String(Ro6);

  sensor1ratioString = String(ratio1530);
  sensor2ratioString = String(ratio2530);
  sensor3ratioString = String(ratio3530);
  sensor4ratioString = String(ratio4430);
  sensor5ratioString = String(ratio6530);
  sensor6ratioString = String(ratio10530);

  sensor1ch4String = String(ppm1530[0]);
  sensor1coString = String(ppm1530[1]);
  sensor1h2String = String(ppm1530[2]);

  sensor2coString = String(ppm2530);

  sensor3ch4String = String(ppm3530);

  sensor4nh3String = String(ppm4430);

  sensor5h2String = String(ppm6530);

  sensor6coString = String(ppm10530[0]);
  sensor6h2String = String(ppm10530[1]);
  sensor6c4h10String = String(ppm10530[2]);

  tombolmuteString = String(nilaiTombol);
}
