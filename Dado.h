#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int lanzar_dado(int M, int N){

    srand(time(NULL)); // // para números aleatorios diferentes cada vez

    cout << "=== Simulador de Dado ===\n";
    cout << "Escribe una letra y presiona ENTER para lanzar el dado: ";
    cin >> N;  // Espera una entrada del usuario (como un botón)

    // Lanzamiento del dado
    M = 1 + rand() % 6;
    
    cout << "\nLanzando el dado...\n";
    cout << "Ha salido el numero: " << M<< "\n";
    cout << "Avanzas " << M << " casillas en el juego.\n";

    return M;
}