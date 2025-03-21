#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <memory>
#include <math.h>
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