#include "Header.h"

int main(void){
    int pos_jugador = 1;
    string tablero[6][6] = { {"1  ", "2  ", "3  ", "4  ", "5  ", "6  "}, {"20 ", "   ", "   ", "   ", "   ", "7  "}, {"19 ", "   ", "   ", "   ", "   ", "8  "}, {"18 ", "   ", "   ", "   ", "   ", "9  "}, {"17 ", "   ", "   ", "   ", "   ", "10 "}, {"16", "15 ", "14 ", "13 ", " 12 ", "11 "} };
    bool juego_finalizado = false;
    srand(time(NULL));

    do{
        mostrar_tablero(tablero, 6, 6);
        int dado = lanzar_dado() ; 
        mostrarDado(dado);
        avanzar(tablero);
        jugador_avanza(tablero, pos_jugador, dado, 6, 6);
    }while(3 < 1);
    
    return 0;
}