#include <iostream>
using namespace std;

// turnos de dos jugadores
void gestionarTurnos(int numturnos) {
    for (int turno = 0; turno < numturnos; ++turno) {
        int jugador = turno % 2 + 1; // Alterna entre jugador 1 y 2
        cout << "Turno del jugador " << jugador << endl;
        
    }
}