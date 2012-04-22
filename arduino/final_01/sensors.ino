

//----------------------- sharpDust ------------------------
//analogPin A5
//led connected to D12;

int dDustPin=5;
int dustVal=0;

int dLedPower=12;
int dDelayTime=280;
int dDelayTime2=40;
float dOffTime=9680;

void dustInit(){
  pinMode(dLedPower,OUTPUT);
  //pinMode(12, OUTPUT);
}

float getSharpDust(){
   // ledPower is any digital pin on the arduino connected to Pin 3 on the sensor
  digitalWrite(dLedPower,LOW); // power on the LED
  delayMicroseconds(dDelayTime);
  dustVal=analogRead(dDustPin); // read the dust value via pin 5 on the sensor
  delayMicroseconds(dDelayTime2);
  digitalWrite(dLedPower,HIGH); // turn the LED off
  delayMicroseconds(dOffTime);
  return dustVal;
}

//----------------------- LSM303 ------------------------
void lsmInit(){
  
  // Calibration values. Use the Calibrate example program to get the values for
  // your compass.
  // M min X: -663 Y: -474 Z: -538 M max X: 339 Y: 442 Z: 322
  compass.m_min.x = -633; 
  compass.m_min.y = -474; 
  compass.m_min.z = -538;
  compass.m_max.x = +339; 
  compass.m_max.y = +442; 
  compass.m_max.z = 322;
}

int getLsmHeading(){
  int heading;

  compass.read();
  //heading = compass.heading((LSM303::vector){ 0,-1,0  } );
  heading = compass.heading();
  Serial.println(heading);
  return heading; 
}

//----------------------- BMP ------------------------
float getBmpAltitude(){

  float val;
  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
  val = bmp.readAltitude(currSTP);
  Serial.print("Real altitude = ");
  //Serial.print(bmp.readAltitude(101500));
  Serial.print(val);
  Serial.println(" meters");
  return val;
}

float getBmpPressure(){
  float val;
  val = bmp.readPressure();
  Serial.print("Pressure = ");
  Serial.print(val);
  Serial.println(" Pa");
  return val;
}

float getBmpTemp(){
  float val;
  val = bmp.readTemperature();
  Serial.print("Temperature = ");
  Serial.print(val);
  Serial.println(" *C");
  return val;
}

//--------------------------------------------------------



