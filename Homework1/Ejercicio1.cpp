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
        for(int j = 0; j < n; j++){
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
    for(int i = n*n - 1; i >= 0; i--){
        int fila =(i/n);
        int columna =(i%n);
        printf("matriz[%d][%d] = %d", fila, columna, matriz[fila][columna]);
    }
}

int main(){
    vector<vector<int>> matriz = crear_matriz(3);
    imprimir_contenidos_matriz(matriz);
    return 0;
}