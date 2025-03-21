//HOMEWORK 1

//Para todas las funciones incluir: 
#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <memory>
using namespace std;

/*1. a. Crear una función que dado un valor entero “n”, positivo y mayor a uno, devuelva
una matriz cuadrada con valores como en los siguientes ejemplos para n=2 y n=3*/

vector<vector<int>> crear_matriz(int n){
    
    vector<vector<int>> matriz(n, vector<int>(n));
    int valor_inicial = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; i++){
             matriz[i][j] = valor_inicial;
             valor_inicial++;
        }
    }
    return matriz;
}

/*
b. Proveer un código que imprima el contenido de la matriz, utilizando un único ciclo
for, desde el mayor valor al menor, es decir, para el ejemplo de Para 𝑀2:
𝑀2[1][1] = 4
𝑀2[1][0] = 3
𝑀2[0][1] = 2
𝑀2[0][0] = 1
Nota: recuerde que se deben imprimir los índices de la matriz.*/

void imprimir_contenidos_matriz(vector<vector<int>> matriz, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("matriz[%d][%d] = %d", i, j, matriz[i][j]);
    }
}
}


/*2. En muchos sistemas, es importante registrar todo lo que sucede mientras están en
funcionamiento. Para ello, se utiliza un sistema de log que almacena los eventos
relevantes. Cada evento recibe una etiqueta que indica su nivel de importancia o
gravedad. Las etiquetas más comunes son: DEBUG, INFO, WARNING, ERROR y
CRITICAL.


a. En este ejercicio, se pide crear un sistema log que permite agregar entradas a un
archivo mediante el llamado a una función logMessage definida en pseudo código de
la siguiente manera:
void logMessage(String mensaje, Integer/Otro NivelSeveridad)
Donde NivelSeveridad corresponderá con unas de las leyendas previamente
mencionadas. El formato esperado en una línea del archivo de log es el siguiente:2
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

/*b. En un proyecto usualmente se solicitan cambios para mejorar o agregar funcionalidad.
Para el caso del código del ejercicio 2.a, se requiere tener la habilidad de agregar
mensajes personalizados para registrar otro tipo de eventos. Los requisitos son los
siguientes:
i. Todos los nuevos mensajes deben ser invocados con logMessage.
ii. Se requiere la posibilidad de registrar errores, indicando el mensaje de error, el
archivo y la línea de código donde sucedió este error, es decir:
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

//nuevos mensajes personalizados con logmessage, registrar errores indicando: 
//logMessage(String Mensage_de_Error, String Archivo, Int Línea_de_Código)
//aplicacion: [security] logMessage(String Mensaje_De_Acceso, String Nombre_de_Usuario)
//mensajes de acesso:  Access Granted, Access Denied, etc.

void logMessage(string mensaje, int NivelSeveridad, string mensajePersonalizado = ""){

    if(NivelSeveridad >= 1 && NivelSeveridad <= 5){
        vector<string> mensajes_posibles = {"DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"};
        
        ofstream logFile("log.txt", ios::app);
        if (logFile.is_open()){
            logFile << "[" << mensajes_posibles[NivelSeveridad - 1] << "]" << mensaje << endl; 
            if(!mensajePersonalizado.empty()){
                logFile << ";" << mensajePersonalizado << endl;
            }
            
            logFile.close();
            return;
        }
    }
    else{return;}
}

void logMessage(string mensaje, string archivo = "", int linea_codigo = 0){
    ofstream logFile("log.txt", ios::app);
    if (logFile.is_open()){
        if(!mensaje.empty()){
            logFile << "[ERROR] " << mensaje << endl;
        }
        if(!archivo.empty()){
            logFile << ";" << archivo << endl;
        }
        if(linea_codigo != NULL){
            logFile << ";" << linea_codigo << endl;
        }
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

main(){
    //funcion parte 1:
    logMessage("Debugging ", 1);
    logMessage("Info ", 2);
    logMessage("Warning ", 3);
    logMessage("Error ", 4);
    logMessage("Critical ", 5);
    //funcion parte 2 con mensaje personalizado:
    logMessage("Debugging ", 1, "Mensaje personalizado");
    //Parte 3 con mensaje, archivo y linea
    logMessage("Hubo un error", "archivo.txt", 98)
    //Parte 4: 
    logMessage("Este es un mensaje de error", "usuario1340");
}

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