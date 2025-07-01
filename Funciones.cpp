#include "Header.h"

// agregue juego_finalizado
// Ahora recibe la posición del jugador y retorna true si llegó o pasó la meta
bool juego_finalizado(int pos_jugador)
{
    return pos_jugador >= 20;
}

void mostrar_tablero(string M[][6], int nfilas, int ncolumnas)
{
    for (int i = 0; i < nfilas; i++)
    {
        cout << "[ ";
        for (int j = 0; j < ncolumnas; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";
}

void mostrarDado(int num)
{
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

int lanzar_dado()
{
    cout << "=== Simulador de Dado ===\n";
    cout << "Presiona ENTER para lanzar el dado...";
    cin.ignore();

    int resultado = 1 + rand() % 6;

    cout << "\nLanzando el dado...\n";
    cout << "Ha salido el numero: " << resultado << "\n";
    cout << "Avanzas " << resultado << " casillas en el juego.\n";

    return resultado;
}

void avanzar(string M[][6])
{
    int dado = 0;
    int n = 0;
    int casilla_global = 0;
    int fila, columna;
    casilla_global += dado;
    for (int i = 1; i <= dado; i++)
    {
        casilla_global++;
        int fila = casilla_global / 6;
        int columna = casilla_global % 6;
        cout << "Usted está en la casilla: " << casilla_global << "\n";
    }
}

void casilla_a_coordenadas(int casilla, int &fila, int &col)
{ // se convierten las cassillas en coordenadas
    if (casilla >= 1 && casilla <= 6)
    { // Arriba
        fila = 0;
        col = casilla - 1;
    }
    else if (casilla >= 7 && casilla <= 10)
    { // Derecha
        fila = casilla - 6;
        col = 5;
    }
    else if (casilla >= 11 && casilla <= 15)
    { // Abajo
        fila = 5;
        col = 16 - casilla;
    }
    else if (casilla >= 16 && casilla <= 20)
    { // Izquierda
        fila = 21 - casilla;
        col = 0;
    }
}

void jugador_avanza(string M[][6], int &pos_jugador, int dado, int nfilas, int ncolumnas)
{
    int fila_ant, col_ant;
    casilla_a_coordenadas(pos_jugador, fila_ant, col_ant);
    // Restaura el número original
    M[fila_ant][col_ant] = (pos_jugador < 10 ? " " : "") + to_string(pos_jugador) + " ";

    pos_jugador += dado;
    if (pos_jugador > 20)
        pos_jugador = 20;

    int fila, col;
    casilla_a_coordenadas(pos_jugador, fila, col);
    M[fila][col] = "@";
}