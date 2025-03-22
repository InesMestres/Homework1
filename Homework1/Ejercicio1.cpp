#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include <memory>
using namespace std;

//Ejercicio 1

//Parte a

/*Devuelve una matriz cuadrada de n*n lados
Parametro: n (int): numero
Retorna: matriz cuadrada de n en cada lado
*/

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

//Parte b

/*Imprime el contenido de una matriz utilizando un unico ciclo for, desde el mayor valor al menor.
Parametro: 
matriz(vector<vector<int>>): matriz a imprimir
n(int): numero 
Retorna: nada, imprime.*/

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