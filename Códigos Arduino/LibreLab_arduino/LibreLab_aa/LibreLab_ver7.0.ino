////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
///
/// *** "FIRMWARE" Arduino para proyecto LibreLab ***
///                 Version 7.0
/// Cambios:  
///     - corregido un error en el parsing de los comandos que devolvia error 256 (faltaba un else)
///     - agregado nuevo sensor id7 (posicion ultrasonico HC-SR04) (por ahora, si el pulso se desborda, repite el ultimo dato valido como solucion)
///
/// Tareas a hacer:
///     - agregar la posibilidad de tener datos invalidos (ahora siempre tiene que haber un dato cuando muestrea)
///
///
///
/// Soporta actualmente hasta dos sensores (se puede ampliar):
///
///       - Ahora se usa millis() como cronometro
///
///       - Comandos: SetX,ID,modo,periodo    Setea en tipo, modo y periodo de muestreo para cada sensor
///                   GetX                    Realiza una medicion del sensor X
///                   Stop                    Detiene todos los muestreos periodicos en curso
///                   Millis                  Devuelve el valor actual en milisegundos del cronometro interno de Arduino
///                   Stopint                 Detiene todas las interrupciones activas
///                   IntY,modoint            Activa alguna de las interrupciones por flanco
///
///         donde X=sensor (1,2), ID=tipo (ver tabla), modo=0:manual,1:periodico, periodo=en milisegundos, 
///               Y=entrada de interrupcion (0,1), modoint=rising, falling, change
///
///       - Sensores: ver .doc adjunto para lista de sensores, caracteristicas y wiring de cada uno de ellos
///
/// 
/// MENSAJES:  
/// 
///   millis,X;               // X: cronometo interno en milisegundos
///   error,comando,X;        // X: codigo de error
///   1,X;                    // X: medida en punto flotante
///   2,X;                    // X: medida en punto flotante
///   error,sensor1;   
///   error,sensor2;
///   int0,X;                 // X: cronometro interno en milisegundos en el momento de la interrupcion
///   int1,X;                 // X: cronometro interno en milisegundos en el momento de la interrupcion
///
///
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////


typedef double flt;

#define newline 0



////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION DE LIBRERIAS, DEFINICION DE PINES E INSTANCIACION DE OBJETOS
////////////////////////////////////////////////////////////////////////////////////////////

/// Para sensores 1-wire tipo ds18s20
#include <OneWire.h>
#include <DallasTemperature.h>
#define Pin_1w 2
OneWire ourWire(Pin_1w);
DallasTemperature sensors1w(&ourWire);

/// Para termocupla tipo K
#include <max6675.h>  // max6675.h file is part of the library that you should download from Robojax.com
#define Pin_so 4       // SO=Serial Out
#define Pin_cs 5       // CS = chip select CS pin
#define Pin_sck 6      // SCK = Serial Clock pin
MAX6675 Module(Pin_sck, Pin_cs, Pin_so);   // create instance object of MAX6675

/// Para sensor presion/temperatura BMP180
#include <SFE_BMP180.h>
#include <Wire.h>
SFE_BMP180 bmp180;  // pines predeterminados son A4 y A5

/// Para sensor chino humedad/temperatura DHT11
#include <DHT.h>
#define Pin_DHT 2
#define Type_DHT DHT11 
DHT dht(Pin_DHT, Type_DHT);

/// Para sensor presion 0-40kPa con HX710
#include <Q2HX711.h>
#define Pin_DOUT 7
#define Pin_SCLK 8
Q2HX711 MPS20N0040D(Pin_DOUT,Pin_SCLK);

/// Para sensor de posicion (ultrasonico) HC-SR04
#define PIN_Trig  9
#define PIN_Echo  10


