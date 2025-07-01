#include "Header.h"

#include "Header.h"

int main()
{
    int pos_jugador = 1; // Posición inicial del jugador

    string tablero[6][6] = {
        {"1  ", "2  ", "3  ", "4  ", "5  ", "6  "},
        {"20 ", "   ", "   ", "   ", "   ", "7  "},
        {"19 ", "   ", "   ", "   ", "   ", "8  "},
        {"18 ", "   ", "   ", "   ", "   ", "9  "},
        {"17 ", "   ", "   ", "   ", "   ", "10 "},
        {"16 ", "15 ", "14 ", "13 ", "12 ", "11 "}};

    string tablero_original[6][6];
    // Copiar el tablero original
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tablero_original[i][j] = tablero[i][j];
        }
    }

    tablero[0][0] = "@";
    srand(time(NULL));

    while (!juego_finalizado(pos_jugador))
    {
        mostrar_tablero(tablero, 6, 6);
        int dado = lanzar_dado();
        mostrarDado(dado);

        jugador_avanza(tablero, pos_jugador, dado, 6, 6);
    }

    cout << "Juego terminado!: " << pos_jugador << endl;
    return 0;
}