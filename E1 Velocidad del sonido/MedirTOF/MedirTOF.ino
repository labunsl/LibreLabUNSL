#include <elapsedMillis.h>
#include "QList.h"
#include <Adafruit_AHT10.h>

Adafruit_AHT10 aht;


elapsedMillis timeElapsed;
int i;
int medida;
const int nMedidas = 100;
int listaMedidas[nMedidas] = {};
float suma = 0.0;
int nOutliers = nMedidas/15;   //// Esto va a haber que ajustarlo para q sea un % < a mayor nMedidas


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
  delay(500);  // Para prevenir errores
  pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
  timeElapsed = 0;
  if (! aht.begin()) {
    Serial.println("Could not find AHT10? Check wiring");
    while (1) delay(10);
  }
  //Serial.println("TOF,Distancia,Temp,Humed");
}





void loop(){

 for(i =1; i <= nMedidas; i++){     // Cuántas mediciones queremos promediar
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
 

  delay(30);
}

sort(listaMedidas,nMedidas);   // Ordenamos lista 



QList<int> listaSmart;      // Pasamos lista a Qlist
for(i =1; i < nMedidas; i++){
  listaSmart.push_back(listaMedidas[i]);
}




for(i =1; i < nOutliers; i++){   // Sacamos primeros outliers
  listaSmart.pop_front();
}
 
for(i =1; i < nOutliers; i++){   // Sacamos ultimos outliers
  listaSmart.pop_back();
}

/*
Serial.println("Ordenadas y sin outliers: ");
for(i =1; i <= listaSmart.size(); i++){  
  Serial.println(listaSmart.at(i));
}
*/

// CALCULEMOS MEDIA
for(i =1; i <= listaSmart.size(); i++){  
  suma += listaSmart.at(i);
}
float tof = suma/listaSmart.size()/2000000;

sensors_event_t humidity, temp;
aht.getEvent(&humidity, &temp);  //Leer sensor Temp y humedad

//Serial.print("Media: ");
Serial.print(tof,8);
Serial.print(",");
Serial.print(1);  //distancia
Serial.print(",");
Serial.print(temp.temperature);
Serial.print(",");
Serial.println(humidity.relative_humidity);
suma=0;



//while(1){};


delay(5000);
}
  