////////////////////////////////////////////////////////////////////////////////////////////
/// ASIGNACION DE PINES (BASADO EN ARDUINO UNO)
////////////////////////////////////////////////////////////////////////////////////////////
///
/// A0  entrada analógica
/// A1
/// A2
/// A3
/// A4  bmp180
/// A5  bmp180
/// 
/// 0   RX
/// 1   TX
/// 2   entrada digital (interrupción externa #0)
/// 3   entrada digital (interrupción externa #1)
/// 4   max6675
/// 5   max6675
/// 6   max6675
/// 7   hx711
/// 8   hx711
/// 9   HC-SR04 (trig)
/// 10  HC-SR04 (echo)
/// 11  salida digital (PWM)
/// 12  1-wire
/// 13  dht11













///////////////////////////////////////////////////////////////////////////////////////////
/// VARIABLES GLOBALES ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

int cont;

int error;

// Comunicacion
String bufferEnt;
String param;
flt datoActual;

// int es de 16 bits, long int es de 32 bits
long int millis_sensor1,periodo_sensor1;
char modo_sensor1,leer_sensor1,id_sensor1;

long int millis_sensor2,periodo_sensor2;
char modo_sensor2,leer_sensor2,id_sensor2;

long int millis_actual;

// volatile ya que puede ser modificado en cualquier momento por las ISR...
volatile long int millis_int0;  
volatile long int millis_int1;
volatile char event_int0;
volatile char event_int1;


flt udv=0;    // ultimo dato valido


///////////////////////////////////////////////////////////////////////////////////////////
/// EL SETUP
///////////////////////////////////////////////////////////////////////////////////////////
void setup() 
{
 
  delay(1000);
  Serial.begin(9600);
  sensors1w.begin();                     // se inician los sensores 1-wire
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Iniciando LibreLab...");
  dht.begin();
  bmp180.begin();
  pinMode(9,INPUT);
  
  millis_sensor1=millis_sensor2=millis();

  pinMode(9, OUTPUT);                     // para el sensor ultrasonico!!!
  udv=0;                                  // "ultimo dato valido" filtro rudimentario...

  modo_sensor1=modo_sensor2=0;            // inicialmente en modo manual
  periodo_sensor1=2000000L;
  periodo_sensor2=250000L;
  id_sensor1=0;
  id_sensor2=2;
  error=0;
}



///////////////////////////////////////////////////////////////////////////////////////////
/// LEE SENSOR
///////////////////////////////////////////////////////////////////////////////////////////
flt lee_sensor(char id)
{
  flt a,aa;
  int s;

  switch(id)
  {
    case 0:   error=0;
              a=Module.readCelsius(); break;  // lee termocupla K

    case 1:   error=1;
              s=bmp180.startTemperature();    // inicio lectura temperatura BMP180
              if(s)
              {   
                delay(s*2);                     // pausa para que finalice la lectura
                s=bmp180.getTemperature(a);   // obtener la temperatura BMP180
                if(s) error=0;
              }
              break;
    
    case 2:   error=1;
              s=bmp180.startTemperature();    // inicio lectura temperatura BMP180
              if(s)
              {   
                delay(s);                     // pausa para que finalice la lectura
                s=bmp180.getTemperature(aa);  // obtener la temperatura BMP180
                if(s) error=0;
              }
              if(error) break;
              s=bmp180.startPressure(3);      // inicio lectura de presión BMP180
              if(s)
              {        
                delay(s);                     // pausa para que finalice la lectura        
                s=bmp180.getPressure(a,aa);    // obtenemos la presión (aa debe ser una lectura previa de temperatura)
                if(s) error=0;
              }
              break;
              
    case 3:   error=0;
              sensors1w.requestTemperatures();  // se envía el comando para leer la temperatura
              a=sensors1w.getTempCByIndex(0);   // se obtiene la temperatura en ºC
              break;

    case 4:   a=dht.readTemperature();
              error=isnan(a);
              break;

    case 5:   a=dht.readHumidity();
              error=isnan(a);
              break;

    case 6:   a=(flt)MPS20N0040D.read();  // obtiene datos raw
              // a=29.5*(a/429496704.0-22.6)/50.0;    // supuestamente con esto quedaria en kPa 
                                                      // pero no da..
                                                      // ver (https://makersportal.com/blog/2020/6/4/mps20n0040d-pressure-sensor-calibration-with-arduino)
              error=0;
              break;

    case 7:   digitalWrite(PIN_Trig, HIGH);
              delayMicroseconds(10);          //Enviamos un pulso de 10us
              digitalWrite(PIN_Trig, LOW);
              aa=(flt)pulseIn(PIN_Echo, HIGH); //obtenemos el ancho del pulso
              if(aa>50000) a=udv; else a=udv=aa;  // si es menor de 50000 lo considera valido (solucion provisoria...)
              error=0;
              break;
    

    
    default:  error=1;
              break;
  }
  return a;
}




