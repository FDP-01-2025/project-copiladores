#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
using namespace std;

// Prototipos
void mostrar_tablero(string M[][6]);
int lanzar_dado();
void mostrarDado(int num);
void casilla_a_coordenadas(int casilla, int &fila, int &col);
bool juego_finalizado(int pos_jugador);
void jugador_avanza(string M[][6], int &pos_jugador, int dado, string simbolo);
int mostrar_menu();
void pedir_nombres(string &nombre1, string &nombre2);
string valor_original(int casilla);
void generar_casillas_especiales(vector<int> &adelanto, vector<int> &retroceso, int tipo);

// Implementación
int lanzar_dado() {
    cout << "=== Lanzar dado ===\n";
    cout << "Presiona ENTER para lanzar...";
    cin.ignore();
    int resultado = 1 + rand() % 6;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Salió el número: " << resultado << "\n";
    return resultado;
}

void mostrarDado(int num) {
    cout << "\n+-------+\n";
    switch (num) {
        case 1: cout << "|       |\n|   *   |\n|       |\n"; break;
        case 2: cout << "| *     |\n|       |\n|     * |\n"; break;
        case 3: cout << "| *     |\n|   *   |\n|     * |\n"; break;
        case 4: cout << "| *   * |\n|       |\n| *   * |\n"; break;
        case 5: cout << "| *   * |\n|   *   |\n| *   * |\n"; break;
        case 6: cout << "| *   * |\n| *   * |\n| *   * |\n"; break;
    }
    cout << "+-------+\n";
}

void casilla_a_coordenadas(int casilla, int &fila, int &col) {
    if (casilla >= 1 && casilla <= 6) {
        fila = 0;
        col = casilla - 1;
    } else if (casilla >= 7 && casilla <= 10) {
        fila = casilla - 6;
        col = 5;
    } else if (casilla >= 11 && casilla <= 15) {
        fila = 5;
        col = 16 - casilla; // 15->1, 14->2, ..., 11->5
    } else if (casilla >= 16 && casilla <= 20) {
        fila = 21 - casilla; // 20->1, 19->2, ..., 16->5
        col = 0;
    }
}

string valor_original(int casilla) {
    return (casilla < 10 ? " " : "") + to_string(casilla);
}

void jugador_avanza(string M[][6], int &pos_jugador, int dado, string simbolo) {
    int fila_ant, col_ant;
    casilla_a_coordenadas(pos_jugador, fila_ant, col_ant);
    M[fila_ant][col_ant] = valor_original(pos_jugador);

    pos_jugador += dado;
    if (pos_jugador > 20) pos_jugador = 20;

    int fila, col;
    casilla_a_coordenadas(pos_jugador, fila, col);
    M[fila][col] = " " + simbolo + " ";
}

