#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void mostrar_tablero(string M[][6], int nfilas, int ncolumnas);
int lanzar_dado();
void mostrarDado(int num);
void avanzar(string M[][6]);
void jugador_avanza(string M[][6], int &pos_jugador, int dado, int nfilas, int ncolumnas,string simbolo);


void casilla_a_coordenadas(int casilla, int &fila, int &col);
bool juego_finalizado(int pos_jugador);

int lanzar_dado() {
    cout << "=== Lanzar dado ===\n";
    cout << "Presiona ENTER para lanzar...";
    cin.ignore();
    int resultado = 1 + rand() % 6;
    cout << "Salió el número: " << resultado << "\n";
    return resultado;
}

void mostrarDado(int num) {
    cout << "\n+-------+\n";
    switch (num) {
        case 1:
            cout << "|       |\n|   *   |\n|       |\n"; break;
        case 2:
            cout << "| *     |\n|       |\n|     * |\n"; break;
        case 3:
            cout << "| *     |\n|   *   |\n|     * |\n"; break;
        case 4:
            cout << "| *   * |\n|       |\n| *   * |\n"; break;
        case 5:
            cout << "| *   * |\n|   *   |\n| *   * |\n"; break;
        case 6:
            cout << "| *   * |\n| *   * |\n| *   * |\n"; break;
    }
    cout << "+-------+\n";
}

void casilla_a_coordenadas(int casilla, int &fila, int &col) {
    if (casilla >= 1 && casilla <= 6) {          // Arriba
        fila = 0;
        col = casilla - 1;
    } else if (casilla >= 7 && casilla <= 10) {  // Derecha
        fila = casilla - 6;
        col = 5;
    } else if (casilla >= 11 && casilla <= 15) { // Abajo
        fila = 5;
        col = 16 - casilla;
    } else if (casilla >= 16 && casilla <= 20) { // Izquierda
        fila = 21 - casilla;
        col = 0;
    }
}
void jugador_avanza(string M[][6], int &pos_jugador, int dado, int nfilas, int ncolumnas, string simbolo)
{
    int fila_ant, col_ant;
    casilla_a_coordenadas(pos_jugador, fila_ant, col_ant);
    M[fila_ant][col_ant] = (pos_jugador < 10 ? " " : "") + to_string(pos_jugador) + " ";

    pos_jugador += dado;
    if (pos_jugador > 20)
        pos_jugador = 20;

    int fila, col;
    casilla_a_coordenadas(pos_jugador, fila, col);
    M[fila][col] = simbolo;
}


void mostrar_tablero(string tablero[][6]) {
    for (int i = 0; i < 6; i++) {
        cout << "[ ";
        for (int j = 0; j < 6; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << endl;
}

bool juego_finalizado(int pos_jugador) {
    return pos_jugador >= 20;
}

// ============ FUNCIÓN PRINCIPAL MAIN() ============

int main() {
    int pos_jugador1 = 1;
    int pos_jugador2 = 1;
    int turno = 1; // 1 = jugador1, 2 = jugador2

    string tablero[6][6] = {
        {"1 ", "2 ", "3 ", "4 ", "5 ", "6 "},
        {"20", "  ", "  ", "  ", "  ", "7 "},
        {"19", "  ", "  ", "  ", "  ", "8 "},
        {"18", "  ", "  ", "  ", "  ", "9 "},
        {"17", "  ", "  ", "  ", "  ", "10"},
        {"16", "15", "14", "13", "12", "11"}
    };

    // Posicionar jugador 1 y 2 al inicio
    int fila1, col1, fila2, col2;
    casilla_a_coordenadas(pos_jugador1, fila1, col1);
    tablero[fila1][col1] = " @ ";
    casilla_a_coordenadas(pos_jugador2, fila2, col2);
    tablero[fila2][col2] = " # ";

    srand(time(NULL));

    while (true)
    {
        int dado = lanzar_dado();
        mostrarDado(dado);

        if (turno == 1)
        {
            cout << "Turno del Jugador 1" << endl;
            jugador_avanza(tablero, pos_jugador1, dado, 6, 6, " @ ");
        }
        else
        {
            cout << "Turno del Jugador 2" << endl;
            jugador_avanza(tablero, pos_jugador2, dado, 6, 6, " # ");
        }

        mostrar_tablero(tablero);

        if (juego_finalizado(pos_jugador1))
        {
            cout << "¡El Jugador 1 ha ganado!" << endl;
            break;
        }
        if (juego_finalizado(pos_jugador2))
        {
            cout << "¡El Jugador 2 ha ganado!" << endl;
            break;
        }

        // Cambiar turno
        turno = (turno == 1) ? 2 : 1;
    }

    return 0;
}
