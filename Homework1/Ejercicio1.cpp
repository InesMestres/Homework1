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