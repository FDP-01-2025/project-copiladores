#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void mostrarDado(int num) {
    cout << "\n+-------+\n";
    switch (num) {
        case 1:
            cout << "|       |\n";
            cout << "|   *   |\n";
            cout << "|       |\n";
            break;
        case 2:
            cout << "| *     |\n";
            cout << "|       |\n";
            cout << "|     * |\n";
            break;
        case 3:
            cout << "| *     |\n";
            cout << "|   *   |\n";
            cout << "|     * |\n";
            break;
        case 4:
            cout << "| *   * |\n";
            cout << "|       |\n";
            cout << "| *   * |\n";
            break;
        case 5:
            cout << "| *   * |\n";
            cout << "|   *   |\n";
            cout << "| *   * |\n";
            break;
        case 6:
            cout << "| *   * |\n";
            cout << "| *   * |\n";
            cout << "| *   * |\n";
            break;
    }
    cout << "+-------+\n";
}

int main() {
    int dado;
    int lanzar;

    srand(time(NULL)); // Para obtener resultados diferentes cada vez

    cout << "=== Simulador de Dado ===\n";
    cout << "Elije un numero y presiona ENTER para lanzar el dado: ";
    cin >> lanzar;

    // Lanzamiento del dado
    dado = 1 + rand() % 6;

    cout << "\nLanzando el dado...\n";
    cout << "Ha salido el numero: " << dado << "\n";

    // Mostrar el dibujo del dado
    mostrarDado(dado);

    cout << "Avanzas " << dado << " casillas en el juego.\n";

    return 0;
}
