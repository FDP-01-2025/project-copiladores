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


    


void casilla_a_coordenadas(int casilla, int &fila, int &col)
{
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

void jugador_avanza(string M[][6], int &pos_jugador, int dado, int nfilas, int ncolumnas)
{
    int fila_ant, col_ant;
    casilla_a_coordenadas(pos_jugador, fila_ant, col_ant);
    // Restaura el número original
    M[fila_ant][col_ant] = (pos_jugador < 10 ? " " : " ") + to_string(pos_jugador) + " ";

    pos_jugador += dado;
    if (pos_jugador > 20)
        pos_jugador = 20;

    int fila, col;
    casilla_a_coordenadas(pos_jugador, fila, col);
    M[fila][col] = " @ ";
}