#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void mostrar_tablero(string M[][6], int nfilas, int ncolumnas);
int lanzar_dado();
void mostrarDado(int num);
void avanzar(string M[][6]);
void jugador_avanza(std::string M[][6], int &pos_jugador, int dado, int nfilas, int ncolumnas);