#include <iostream>
#include "Dado.h"
#include "personaje.h"
#include "mostrar_tablero.h"
using namespace std;

bool juego_finalizado(){
    
}

void avanzar(string M[][6]){
    int dado;
    int n = 0;
    int casilla_global = 0;
    dado = lanzar_dado(dado, n);
    int fila, columna;
    casilla_global += dado;
    for(int i = 0; i < dado; i++){
        fila = i / 10;
        columna = i % 10;
        cout << "Usted está en la casilla: " << casilla_global << "\n";
        /*TODO: Agregar que la funcion del juegador, 
        debe avanzar conforme sea el resultado de lanzar_dado en el tablero*/
    }
}   

int main(void){
    string tablero[9][6] = { {"1  ", "2  ", "3  ", "4  ", "5  ", "6  "}, {"20 ", "   ", "   ", "   ", "   ", "7  "}, {"19 ", "   ", "   ", "   ", "   ", "8  "}, {"18 ", "   ", "   ", "   ", "   ", "9  "}, {"17 ", "   ", "   ", "   ", "   ", "10 "}, {"16", "15 ", "14 ", "13 ", " 12 ", "11 "} };
    bool juego_finalizado = false;

    do{
        mostrar_tablero(tablero, 2, 10);
        avanzar(tablero);
    }while(!juego_finalizado);
    
    return 0;
}