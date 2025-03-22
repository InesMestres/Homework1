#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <memory>
#include <math.h>
using namespace std;

//Ejercicio 3

struct nodo{
    int valor;
    nodo* siguiente;
};

/*Devuelve un nuevo nodo.
Parametro: valor_nodo: valor que le damos al nodo
Retorna nodo*/
nodo* create_node(int valor_nodo){
    nodo* nuevo_nodo = new nodo;
    nuevo_nodo -> valor = valor_nodo;
    nuevo_nodo  -> siguiente = nullptr;
    return nuevo_nodo;
}

/*Inserta un nodo al inicio de la lista
Parametros: head(nodo): puntero a lista, valor_nodo(int): valor asignado al nodo
Retorna: vacio*/
void push_front(nodo*& head, int valor_nodo){
    nodo* nuevo_nodo = create_node(valor_nodo);
    nuevo_nodo -> siguiente = head;
    head = nuevo_nodo;
    return;
}

/*Inserta un nodo al final
Parametros: head(nodo): puntero a lista, valor_nodo(int): valor asignado al nodo
Retorna:*/
void push_back(nodo*& head, int valor_nodo){
    nodo* nuevo_nodo = create_node(valor_nodo);

    if (head == nullptr){
        head = nuevo_nodo;
        return;
    }
    
    nodo* nodo_temp = head;
    while(nodo_temp -> siguiente != nullptr){
        nodo_temp = nodo_temp -> siguiente;
    }
    nodo_temp -> siguiente = nuevo_nodo;
}


/*Inserta nodo en una posicion indicada
Parametros: 
head(nodo): puntero a lista
posicion(int): numero de posicion dentro de la lista
valor_nodo(int): valor que se le asigna al nodo
Retorna: vacio
*/
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

/*Borra un nodo en na posicion indicada
Parametros: 
head(nodo*): puntero al nodo
posicion(int): posicion en la que se borra el nodo
Retorna vacío
*/
void erase(nodo*& head, int posicion){
        
    if(head == nullptr){
        return;    
    }

    if(posicion == 0){
        nodo* nodo_temp = head;
        head = head -> siguiente;
        delete nodo_temp;
        return;
    }

    nodo* nodo_presente = head;
    int contador = 0;
        
    while(contador < posicion - 1 && nodo_presente != nullptr){
        nodo_presente = nodo_presente -> siguiente; 
         contador++;
    }
    
    if(nodo_presente == nullptr || nodo_presente->siguiente == nullptr){
        cout << "La posicion ingresada es mayor que el tamaño de la lista, por lo tanto eliminamos el ultimo nodo" << endl;
        return;
    }
        
    nodo* nodo_a_borrar = nodo_presente -> siguiente;
    nodo_presente -> siguiente = nodo_a_borrar -> siguiente;
    delete nodo_a_borrar; 
    }

/*Imprime la lista enlazada
Parametros: 
head (nodo*): puntero a la lista
Retorna: vacio*/

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

//Para verificar todas las operaciones: 

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