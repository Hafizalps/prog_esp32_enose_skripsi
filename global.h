const int pin_input[6] = {36, 39, 34, 35, 32, 33};
const double Rawal[6] = {27, 68, 47, 18, 6.8, 68}; //R1 Pembagi tegangan
double raw[6]; //Data raw sensor
double V[6]; //Mapping ke voltase 0-3.3 V
double mV[6]; //Mapping ke milivolt 0-3300 mV
double Rakhir[6]; //Mapping ke resistansi (kOhm)
double RFilt[6]; //Filtered Sensor Resistance

const int pinBuzzer = 12;
const int pinMute = 13;
int nilaiTombol;

String udara = "";

unsigned long tensec = 2400000; //30000 //40UL*60UL*1000UL //2400000

/*START GGS-1530*/
double Ro1 = 60;
double ratio1530 = 0;
double ppm1530[3];
/*END GGS-1530*/


/*START GGS-2530*/
double Ro2 = 150;
double ratio2530 = 0;
double ppm2530;
/*END GGS-2530*/


/*START GGS-3530*/
double Ro3 = 110;
double ratio3530 = 0;
double ppm3530;
/*END GGS-3530*/


/*START GGS-4430*/
double Ro4 = 35;
double ratio4430 = 0;
double ppm4430;
/*END GGS-4430*/


/*START GGS-6530*/
double Ro5 = 15;
double ratio6530 = 0;
double ppm6530;
/*END GGS-6530*/


/*START GGS-10530*/
double Ro6 = 150;
double ratio10530 = 0;
double ppm10530[3];
/*END GGS-10530*/
