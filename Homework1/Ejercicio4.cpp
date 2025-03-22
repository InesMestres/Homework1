#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <memory>
#include <math.h>
using namespace std;

//Ejercicio 4

//Parte a:

/*Funcion recursiva que compara dos variables de texto e indica mediante bool si son iguales
Parametros:
texto1(char): texto para comparar
texto2(char): texto para comparar
i(int): numero
Retorna: True/False*/

bool son_iguales(const char* texto1, const char* texto2, int i = 0){
    if(texto1[i] == '\0' && texto2[i] == '\0'){return true;}
    if(texto1[i] != texto2[i]){return false;}
    return son_iguales(texto1, texto2, i+1);
}

/*Elección de usar char: Permite que la funcion sea evaluada en tiempo de compilación ya que usa memoria estatica (string usa dinamica).*/


//Parte b:


/*Funcion recursiva que compara dos variables de texto e indica mediante bool si son iguales
Parametros:
texto1(char): texto para comparar
texto2(char): texto para comparar
i(int): numero
Retorna: True/False*/

constexpr bool son_iguales_constexpr(const char* texto1, const char* texto2, int i = 0){
    if(texto1[i] == '\0' && texto2[i] == '\0'){return true;}
    if(texto1[i] != texto2[i]){return false;}
    return son_iguales_constexpr(texto1, texto2, i+1);
}

#include <chrono>

int main(){   

const char* texto1 = "Este texto deberia tener mas de sesenta y cuatro caracteres en total.";
const char* texto2 = "Este texto deberia tener mas de sesenta y cuatro caracteres en total.";

//mido tiempo de ejecucion de son_iguales:
auto startTime1 = std::chrono::high_resolution_clock::now();
bool resultado1 = son_iguales(texto1, texto2);
auto endTime1 = std::chrono::high_resolution_clock::now();
auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime1 - startTime1);
std:: cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << "nanosegundos" << std::endl;
cout << "¿Los textos son iguales?" << (resultado1 ? "si" : "no") << endl;


//mido tiempo de ejecución de evaluacion contexpr
constexpr bool resultado2 = son_iguales_constexpr("Este texto deberia tener mas de sesenta y cuatro caracteres en total.", "Este texto deberia tener mas de sesenta y cuatro caracteres en total.");
auto startTime2 = std::chrono::high_resolution_clock::now();
volatile bool copia = resultado2;
auto endTime2 = std::chrono::high_resolution_clock::now();
auto elapsedTime2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2);
std::cout << "A miProcesoAMedir le tomó: " << elapsedTime2.count() << "nanosegundos" << std::endl;
cout << "¿Los textos son iguales? " << (copia ? "Sí" : "No") << endl;


return 0;
}

/* Comentario: En este ejercicio se modifica la comparasión de textos para evaluar el tiempo de ejecución y luego el de compliación. 
Ambos tiempos me dan iguales, lo cual creo que se debe a un tiempo mínimo.
Sé que debería dar mayor el tiempo de ejecución porque debe recorrer caracter por caracter, mientras que el de compilación no. */