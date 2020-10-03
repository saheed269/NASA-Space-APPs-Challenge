//For GPS+sdreading
 #include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

TinyGPSPlus gps;

SoftwareSerial ss(4, 3);

struct dataStruct{
  double latitude;
  double longitude;
  unsigned long date;
  unsigned long time;
  unsigned long COlevel;
  unsigned long CH4level;
}gpsData;


/* MQ-7 Carbon Monoxide Sensor Circuit with Arduino */

const int AOUTpin1=0;//theAOUT pin of the CO sensor goes into analog pin A0 of the arduino
const int DOUTpin1=8;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino



/* MQ-4 Methane Sensor Circuit with Arduino */

const int AOUTpin2=1;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
const int DOUTpin2=9;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino

int limit1;//for CO
int value1;
int limit2;//for CH4
int value2;


void setup() {
Serial.begin(115200);//sets the baud rate
pinMode(DOUTpin1, INPUT);//sets the pin as an input to the arduino
pinMode(DOUTpin2, INPUT);//sets the pin as an input to the arduino
 
 
  ss.begin(9600);
  
  if (!SD.begin(5)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");

File dataFile = SD.open("gps_data_CH4_CO2level.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println("Latitude, Longitude, Date, Time,COlevel, CH4level");
    dataFile.close();
  }
  else{
    Serial.println("nope can't open file");
  }
}


void loop()
{
value1= analogRead(AOUTpin1);//reads the analaog value from the CO sensor's AOUT pin
limit1= digitalRead(DOUTpin1);//reads the digital value from the CO sensor's DOUT pin
//Serial.print("CO value: ");
//Serial.println(value1);//prints the CO value
//Serial.print("Limit: ");//for which value you want to set an alarm(dangerous)
//Serial.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
delay(100);


value2= analogRead(AOUTpin2);//reads the analaog value from the CH4 sensor's AOUT pin
limit2= digitalRead(DOUTpin2);//reads the digital value from the CH4 sensor's DOUT pin
Serial.print("CH4 value: ");
Serial.println(value2);//prints the CH4 value
//Serial.print("Limit: ");////for which value you want to set an alarm(dangerous)
//Serial.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
delay(100);


while (ss.available() > 0){
    if (gps.encode(ss.read())){
      getInfo();
      printResults(); 
      saveInfo();
    }
  }
}

void getInfo(){
  if (gps.location.isValid()){
    gpsData.latitude = gps.location.lat();
    gpsData.longitude = gps.location.lng();
  }
  else{
    Serial.println("Invalid location");
  }
  if (gps.date.isValid()){
    gpsData.date = gps.date.value();
  }
  else{
    Serial.println("Invalid date");
  }
  if (gps.time.isValid()){
    gpsData.time = gps.time.value();
  }
  else{
    Serial.println("Invalid time");
  }
     
 
}

void printResults(){
  Serial.print("Location: ");
  Serial.print(gpsData.latitude, 6); 
  Serial.print(", "); 
  Serial.print(gpsData.longitude, 6);
  Serial.print("  Date: ");
  Serial.print(gpsData.date);
  Serial.print("  Time: ");
  Serial.print(gpsData.time);
  Serial.print("CO value: ");
Serial.print(value1);//prints the CO value
Serial.print("CH4 value: ");
Serial.print(value2);//prints the CH4 value
  Serial.println();
}

void saveInfo(){
File dataFile = SD.open("gps_data.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.print(gpsData.latitude);
    dataFile.print(", ");
    dataFile.print(gpsData.longitude);
    dataFile.print(", ");
    dataFile.print(gpsData.date);
    dataFile.print(", ");
    dataFile.print(gpsData.time); 
        dataFile.print(", ");
    dataFile.print(value1); 
        dataFile.print(", ");
    dataFile.println(value2); 
    
    dataFile.close();
  }
  else{
    Serial.println("nope no datafile");
  }
 }
