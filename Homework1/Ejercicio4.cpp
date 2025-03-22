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
auto startTime = std::chrono::high_resolution_clock::now();
bool resultado = son_iguales(texto1, texto2);
auto endTime = std::chrono::high_resolution_clock::now();
auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << "nanosegundos" << std::endl;

//mido tiempo de ejecución de 
constexpr bool resultado2 = son_iguales_constexpr("Este texto deberia tener mas de sesenta y cuatro caracteres en total.", "Este texto deberia tener mas de sesenta y cuatro caracteres en total.");
auto startTime2 = std::chrono::high_resolution_clock::now();
auto endTime2 = std::chrono::high_resolution_clock::now();
auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime2 - startTime2);
std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << "nanosegundos" << std::endl;

return 0;
}


/*c. Modifique el código del ejercicio 4.1 para que la comparación de los textos se
realice en tiempo de compilación y obtenga el tiempo de ejecución. Compare
este tiempo con el obtenido en el ejercicio 4.2 y justifique brevemente la
diferencia (puede escribir su conclusión como un comentario al final del código
de este item).*/
