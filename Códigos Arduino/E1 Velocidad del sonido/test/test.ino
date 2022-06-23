#include <elapsedMillis.h>
#include <Adafruit_AHT10.h>

Adafruit_AHT10 aht;


elapsedMillis timeElapsed;
int i;
float medida;
float tof;
const int nMedidas = 20;
float suma = 0.0;

float dAnt = 0;
float tofAnt = 0;
float vAnt = 0;
float velSon = 0;
float d = 0;

elapsedSeconds tempSegundos;
unsigned int tempIntervalo = 10;  // Tiempo entre mediciones de temperatura

void setup() {
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





void loop() {

  for (i = 1; i <= nMedidas; i++) {  // Cuántas mediciones queremos promediar
    digitalWrite(9, LOW); /* Por cuestión de estabilización del sensor*/
    delayMicroseconds(10);

    digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
    delayMicroseconds(10);


    medida = pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante.
  Mide el tiempo que transcurrido entre el envío del pulso ultrasónico y cuando el
  sensor recibe el rebote, es decir: desde que el pin 8 empieza a recibir el rebote,
  HIGH, hasta que deja de hacerlo, LOW, la longitud del pulso entrante*/

    if (medida >= 300 && medida <= 29000) {
      tof = medida;
    }

    d = 343 * tof/2000000;
    Serial.println(d, 5);

    delay(20);
  }

  
  if (tempSegundos >= tempIntervalo) {
      sensors_event_t humidity, temp;
      aht.getEvent(&humidity, &temp);  //Leer sensor Temp y humedad
      tempSegundos = 0;
  }

  //velSon = 331.29 * sqrt((temp.temperature + 273.15) / 273.15);
  //d = velSon * tof;
  
  //float v = (d-dAnt)/(tof-tofAnt);
  //float a = (v-vAnt)/(tof-tofAnt);

  //Serial.print(",");
  //Serial.print(v);
  //Serial.print(",");
  //Serial.println(a);

  //dAnt = d;
  //tofAnt = tof;
  //vAnt=v;

  //Serial.println(humidity.relative_humidity);
  suma = 0;



  //while(1){};


}
