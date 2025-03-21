#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <memory>
#include <math.h>
using namespace std;

/*4. Recursión y ejecución en tiempo de compilación:
a. Se requiere el código de una función recursiva que compare dos variables que
contengan texto e indique mediante una variable bool si son iguales (true si son
iguales, false si no lo son). Explique su elección entre los tipos string y char* (lea
el siguiente item de este ejercicio antes de elegir el tipo de variable) y demuestre
la funcionalidad de su código con un texto de, al menos, 64 caracteres.
b. El componente high_resolution_clock de <chrono> permite calcular el tiempo
de ejecución de un proceso al hacer:
#include <chrono>
…
auto startTime = std::chrono::high_resolution_clock::now();
miProcesoAMedir();
auto endTime = std::chrono::high_resolution_clock::now();
auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
endTime - startTime);
std::cout << “A miProcesoAMedir le tomó: “ << elapsedTime.count() << “
nanosegundos” << std::endl;
Utilice esté código y las modificaciones necesarias que crea conveniente para
verificar cuanto tiempo toma la ejecución del código del ejercicio 4.1.
c. Modifique el código del ejercicio 4.1 para que la comparación de los textos se
realice en tiempo de compilación y obtenga el tiempo de ejecución. Compare
este tiempo con el obtenido en el ejercicio 4.2 y justifique brevemente la
diferencia (puede escribir su conclusión como un comentario al final del código
de este item).*/


/*a. Se requiere el código de una función recursiva que compare dos variables que
contengan texto e indique mediante una variable bool si son iguales (true si son
iguales, false si no lo son). Explique su elección entre los tipos string y char* (lea
el siguiente item de este ejercicio antes de elegir el tipo de variable) y demuestre
la funcionalidad de su código con un texto de, al menos, 64 caracteres.*/
bool son_iguales(string texto1, string texto2, int i = 0){
    if(i == texto1.length() && i == texto2.length()){return true;}
    if(i == texto1.length() || i == texto2.length()){return false;}
    if(texto1[i] != texto2[i]){return false;}
    return son_iguales(texto1, texto2, i+1);
}

/*b. El componente high_resolution_clock de <chrono> permite calcular el tiempo
de ejecución de un proceso al hacer:
#include <chrono>
…
auto startTime = std::chrono::high_resolution_clock::now();
miProcesoAMedir();
auto endTime = std::chrono::high_resolution_clock::now();
auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
endTime - startTime);
std::cout << “A miProcesoAMedir le tomó: “ << elapsedTime.count() << “
nanosegundos” << std::endl;
Utilice esté código y las modificaciones necesarias que crea conveniente para
verificar cuanto tiempo toma la ejecución del código del ejercicio 4.1.*/

#include <chrono>

int main(){   
string texto1 = "Esta es una frase corta.";
string texto2 = "Esta es una frase corta.";

auto startTime = std::chrono::high_resolution_clock::now();
bool resultado = son_iguales(texto1, texto2);
auto endTime = std::chrono::high_resolution_clock::now();
auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << "nanosegundos" << std::endl;
return 0;
}


/*c. Modifique el código del ejercicio 4.1 para que la comparación de los textos se
realice en tiempo de compilación y obtenga el tiempo de ejecución. Compare
este tiempo con el obtenido en el ejercicio 4.2 y justifique brevemente la
diferencia (puede escribir su conclusión como un comentario al final del código
de este item).*/

int main(){   
    string texto1 = "Esta es una frase corta.";
    string texto2 = "Esta es una frase corta.";
    
    constexpr bool resultado = son_iguales(texto1, texto2);
    auto startTime = std::chrono::high_resolution_clock::now();
    bool resultado_en_runtime = resultado;
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << "nanosegundos" << std::endl;
    return 0;
    }