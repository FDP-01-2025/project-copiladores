#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream> 
using namespace std;

void mostrar_tablero(string M[][6], int nfilas, int ncolumnas);
int lanzar_dado();
void mostrarDado(int num);
void avanzar(string M[][6]);
void casilla_a_coordenadas(int casilla, int &fila, int &col);
void jugador_avanza(string M[][6], int &pos_jugador, int dado, int nfilas, int ncolumnas);
bool es_trampa(int casilla);
bool juego_finalizado(int pos_jugador);
