#include "Header.h"

// agregue juego_finalizado
// Ahora recibe la posición del jugador y retorna true si llegó o pasó la meta
bool juego_finalizado(int pos_jugador){
    return pos_jugador >= 20;
}

void mostrar_tablero(string M[][6], int nfilas, int ncolumnas){
    for (int i = 0; i < nfilas; i++){
        cout << "[ ";
        for (int j = 0; j < ncolumnas; j++){
            cout << M[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";
}

void mostrarDado(int num){
    cout << "\n+-------+\n";
    switch (num)
    {
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

int lanzar_dado(int jugador){
    cout << "=== Simulador de Dado ===\n";
    cout << "Turno del jugador #" << jugador;
    cout << "Presiona ENTER para lanzar el dado...";
    cin.ignore();

    int resultado = 1 + rand() % 6;

    cout << "\nLanzando el dado...\n";
    cout << "Ha salido el numero: " << resultado << "\n";
    cout << "Jugador #" << jugador <<  " avanzas " << resultado << " casillas en el juego.\n";
    jugador = ((jugador==1)?2:1);

    return resultado;
}

void casilla_a_coordenadas(int casilla, int &fila, int &col){
    if (casilla >= 1 && casilla <= 6) { // Fila de arriba 
        fila = 0;
        col = casilla - 1;
    }
    else if (casilla >= 7 && casilla <= 11) { // Columna derecha 
        fila = casilla - 6;
        col = 5;
    }
    else if (casilla >= 12 && casilla <= 16) { // Fila de abajo 
        fila = 5;
        col = 17 - casilla;
    }
    else if (casilla >= 17 && casilla <= 20) { // Columna izquierda 
        fila = 21 - casilla;
        col = 0;
    }
}

bool es_trampa(int casilla) {
    int trampas[] = {5, 10, 14, 18};
    int cantidad_trampas = sizeof(trampas) / sizeof(trampas[0]);
    for (int i = 0; i < cantidad_trampas; i++) {
        if (casilla == trampas[i])
            return true;
    }
    return false;
}

void jugador_avanza(string M[][6], int &pos_jugador, string jugador, string personaje1, string personaje2, int dado, int nfilas, int ncolumnas){
    int fila_ant, col_ant;
    casilla_a_coordenadas(pos_jugador, fila_ant, col_ant);
    // Restaura el número original
    M[fila_ant][col_ant] = (pos_jugador < 10 ? " " : " ") + to_string(pos_jugador) + " ";

    pos_jugador += dado;
    if (pos_jugador > 20){
        pos_jugador = 20;
    }

    if (es_trampa(pos_jugador)) {
        cout << "\n ¡CUIDADO! Jugador #" << jugador << " has caído en una casilla trampa y retrocede 3 posiciones.\n";
        pos_jugador -= 3;
        if (pos_jugador < 1)
            pos_jugador = 1;
    }

    int fila, col;
    casilla_a_coordenadas(pos_jugador, fila, col);
    jugador = ((jugador=="1")?personaje1:personaje2);
    M[fila][col] = jugador;
    jugador = ((jugador=="1")?"2":"1");
}