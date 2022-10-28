#ifndef SERIALCLASS_H_INCLUDED
#define SERIALCLASS_H_INCLUDED

#define ARDUINO_WAIT_TIME 2000

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

class Serial
{
    private:
        //Serial comm handler
        HANDLE hSerial;
        //Connection status
        bool connected;
        //Get various information about the connection
        COMSTAT status;
        //Keep track of last error
        DWORD errors;

        std::vector<std::string> vecSensores;

    public:
        //Initialize Serial
        Serial();
        
        //Close the connection
        //NOTA: for some reason you can'time connect again before exiting
        //the program and running it again
        ~Serial();
        //Initialize Serial communication with the given COM port
        int conectar(char* portName);
        //Read data in a buffer, if nbChar is greater than the
        //maximum number of bytes available, it will return only the
        //bytes available. The function return -1 when nothing could
        //be read, the number of bytes actually read.
        int leerDatos(char *buffer, unsigned int nbChar);
        //Writes data from a buffer through the Serial connection
        //return true on success.
        bool escribirDatos(char *buffer, unsigned int nbChar);
        //Check if we are actually connected
        bool estaConectado();

        void addSensor(std::string nuevoSensor);
        int getSensorNum();
        std::vector<std::string> getVecSensores();
};

#endif // SERIALCLASS_H_INCLUDED