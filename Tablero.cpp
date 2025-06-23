#include <iostream>
#include "Dado.h"
#include "personaje.h"
using namespace std;

void mostrar_tablero(int M[][10], int nfilas, int ncolumnas){
    cout << "=== Tablero ===\n";
    for(int i = 0; i < nfilas; i++){
        cout << "[ ";
        for(int j = 0; j < ncolumnas; j++){
            cout << M[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";
}

void avanzar(int M[][10]){
    int dado;
    int n = 0;
    int casilla_global = 0;
    dado = lanzar_dado(dado, n);
    int fila, columna;
    for(int pos = 0; pos < dado; pos++){
        fila = pos / 10;
        columna = pos % 10;
        casilla_global += dado;
        cout << "Usted está en la casilla: " << casilla_global << "\n";
        /*TODO: Agregar que la funcion del juegador, 
        debe avanzar conforme sea el resultado de lanzar_dado en el tablero*/
    }
}   

int main(void){
    int tablero[2][10] = { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {11, 12, 13, 14, 15, 16, 17, 18, 19, 20} };

    mostrar_tablero(tablero, 2, 10);
    avanzar(tablero);

    return 0;
}