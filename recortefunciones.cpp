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

void jugador_avanza(string tablero[][6], int &pos_jugador, int dado) {
    int fila_ant, col_ant;
    casilla_a_coordenadas(pos_jugador, fila_ant, col_ant);
    // Restaura el número original
    tablero[fila_ant][col_ant] = (pos_jugador < 10 ? " " : "") + to_string(pos_jugador) + " ";

    // Avanza
    pos_jugador += dado;
    if (pos_jugador > 20)
        pos_jugador = 20;

    int fila, col;
    casilla_a_coordenadas(pos_jugador, fila, col);
    tablero[fila][col] = "@ ";
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
    int pos_jugador = 1;

    string tablero[6][6] = {
        {"1 ", "2 ", "3 ", "4 ", "5 ", "6 "},
        {"20", "  ", "  ", "  ", "  ", "7 "},
        {"19", "  ", "  ", "  ", "  ", "8 "},
        {"18", "  ", "  ", "  ", "  ", "9 "},
        {"17", "  ", "  ", "  ", "  ", "10"},
        {"16", "15", "14", "13", "12", "11"}
    };

    tablero[0][0] = "@ ";

    srand(time(NULL));

    while (!juego_finalizado(pos_jugador)) {
        mostrar_tablero(tablero);
        int dado = lanzar_dado();
        mostrarDado(dado);
        jugador_avanza(tablero, pos_jugador, dado);
    }

    mostrar_tablero(tablero);
    cout << "¡Juego terminado! Llegaste a la meta.\n";

    return 0;
}
