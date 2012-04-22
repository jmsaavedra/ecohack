

void sendData(){

  Serial1.print(bmpAltitude);
  Serial1.print(","); 
  Serial1.print(bmpPressure);
  Serial1.print(","); 
  Serial1.print(bmpTemp);
  Serial1.print(","); 
  Serial1.print(heading);
  Serial1.print(","); 
  Serial1.print(dhtTemp);
  Serial1.print(","); 
  Serial1.print(dhtHumidity);
  Serial1.print(","); 
  Serial1.print(sharpDust);
  Serial1.print(","); 
  Serial1.print(COval);
  Serial1.print(","); 
  Serial1.print(O3val);
  Serial1.print(","); 
  Serial1.print(NO2val);
  Serial1.print(","); 
  Serial1.print(VOCval);
  Serial1.println();
  
  debugSerial();
}

void sendHeader(){
  Serial1.print("bmpAltitude");
  Serial1.print(","); 
  Serial1.print("bmpPressure");
  Serial1.print(","); 
  Serial1.print("bmpTemp");
  Serial1.print(","); 
  Serial1.print("heading");
  Serial1.print(","); 
  Serial1.print("dhtTemp");
  Serial1.print(","); 
  Serial1.print("dhtHumidity");
  Serial1.print(","); 
  Serial1.print("sharpDust");
  Serial1.print(","); 
  Serial1.print("COval");
  Serial1.print(","); 
  Serial1.print("O3val");
  Serial1.print(","); 
  Serial1.print("NO2val");
  Serial1.print(","); 
  Serial1.print("VOCval");
  Serial1.println();
  
}

void debugSerial(){

  Serial.println("OUTGOING: ");
  Serial.print(bmpAltitude);
  Serial.print(","); 
  Serial.print(bmpPressure);
  Serial.print(","); 
  Serial.print(bmpTemp);
  Serial.print(","); 
  Serial.print(heading);
  Serial.print(","); 
  Serial.print(dhtTemp);
  Serial.print(","); 
  Serial.print(dhtHumidity);
  Serial.print(","); 
  Serial.print(sharpDust);
  Serial.print(","); 
  Serial.print(COval);
  Serial.print(","); 
  Serial.print(O3val);
  Serial.print(","); 
  Serial.print(NO2val);
  Serial.print(","); 
  Serial.print(VOCval);
  Serial.println();
}