void mostrar_tablero(string tablero[][6]) {
    cout << "\nTablero actual:\n";
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

int mostrar_menu() {
    int opcion;
    cout << "\n=== MENU DE JUEGO ===\n";
    cout << "1. Nivel fácil\n";
    cout << "2. Nivel intermedio\n";
    cout << "3. Nivel difícil\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

void pedir_nombres(string &nombre1, string &nombre2) {
    cout << "Ingrese el nombre del Jugador 1 (Policía): ";
    getline(cin, nombre1);
    cout << "Ingrese el nombre del Jugador 2 (Ladrón): ";
    getline(cin, nombre2);
}

void generar_casillas_especiales(vector<int> &adelanto, vector<int> &retroceso, int tipo) {
    vector<int> disponibles;
    for (int i = 2; i <= 19; ++i) disponibles.push_back(i);
    random_shuffle(disponibles.begin(), disponibles.end());

    if (tipo == 1) { // fácil
        adelanto.assign(disponibles.begin(), disponibles.begin() + 3);
        retroceso.assign(disponibles.begin() + 3, disponibles.begin() + 4);
    } else if (tipo == 2) { // intermedio
        adelanto.assign(disponibles.begin(), disponibles.begin() + 3);
        retroceso.assign(disponibles.begin() + 3, disponibles.begin() + 6);
    } else if (tipo == 3) { // difícil
        adelanto.assign(disponibles.begin(), disponibles.begin() + 2);
        retroceso.assign(disponibles.begin() + 2, disponibles.begin() + 8);
    }
}

int main() {
    srand(time(NULL));

    cout << "=== Bienvenidos al juego Ladron y Policia ===\n";
    int opcion = mostrar_menu();
    if (opcion == 4) {
        cout << "Saliendo del juego...\n";
        return 0;
    }
    if (opcion < 1 || opcion > 4) {
        cout << "Opción no válida. Fin del programa.\n";
        return 0;
    }

    string nombre1, nombre2;
    pedir_nombres(nombre1, nombre2);
    string inicial1 = nombre1.substr(0, 1);
    string inicial2 = nombre2.substr(0, 1);

    int pos_jugador1 = 1;
    int pos_jugador2 = 1;
    int turno = 1;

    // Tablero 6x6 con casillas del 1 al 20 distribuidas en "serpiente"
    string tablero[6][6] = {
        {" 1", " 2", " 3", " 4", " 5", " 6"},
        {"20", "  ", "  ", "  ", "  ", " 7"},
        {"19", "  ", "  ", "  ", "  ", " 8"},
        {"18", "  ", "  ", "  ", "  ", " 9"},
        {"17", "  ", "  ", "  ", "  ", "10"},
        {"16", "15", "14", "13", "12", "11"}
    };

    vector<int> casillas_adelanto, casillas_retroceso;
    generar_casillas_especiales(casillas_adelanto, casillas_retroceso, opcion);

    // Marcar posición inicial
    int fila, col;
    casilla_a_coordenadas(pos_jugador1, fila, col);
    tablero[fila][col] = " " + inicial1 + " ";
    casilla_a_coordenadas(pos_jugador2, fila, col);
    // Si ambos empiezan en la misma casilla, mostrar ambos símbolos juntos (opcional)
    if (pos_jugador2 == pos_jugador1) {
        tablero[fila][col] = " " + inicial1 + inicial2;
    } else {
        tablero[fila][col] = " " + inicial2 + " ";
    }

    mostrar_tablero(tablero);

    while (true) {
        if (turno == 1) {
            cout << "\nTurno de " << nombre1 << " (" << inicial1 << ") - Casilla actual: " << pos_jugador1 << "\n";
            int dado = lanzar_dado();
            mostrarDado(dado);
            jugador_avanza(tablero, pos_jugador1, dado, inicial1);

            if (find(casillas_adelanto.begin(), casillas_adelanto.end(), pos_jugador1) != casillas_adelanto.end()) {
                int extra = 1 + rand() % 4;
                cout << "¡Casilla especial! Adelantas " << extra << " casillas...\n";
                this_thread::sleep_for(chrono::seconds(1));
                jugador_avanza(tablero, pos_jugador1, extra, inicial1);
            }

            if (find(casillas_retroceso.begin(), casillas_retroceso.end(), pos_jugador1) != casillas_retroceso.end()) {
                int resta = 1 + rand() % 4;
                cout << "¡Casilla trampa! Retrocedes " << resta << " casillas.\n";
                this_thread::sleep_for(chrono::seconds(1));

                int f, c;
                casilla_a_coordenadas(pos_jugador1, f, c);
                tablero[f][c] = valor_original(pos_jugador1);

                pos_jugador1 -= resta;
                if (pos_jugador1 < 1) pos_jugador1 = 1;

                jugador_avanza(tablero, pos_jugador1, 0, inicial1);
            }

        } else {
            cout << "\nTurno de " << nombre2 << " (" << inicial2 << ") - Casilla actual: " << pos_jugador2 << "\n";
            int dado = lanzar_dado();
            mostrarDado(dado);
            jugador_avanza(tablero, pos_jugador2, dado, inicial2);

            if (find(casillas_adelanto.begin(), casillas_adelanto.end(), pos_jugador2) != casillas_adelanto.end()) {
                int extra = 1 + rand() % 4;
                cout << "¡Casilla especial! Adelantas " << extra << " casillas...\n";
                this_thread::sleep_for(chrono::seconds(1));
                jugador_avanza(tablero, pos_jugador2, extra, inicial2);
            }

            if (find(casillas_retroceso.begin(), casillas_retroceso.end(), pos_jugador2) != casillas_retroceso.end()) {
                int resta = 1 + rand() % 4;
                cout << "¡Casilla trampa! Retrocedes " << resta << " casillas.\n";
                this_thread::sleep_for(chrono::seconds(1));

                int f, c;
                casilla_a_coordenadas(pos_jugador2, f, c);
                tablero[f][c] = valor_original(pos_jugador2);

                pos_jugador2 -= resta;
                if (pos_jugador2 < 1) pos_jugador2 = 1;

                jugador_avanza(tablero, pos_jugador2, 0, inicial2);
            }
        }

        mostrar_tablero(tablero);

        if (juego_finalizado(pos_jugador1)) {
            cout << "\n¡" << nombre1 << " ha ganado la carrera!\n";
            break;
        }
        if (juego_finalizado(pos_jugador2)) {
            cout << "\n¡" << nombre2 << " ha ganado la carrera!\n";
            break;
        }

        turno = (turno == 1) ? 2 : 1;
    }

    return 0;
}
