#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <memory>
#include <math.h>
using namespace std;


/*2. En muchos sistemas, es importante registrar todo lo que sucede mientras están en funcionamiento. Para ello, se 
utiliza un sistema de log que almacena los eventos relevantes. Cada evento recibe una etiqueta que indica su nivel de 
importancia o gravedad. Las etiquetas más comunes son: DEBUG, INFO, WARNING, ERROR y CRITICAL.

a. En este ejercicio, se pide crear un sistema log que permite agregar entradas a un archivo mediante el llamado a una 
función logMessage definida en pseudo código de la siguiente manera:
void logMessage(String mensaje, Integer/Otro NivelSeveridad)
Donde NivelSeveridad corresponderá con unas de las leyendas previamente mencionadas. 
El formato esperado en una línea del archivo de log es el siguiente:
[ERROR] <Mensaje>
[INFO] <Mensaje>
etc.
Verifique su funcionamiento con al menos una entrada de cada tipo.
*/

void logMessage(string mensaje, int NivelSeveridad){

    if(NivelSeveridad >= 1 && NivelSeveridad <= 5){
        vector<string> mensajes_posibles = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};
        
        ofstream logFile("log.txt", ios::app);
        if (logFile.is_open()){
            logFile << "[" << mensajes_posibles[NivelSeveridad - 1] << "]" << mensaje << endl; 
            logFile.close();
            return;
        }
    }
    else{return;}
}

/*b. En un proyecto usualmente se solicitan cambios para mejorar o agregar funcionalidad. Para el caso del código del 
ejercicio 2.a, se requiere tener la habilidad de agregar mensajes personalizados para registrar otro tipo de eventos. 
Los requisitos son los siguientes:
i. Todos los nuevos mensajes deben ser invocados con logMessage.
ii. Se requiere la posibilidad de registrar errores, indicando el mensaje de error, el archivo y la línea de código 
donde sucedió este error, es decir:

logMessage(String Mensage_de_Error, String Archivo, Int Línea_de_Código)

iii. Se requiere la posibilidad de registrar un mensaje de “Acceso de Usuario” a la
aplicación. Este mensaje debe tener una leyenda nueva: [SECURITY]. La misma
debe ser ingresada de la siguiente manera:

logMessage(String Mensaje_De_Acceso, String Nombre_de_Usuario)

Los mensajes de acceso pueden ser: Access Granted, Access Denied, etc.
iv. Se requiere un código que pruebe que el sistema verifica la funcionalidad
requerida y que además demuestre que puede capturar un error en runtime,
crear una entrada en el log y después detener la ejecución del programa y salir
del mismo con un código de error (return 1)*/

void logMessage(string mensaje, string archivo, int linea_codigo){
    ofstream logFile("log.txt", ios::app);
    if (logFile.is_open()){
        if(!mensaje.empty()){
            logFile << "[ERROR] " << mensaje << endl;
        }
        if(!archivo.empty()){
            logFile << ";" << archivo << endl;
        }
        logFile << ";" << linea_codigo << endl;
        logFile.close();
        return; }
    else{return;}
}   

void logMessage(string mensaje_de_acceso, string nombre_de_usuario){
    
    ofstream logFile("log.txt", ios::app);
    if(logFile.is_open()){
        logFile << "[SECURITY] " << mensaje_de_acceso << "; usuario: " << nombre_de_usuario << endl;
    }

}

//Ejercicio2 parte4:
int captura_error(){ 
    try{
        int x = -100;
        if(x < 0){
            throw "raiz de numero negativo";
        }
        int raiz_x = sqrt(x);
        cout << "El resultado es" << raiz_x << endl;
    }
    catch(const char* e){
        cout << "Error." << endl;
        logMessage((string)e, 4);
        return 1;
    }
    return 0; 
}


int main(){
    //Ejercicio a:
    logMessage("Se hace un debug", 1);
    logMessage("Busqueda de información", 2);
    logMessage("Warning de codigo", 3);
    logMessage("Error de código", 4);
    logMessage("Critical error de código", 5);

    //Ejercicio b, parte1: :
    logMessage("Soy un string de mensaje personalizado", "archivo.txt", 10);

    //Ejercicio b, parte2:
    logMessage("Soy un string de acceso de usuario", "ines_mestres");
    captura_error();
    return 0;
}