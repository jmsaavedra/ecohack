
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
}

void loop() {

  bmpAltitude = getBmpAltitude();
  bmpPressure = getBmpPressure();
  bmpTemp = getBmpTemp();
  heading = getLsmHeading();
  dhtTemp = dht.readTemperature();
  dhtHumidity = dht.readHumidity();
  sharpDust = getSharpDust();
  COval = getCO();
  O3val = getO3();
  NO2val = getNO2();
  VOCval = getVOC();
  

  Serial1.println();

  delay(2000);
}






