#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <memory>
#include <math.h>
using namespace std;

//Ejercicio 2

//Parte a 

/*Devuelve un mensaje con un titulo de evento.
Parametros: 
Mensaje(string): mensaje que describe evento
NivelSeveridad(int): numero que describe gravedad del evento.
Retorna: mensaje con formato: [titulo] <Mensaje>
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

//Parte b

//i.

/*Devuelve un mensaje de error personalizado con informacion del archivo y la linea donde ocurre el error. 
Parametros: 
Mensaje(string): mensaje que describe error
archivo(string): archivo donde ocurre evento.
Linea(int): linea donde ocurre error.
Retorna: mensaje de error, archivo donde ocurre, linea donde ocurre
*/

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

//ii.
/*
/*Genera mensaje de acceso con del usuario que quiere dicho acceso
Parametros: mensaje de acceso (string)
Nombre_de_usuario(string): nombre del usuario a ingresar
Retorna: mensaje y nombre del usuario */

void logMessage(string mensaje_de_acceso, string nombre_de_usuario){
    
    ofstream logFile("log.txt", ios::app);
    if(logFile.is_open()){
        logFile << "[SECURITY] " << mensaje_de_acceso << "; usuario: " << nombre_de_usuario << endl;
    }

}

//iii.
/*Se captura un error en runtime para demostrar
Parametros: -
Retorna: conclusión de que es un error una raiz negativa.
*/

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

    //Demostración de que captura error en runtime: 
    captura_error();
    return 0;
}