///////////////////////////////////////////////////////////////////////////////////////////
/// Rutinas de servicio de interrupciones externas
///////////////////////////////////////////////////////////////////////////////////////////
void ISR_int0(void) { millis_int0=millis(); event_int0=1; }   // pin 2, entrada de interrupcion externa 0
void ISR_int1(void) { millis_int1=millis(); event_int1=1; }   // pin 3, entrada de interrupcion externa 1






///////////////////////////////////////////////////////////////////////////////////////////
/// EL LOOP
///////////////////////////////////////////////////////////////////////////////////////////
void loop() 
{
  int i,param1,param2,param3;
  long int param4;
  
/// *** LEE SERIAL Y PROCESA COMANDOS ***

  if (Serial.available()) {

    String bufferEnt = Serial.readStringUntil('\n');

// Seteo el ID, el modo (manual o periodico) y el periodo, para los sensores #1 o #2
// sintaxis: SetX,ID,MODO,MILLIS
// X:  1,2 (# de sensor)
// ID: 0..7 (tipo de sensor)
// MODO: 0 (manual), 1 (periodico)
// MILLIS: T en milisegundos, para el caso periodico
// ejemplo: Set1,0,1,250000
//

    if (bufferEnt.indexOf("Set") == 0)
    {
      error=0;
      bufferEnt.remove(0,3);

      // lee los cuatro parametros separados por coma...
      i=bufferEnt.indexOf(",");
      if(i>0)
      {
        param=bufferEnt;
        param.remove(i);
        bufferEnt.remove(0,i+1);
        param1=(int)param.toInt();      
      } else error+=1;

      i=bufferEnt.indexOf(",");
      if(i>0)
      {
        param=bufferEnt;
        param.remove(i);
        bufferEnt.remove(0,i+1);
        param2=(int)param.toInt();      
      } else error+=2;

      i=bufferEnt.indexOf(",");
      if(i>0)
      {
        param=bufferEnt;
        param.remove(i);
        bufferEnt.remove(0,i+1);
        param3=(int)param.toInt();      
      } else error+=4;

      param4=bufferEnt.toInt();      

      // hace un control basico de los rangos de los parametros
      // y si no hay errores toma los nuevos valores...
      if(!error)
      {
        if((param1<1) || (param1>2)) error+=8;      // numero de sensor (1 o 2)
        if((param2<0) || (param2>7)) error+=16;     // controla rango de ID
        if((param3<0) || (param3>1)) error+=32;     // modo puede ser 0 o 1
        if(param4<0L) error+=64;                    // periodo no negativo
        if((param3==1) && (param4==0L)) error+=128; // periodo mayor que 0

        if(!error && (param1==1))
        {
          id_sensor1=param2;
          modo_sensor1=param3;
          periodo_sensor1=param4;
        }

        if(!error && (param1==2))
        {
          id_sensor2=param2;
          modo_sensor2=param3;
          periodo_sensor2=param4;
        }

      }
   
    } else

// Obtiene una medicion segun el ID asociado al sensor #1 o #2
// sintaxis: GetX
// X:  1,2 (sensor)
// ejemplo: Get2
//
    if(bufferEnt.indexOf("Get1")==0) leer_sensor1=1; else
    if(bufferEnt.indexOf("Get2")==0) leer_sensor2=1; else

// Obtiene valor actual del cronometro Arduino en milisegundos
    if(bufferEnt.indexOf("Millis")==0)
    {
      Serial.print("millis,"); 
      Serial.print((flt)millis()); 
      Serial.print(";");                // millis,X;
#if newline
      Serial.println();
#endif
    } else

// Detiene todos los modos periódicos activos
    if(bufferEnt.indexOf("Stop")==0) modo_sensor1=modo_sensor2=0; else
     
// Detiene todas las interrupciones
    if(bufferEnt.indexOf("Stopint")==0) { detachInterrupt(digitalPinToInterrupt(2)); detachInterrupt(digitalPinToInterrupt(3)); } else

// Habilita interrupcion sobre int0 RISING 
    if(bufferEnt.indexOf("Int0,rising")==0)  { event_int0=0; attachInterrupt(digitalPinToInterrupt(2),ISR_int0,RISING); } else
// Habilita interrupcion sobre int0 FALLING
    if(bufferEnt.indexOf("Int0,falling")==0) { event_int0=0; attachInterrupt(digitalPinToInterrupt(2),ISR_int0,FALLING); } else
// Habilita interrupcion sobre int0 CHANGE
    if(bufferEnt.indexOf("Int0,change")==0)  { event_int0=0; attachInterrupt(digitalPinToInterrupt(2),ISR_int0,CHANGE); } else

// Habilita interrupcion sobre int1 RISING 
    if(bufferEnt.indexOf("Int1,rising")==0)  { event_int1=0; attachInterrupt(digitalPinToInterrupt(3),ISR_int1,RISING); } else
// Habilita interrupcion sobre int1 FALLING
    if(bufferEnt.indexOf("Int1,falling")==0) { event_int1=0; attachInterrupt(digitalPinToInterrupt(3),ISR_int1,FALLING); } else
// Habilita interrupcion sobre int1 CHANGE
    if(bufferEnt.indexOf("Int1,change")==0)  { event_int1=0; attachInterrupt(digitalPinToInterrupt(3),ISR_int1,CHANGE); } 

    else error+=256;


    if(error) 
    {
      Serial.print("error,comando,"); 
      Serial.print((int)error); 
      Serial.print(";");                // error,comando,X;
#if newline
      Serial.println();
#endif
    }

  }


/// *** ENVIA SERIAL MEDICIONES Y OTROS MENSAJES (ERRORES, INTERRUPCIONES, CRONOMETO, ETC.) ***


   millis_actual=millis();
   if(((millis_actual>millis_sensor1) && (modo_sensor1)) || (leer_sensor1))
   { 
    millis_sensor1=millis_actual+periodo_sensor1;
//    millis_sensor1=millis_sensor1+periodo_sensor1;  // esto debería andar mejor...
    
    datoActual=lee_sensor(id_sensor1);
    Serial.print("1,");
    Serial.print(datoActual); 
    Serial.print(';');                    // 1,X;
#if newline
    Serial.println();
#endif
    leer_sensor1=0;
    if(error)
    {
      Serial.print("error,sensor1;");     // error,sensor1;
#if newline
      Serial.println();
#endif
    }
   }


   millis_actual=millis();
   if(((millis_actual>millis_sensor2) && (modo_sensor2)) || (leer_sensor2))
   { 
    millis_sensor2=millis_actual+periodo_sensor2;
//    millis_sensor2=millis_sensor2+periodo_sensor2;  // esto debería andar mejor...

    datoActual=lee_sensor(id_sensor2);
    Serial.print("2,");
    Serial.print(datoActual); 
    Serial.print(';');                      // 2,X;
#if newline
    Serial.println();
#endif
    leer_sensor2=0;
    if(error)
    {
      Serial.print("error,sensor2;");       // error,sensor2;
#if newline
      Serial.println();
#endif
    }
 
   }

  if(event_int0)
  {
      event_int0=0;
      Serial.print("int0,"); 
      Serial.print((flt)millis_int0); 
      Serial.print(";");                  // int0,X;
#if newline
      Serial.println();
#endif
  }

  if(event_int1)
  {
      event_int1=0;
      Serial.print("int1,"); 
      Serial.print((flt)millis_int1); 
      Serial.print(";");                  // int1,X;
#if newline
      Serial.println();
#endif
  }

  
//  Serial.flush();

//  delay(500);
 
}
