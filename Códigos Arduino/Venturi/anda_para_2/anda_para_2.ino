//#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCL 21
#define BMP_SDO 12
#define BMP_SDA 20

#define BMP_CSB1 10 //p1
#define BMP_CSB2 9 //p2

Adafruit_BMP280 bmp1(BMP_CSB1, BMP_SDA, BMP_SDO, BMP_SCL);

Adafruit_BMP280 bmp2(BMP_CSB2, BMP_SDA, BMP_SDO, BMP_SCL);

void setup() {
  Serial.begin(9600);
  
  //Serial.println("Starting BMP280 device 1...");

  if (!bmp1.begin()) {
  //Serial.println("Sensor BMP280 device 1 was not found.");
    while (1);
  }
 // Serial.println("Initialize BMP280 1 completed.");
 // delay(2000);

 // Serial.println("Starting BMP280 device 2...");

  if (!bmp2.begin()) {
  //  Serial.println("Sensor BMP280 device 2 was not found.");
     while (1);
  }
  //delay(2000);
}  

void loop() {
  
  float p1 = 0;
  float p2 = 0;
  int i = 0;
  int medidas = 50;

  while(i<medidas){
  p1 = p1 + bmp1.readPressure()/*-145,57788*/;
  p2 = p2 + bmp2.readPressure();
  i++;
  } 
  
  Serial.print(p1/medidas);
  Serial.print("  ");
  Serial.println(p2/medidas);
  //Serial.println((p2-p1)/medidas);
  delay(50);
 
}

/*The volume of air produced is 1.02 m3/min (36 ft3/min) 
and the pressure is 867 Pascals (0.0867 N/cm2or0.122 lbs/in2) 
or 6.5 mm Hg at full speed*/
