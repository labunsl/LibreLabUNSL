#include <elapsedMillis.h>
#include "QList.h"
#include <Adafruit_AHT10.h>

elapsedMillis timeElapsed, tiempoTemp;
unsigned long tMedida, tAnt;
Adafruit_AHT10 aht;



int i;
int medida;
float frecMuestreo = 30;   // Esto va a ser variable en la INTERFAZ  ========= La máxima es 30 para nMedidas=5
const int nMedidas = 5;  
int listaMedidas[nMedidas] = {};
float suma, v, dAnt, vAnt = 0.0;
int nOutliers = 1;   //// Esto va a haber que ajustarlo para q sea un % < a mayor nMedidas
float d, a;
int primerTemp = 1;
float velSon;
sensors_event_t humidity, temp;


void sort(int a[], int size) {          // Función de ordenamiento tipo Bubble
    for(int i=0; i<(size-1); i++) {
        for(int o=0; o<(size-(i+1)); o++) {
                if(a[o] > a[o+1]) {
                    int holder = a[o];
                    a[o] = a[o+1];
                    a[o+1] = holder;
                }
        }
    }
}

void setup(){
  Serial.begin(9600);
  
  pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  timeElapsed = 0;
  if (! aht.begin()) {
    Serial.println("Could not find AHT10? Check wiring");
    while (1) delay(10);
  }
  //Serial.println("TOF,Distancia,Temp,Humed");
  delay(1000);  // Para prevenir errores
  timeElapsed=0;
}



void loop() {

  elapsedMillis medicion;
  medicion=0;

  //unsigned long lasttime = millis();   Iniciando timer para ver cuánto tiempo tarda una medida promediada
 
  

     for(int i =1; i <= nMedidas; i++){     // Cuántas mediciones queremos promediar
      digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/
      delayMicroseconds(10);
      
      digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
      delayMicroseconds(10);
      
      
      medida = pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante.
      Mide el tiempo que transcurrido entre el envío del pulso ultrasónico y cuando el
      sensor recibe el rebote, es decir: desde que el pin 8 empieza a recibir el rebote,
      HIGH, hasta que deja de hacerlo, LOW, la longitud del pulso entrante*/
      
      listaMedidas[i] = medida;   // Agregamos medida individual a la lista de medidas
      
      //Serial.println(medida);   // Nos muestra las medidas individuales
      
      }
      tMedida=(long)timeElapsed;



      sort(listaMedidas,nMedidas);   // Ordenamos lista 
      
      
      
      QList<int> listaSmart;      // Pasamos lista a Qlist
      for(int i =1; i < nMedidas; i++){
        listaSmart.push_back(listaMedidas[i]);
      }
      
      
      
      
      for(int i =1; i < nOutliers; i++){   // Sacamos primeros outliers
        listaSmart.pop_front();
      }
       
      for(int i =1; i < nOutliers; i++){   // Sacamos ultimos outliers
        listaSmart.pop_back();
      }
      
      /*
      Serial.println("Ordenadas y sin outliers: ");
      for(i =1; i <= listaSmart.size(); i++){  
        Serial.println(listaSmart.at(i));
      }
      */
      
      // CALCULEMOS MEDIA
      for(int i =1; i <= listaSmart.size(); i++){  
        suma += listaSmart.at(i);
      }
      float tof = suma/listaSmart.size()/2000000;
      suma=0;
      
      
      
      if (tiempoTemp >=60000 || primerTemp == 1) {
        aht.getEvent(&humidity, &temp);  //Leer sensor Temp y humedad
        tiempoTemp=0;
        primerTemp=0;  
      }
      
      
      
      velSon=331.67*sqrt((temp.temperature+273.15)/273.15);
      d=velSon*(tof+0.0000603491);
      v=(d-dAnt)/((tMedida-tAnt)/1000.0);
      a=(v-vAnt)/((tMedida-tAnt)/1000.0);
      
      Serial.print(timeElapsed/1000.0,7);
      Serial.print(",");
      Serial.println(d,5);
      //Serial.print(",");
      //Serial.print(v,7);
      //Serial.print(",");
      //Serial.println(a,7);
      dAnt=d;
      vAnt=v;
      tAnt=(long)tMedida;
      
      while (medicion/1000.0   < 1.0/frecMuestreo) {
          
          }

}

  
