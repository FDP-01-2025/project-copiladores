#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {
    int dado;
    char lanzar;

    srand(time(NULL)); // // para números aleatorios diferentes cada vez

    cout << "=== Simulador de Dado ===\n";
    cout << "Escribe una letra y presiona ENTER para lanzar el dado: ";
    cin >> lanzar;  // Espera una entrada del usuario (como un botón)

    // Lanzamiento del dado
    dado = 1 + rand() % 6;

    cout << "\nLanzando el dado...\n";
    cout << "Ha salido el numero: " << dado << "\n";
    cout << "Avanzas " << dado << " casillas en el juego.\n";

    return 0;
}