//HOMEWORK 1

//Para todas las funciones incluir: 
#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <memory>
using namespace std;




/*3. Implemente una lista enlazada que utilice nodos que simplemente contengan un
valor y una dirección de memoria de un nodo. Adicionalmente, agregue las siguientes
funciones para manejar la lista:
i. create_node(): devuelve un nodo.
ii. push_front(): inserta un nodo al frente de la lista.
iii. push_back(): inserta un nodo al final de la lista.
iv. insert(): inserta un nodo en la posición que se le pase a la función. Si se le pasa
una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de
agregar el nodo al final de la lista.
v. erase(): borra un nodo en la posición que se le pase a la función. Similar a la
función insert(), si la posición es mayor que el largo de la lista, se debe de borrar
el último nodo.
vi. print_list(): imprime la lista completa, separando el valor en cada nodo con “->”.
Presentar ejemplos que verifiquen el funcionamiento requerido en las funciones i-vi y,
muy importante para el ejercicio, sólo utilizar smart pointers.*/

struct nodo{
    int valor;
    nodo* siguiente;
};

//devuelve un nodo:
nodo create_node(int valor_nodo){
    nodo* nuevo_nodo = new nodo;
    nuevo_nodo -> valor = valor_nodo;
    nuevo_nodo  -> siguiente = nullptr;
    return *nuevo_nodo;
}

//Inserta un nodo al principio:
void push_front(nodo*& head, int valor_nodo){
    nodo* nuevo_nodo = create_node(valor_nodo);
    nuevo_nodo -> valor = valor_nodo;
    nuevo_nodo -> siguiente = head;
    return;
}

//Inserta al final
void push_back(nodo*& head, int valor_nodo){
    nodo* nuevo_nodo = create_node(valor_nodo);
    nuevo_nodo -> valor = valor_nodo;

    if(nuevo_nodo == nullptr){
        nuevo_nodo = head;
        return;
    }
    else{
        nodo* nodo_temp = head;
        while(nodo_temp != nullptr){
            nodo_temp = nodo_temp -> siguiente;
        }
        nuevo_nodo = nodo_temp;
        return;
    }
}


void insert(node*& head, int posicion, int valor_nodo){

    nodo* nuevo_nodo = create_node(valor_nodo);

    if(posicion == 0 || head == nullptr){
        head = nuevo_nodo;
        return;
    }

    nodo* nodo_temp = head;
    int posicion_nodo = 0;

    while(nodo_temp -> siguiente != nullptr && posicion_nodo < (posicion - 1)){
        nodo_temp = nodo_temp -> siguiente;
        posicion_nodo ++;
    }
    
    nuevo_nodo = nodo_temp;
    return;

}


void erase(int valor_nodo, node*& head, int posicion){
    
    node* nodo_a_borrar = head;
    
    if(head == nullptr){
        return;    
    }

    if(posicion == 0){
        head = head -> siguiente;
        delete nodo_a_borrar;
        return;
    }
    else{
        int contador = 0;
        while(contador < posicion && nodo_a_borrar -> siguiente != nullptr){
            nodo_a_borrar = nodo_a_borrar -> siguiente; 
            contador++;
        }
        if(nodo_a_borrar -> siguiente == nullptr){
            nodo_a_borrar = nodo_a_borrar;
        }
        delete nodo_a_borrar;
        return; 
    }

}

void print_list(nodo*& head){
    if(head == nullptr){return;}
    nodo_presente = head;
    while(nodo_presente != nullptr){
        printf(nodo_presente + "->");
        nodo_presente = nodo_presente -> siguiente;
    }
    cout << NULL << endl;
    return;
}

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