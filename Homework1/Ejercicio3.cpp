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
nodo* create_node(int valor_nodo){
    nodo* nuevo_nodo = new nodo;
    nuevo_nodo -> valor = valor_nodo;
    nuevo_nodo  -> siguiente = nullptr;
    return nuevo_nodo;
}

//Inserta un nodo al principio:
void push_front(nodo*& head, int valor_nodo){
    nodo* nuevo_nodo = create_node(valor_nodo);
    nuevo_nodo -> siguiente = head;
    head = nuevo_nodo;
    return;
}

//Inserta al final
void push_back(nodo*& head, int valor_nodo){
    nodo* nuevo_nodo = create_node(valor_nodo);

    if (head == nullptr){
        head = nuevo_nodo;
        return;
    }
    
    nodo* nodo_temp = head;
    while(nodo_temp != nullptr){
        nodo_temp = nodo_temp -> siguiente;
    }
    nuevo_nodo = nodo_temp;
    return;
}



void insert(nodo*& head, int posicion, int valor_nodo){

    nodo* nuevo_nodo = create_node(valor_nodo);

    if(posicion == 0 || head == nullptr){
        nuevo_nodo -> siguiente = head;
        head = nuevo_nodo;
        return;
    }

    nodo* nodo_temp = head;
    int posicion_nodo = 0;

    while(nodo_temp -> siguiente != nullptr && posicion_nodo < (posicion - 1)){
        nodo_temp = nodo_temp -> siguiente;
        posicion_nodo ++;
    }
    
    nuevo_nodo -> siguiente = nodo_temp -> siguiente;
    nodo_temp -> siguiente = nuevo_nodo;
    return;

}



void erase(nodo*& head, int posicion){
        
    if(head == nullptr){
        return;    
    }

    nodo* nodo_a_borrar = head;

    if(posicion == 0){
        head = head -> siguiente;
        delete nodo_a_borrar;
        return;
    }

    nodo* prev = nullptr;
    int contador = 0;
        
    while(contador < posicion && nodo_a_borrar != nullptr){
        prev = nodo_a_borrar;
        nodo_a_borrar = nodo_a_borrar -> siguiente; 
         contador++;
    }
    
    if(nodo_a_borrar == nullptr){
        cout << "La posicion ingresada es mayor que el tamaño de la lista, por lo tanto eliminamos el ultimo nodo" << endl;
        return;
    }
        
    prev -> siguiente = nodo_a_borrar -> siguiente;
    delete nodo_a_borrar; 
    }



void print_list(nodo*& head){
    if(head == nullptr){
        cout<<"lista vacia" << endl;
        return;
    }
    nodo* nodo_presente = head;
    while(nodo_presente != nullptr){
        cout << nodo_presente->valor << "->";
        nodo_presente = nodo_presente -> siguiente;
    }
    cout << "NULL" << endl;
    return;
}

int main(){
    nodo* nodo1 = nullptr;
    push_front(nodo1, 3);
    push_front(nodo1, 2);
    push_front(nodo1, 1);

    push_back(nodo1, 4);
    push_back(nodo1, 5);

    insert(nodo1, 2, 99);

    print_list(nodo1);

    erase (nodo1, 3);

    print_list(nodo1);

    return 0;
}