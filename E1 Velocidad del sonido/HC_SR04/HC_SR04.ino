#include <elapsedMillis.h>
#include "QList.h"


elapsedMillis timeElapsed;
int i;
int medida;
const int nMedidas = 200;
int listaMedidas[nMedidas] = {};
float suma = 0;
int nOutliers = nMedidas/20;   //// Esto va a haber que ajustarlo para q sea un % < a mayor nMedidas
float media;

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
}

float calcularSD(float data[], int tamanio, float media) {    // FUNCIÓN DEVIACIÓN ESTANDAR
  float standardDeviation = 0.0;
  int i;

  for(i = 0; i < tamanio; ++i) {
    standardDeviation += pow(data[i] - media, 2);
  }

  return sqrt(standardDeviation / tamanio);
}




void loop(){
 for(i =1; i <= nMedidas; i++){     // Cuántas mediciones queremos promediar
  digitalWrite(9, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(9, HIGH); //Set trigPin high
  delayMicroseconds(10); //Delay in high state
  digitalWrite(9, LOW); //ping has now been sent
  
  medida = pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante.
  Mide el tiempo que transcurrido entre el envío del pulso ultrasónico y cuando el
  sensor recibe el rebote, es decir: desde que el pin 8 empieza a recibir el rebote,
  HIGH, hasta que deja de hacerlo, LOW, la longitud del pulso entrante*/
  
  
  listaMedidas[i] = medida;   // Agregamos medida individual a la lista de medidas
  
  //Serial.println(medida);   // Nos muestra las medidas individuales

  delay(0);
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


float listaLimpia[listaSmart.size()] = {};           // Volvemos a lista normal
for(i =1; i <= listaSmart.size(); i++){                
  listaLimpia[i] = listaSmart.at(i);
}
int tamanio = listaSmart.size();


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

Serial.print("Media: ");
media = suma/listaSmart.size();
Serial.println(media);


// DEVIACIÓN ESTANDAR
Serial.print("Incerteza: ");
Serial.println(calcularSD(listaLimpia, tamanio, media));


//while(1){};
suma=0;
  
}
  
