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

int lanzar_dado(string lanzar){

    int dado;
    srand(time(NULL)); // Para obtener resultados diferentes cada vez

    cout << "=== Simulador de Dado ===\n";
    cout << "Presiona ENTER para lanzar el dado: ";
    getline(cin, lanzar);

    // Lanzamiento del dado
    dado = 1 + rand() % 6;

    cout << "\nLanzando el dado...\n";
    cout << "Ha salido el numero: " << dado << "\n";

    // Mostrar el dibujo del dado
    mostrarDado(dado);

    cout << "Avanzas " << dado << " casillas en el juego.\n";

    return 0;
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

