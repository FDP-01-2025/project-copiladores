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


int lanzar_dado() {
    cout << "=== Simulador de Dado ===\n";
    cout << "Presiona ENTER para lanzar el dado...";
    cin.ignore(); // Espera que el usuario presione ENTER

    int resultado = 1 + rand() % 6;

    cout << "\nLanzando el dado...\n";
    cout << "Ha salido el número: " << resultado << "\n";
    cout << "Avanzas " << resultado << " casillas en el juego.\n";

    return resultado;
}

int main() {
    srand(time(NULL)); // Inicializa la semilla una sola vez

    int resultado = lanzar_dado();  // Lanza el dado
    mostrarDado(resultado);         // Muestra el dado gráficamente

    return 0;
}
