#include ".\src\Funciones.cpp"

int main(void){
    string tablero[6][6] = { {"1  ", "2  ", "3  ", "4  ", "5  ", "6  "}, {"20 ", "   ", "   ", "   ", "   ", "7  "}, {"19 ", "   ", "   ", "   ", "   ", "8  "}, {"18 ", "   ", "   ", "   ", "   ", "9  "}, {"17 ", "   ", "   ", "   ", "   ", "10 "}, {"16", "15 ", "14 ", "13 ", " 12 ", "11 "} };
    bool juego_finalizado = false;
    int dado;
    string lanzar;

    do{
        mostrar_tablero(tablero, 6, 6);
        dado = lanzar_dado(lanzar);
        mostrarDado(dado);
        avanzar(tablero);
        jugador_avanza(tablero, dado, 6, 6);
    }while(3 < 1);
    
    return 0;
}