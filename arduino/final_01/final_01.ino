
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LSM303.h>
#include "DHT.h"
#define DHTPIN 11     // what pin we're connected to
#define currSTP 100450 //Current sea level temp/pressure: http://www.nws.noaa.gov/obhistory/KNYC.html

Adafruit_BMP085 bmp;
LSM303 compass;

//DHT dht(DHTPIN, DHTTYPE);
DHT dht(DHTPIN, DHT22);

float bmpAltitude = 0.0f;
float bmpPressure = 0.0f;
float bmpTemp = 0.0f;
float dhtTemp = 0.0f;
float dhtHumidity = 0.0f;
float sharpDust = 0.0f;
int heading = 0;
int COval = 0;
int O3val = 0;
int NO2val = 0;
int VOCval = 0;

void setup() {
  Serial.begin(38400);
  Serial1.begin(38400);
  Wire.begin();
  bmp.begin();  
  dht.begin();
  compass.init();
  compass.enableDefault();
  dustInit();
  lsmInit();
  
  sendHeader();
}

void loop() {

  analogReference(DEFAULT); //5v analogRef
  fixARef();

  bmpAltitude = getBmpAltitude();
  bmpPressure = getBmpPressure();
  bmpTemp = getBmpTemp();
  heading = getLsmHeading();
  dhtTemp = getDhtTemp();
  dhtHumidity = getDhtHumidity();
  sharpDust = getSharpDust();

  analogReference(DEFAULT); //this should be set to EXTERNAL (???) so it's at 1.8v
  fixARef();

  COval = getCO();
  O3val = getO3();
  NO2val = getNO2();
  VOCval = getVOC();

  sendData();
  Serial.println("------------------------------");
  
  delay(2000);
}









