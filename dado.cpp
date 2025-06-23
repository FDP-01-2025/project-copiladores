#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {
    int dado;

    srand(time(NULL)); // para números aleatorios diferentes cada vez

    // Simular el lanzamiento del dado (1 al 6)
    dado = 1 + rand() % 6;

    cout << "Lanzando el dado..." << "\n";
    cout << "Ha salido el numero: " << dado << "\n";
    cout << "Avanzas " << dado << " casillas en el juego." << "\n";

    return 0;
}