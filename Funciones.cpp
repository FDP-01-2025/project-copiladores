#include "Header.h"

bool juego_finalizado(){
    
}

void mostrar_tablero(string M[][6], int nfilas, int ncolumnas){
    for(int i = 0; i < nfilas; i++){
        cout << "[ ";
        for(int j = 0; j < ncolumnas; j++){
            cout << M[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";
}

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

void avanzar(string M[][6]){
    int dado = 0;
    int n = 0;
    int casilla_global = 0;
    int fila, columna;
    casilla_global += dado;
    for(int i = 1; i <= dado; i++){
        casilla_global++;
        int fila = casilla_global / 6;
        int columna = casilla_global % 6;
        cout << "Usted está en la casilla: " << casilla_global << "\n";
    }
} 

void jugador_avanza(string M[][6], int dado, int nfilas, int ncolumnas){

    string Persona = "@";
    int casilla_global = 0;

    casilla_global += dado - 1;
    int fila = casilla_global / ncolumnas;
    int columna = casilla_global % ncolumnas;
    
    M[fila][columna] = "@";

    //TODO: Borrar la posicion actual del jugador por cada vuelta y hacer que la posicion del jugador se acumule a modo que recorra todas las casillas.
}