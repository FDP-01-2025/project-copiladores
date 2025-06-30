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
    int dado;
    int n = 0;
    int casilla_global = 0;
    int fila, columna;
    casilla_global += dado;
    for(int i = 0; i < dado; i++){
        fila = i / 10;
        columna = i % 10;
        cout << "Usted está en la casilla: " << casilla_global << "\n";
    }
} 

void jugador_avanza(string M[][6], int dado, int nfilas, int ncolumnas){

    string Persona = "@";
    int casilla_global;

    for(int i = 0; i < nfilas; i++){
        for(int j = 0; j < ncolumnas; j++){
            if(M[i][j].find(to_string(dado)) != string::npos){
                casilla_global += dado;
                M[i][j] = Persona; //TODO: Agregar Personaje
            }
        }
    }
    return;
}

