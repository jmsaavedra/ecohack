#include "DHT.h"
#define DHTPIN 11     // what pin we're connected to
#include <Wire.h>
#include <Adafruit_BMP085.h>


#define SCALE 2  // accel full-scale, should be 2, 4, or 8

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP085 bmp;

const int ledPin =  13;      // the number of the LED pin  
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was update
long interval = 3000;           // interval at which to blink (milliseconds)

void setup() {
  Serial.begin(38600); 
  Serial.println("Hello World");
 
  pinMode(ledPin, OUTPUT);  
  
  dht.begin();
  bmp.begin();  
  
  Wire.begin();  // Start up I2C, required for LSM303 communication
  initLSM303(SCALE);  // Initialize the LSM303, using a SCALE full-scale range  
}

 float humidity;
 float temperature;
 float altitude;

void loop() {
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();     
    altitude = bmp.readAltitude();
   
    getLSM303_accel(accel);  // get the acceleration values and store them in the accel array
    while(!(LSM303_read(SR_REG_M) & 0x01));  // wait for the magnetometer readings to be ready
    getLSM303_mag(mag);  // get the magnetometer values, store them in mag
    //printValues(mag, accel);  // print the raw accel and mag values, good debugging
  
    for (int i=0; i<3; i++)
      realAccel[i] = accel[i] / pow(2, 15) * SCALE;  // calculate real acceleration values, in units of g
  
    /* print both the level, and tilt-compensated headings below to compare */
    getHeading(mag);
    getTiltHeading(mag, realAccel);
   
    Serial.print("Humidity = ");
    Serial.println(humidity);
    Serial.print("Temperature = ");
    Serial.println(temperature);
    Serial.print("Altitude = ");
    Serial.println(altitude);
    printValues(mag,realAccel);
  }  
}

void printValues(int * magArray, float * accelArray)
{
  /* print out mag and accel arrays all pretty-like */
  Serial.print(accelArray[X], DEC);
  Serial.print("\t");
  Serial.print(accelArray[Y], DEC);
  Serial.print("\t");
  Serial.print(accelArray[Z], DEC);
  Serial.print("\t\t");
  
  Serial.print(magArray[X], DEC);
  Serial.print("\t");
  Serial.print(magArray[Y], DEC);
  Serial.print("\t");
  Serial.print(magArray[Z], DEC);
  Serial.println();
}


