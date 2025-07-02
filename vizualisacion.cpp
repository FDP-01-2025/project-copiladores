#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

// Prototipos
void mostrar_tablero(string M[][6]);
int lanzar_dado();
void mostrarDado(int num);
void casilla_a_coordenadas(int casilla, int &fila, int &col);
bool juego_finalizado(int pos_jugador);
void jugador_avanza(string M[][6], int &pos_jugador, int dado, string simbolo, vector<int> &casillas_adelanto, vector<int> &casillas_retroceso);
int mostrar_menu();
void pedir_nombres(string &nombre1, string &nombre2);
void generar_casillas_especiales(vector<int> &adelanto, vector<int> &retroceso, int dificultad);
string valor_original(int casilla);
void marcar_casillas_especiales(string M[][6], const vector<int>& adelanto, const vector<int>& retroceso);

int lanzar_dado() {
    cout << "=== Lanzar dado ===\n";
    cout << "Presiona ENTER para lanzar...";
    cin.ignore();
    int resultado = 1 + rand() % 6;
    cout << "Salio el numero: " << resultado << "\n";
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
        col = 16 - casilla;
    } else if (casilla >= 16 && casilla <= 20) {
        fila = 21 - casilla;
        col = 0;
    }
}

string valor_original(int casilla) {
    return (casilla < 10 ? " " : "") + to_string(casilla);
}

void jugador_avanza(string M[][6], int &pos_jugador, int dado, string simbolo, vector<int> &casillas_adelanto, vector<int> &casillas_retroceso) {
    int fila_ant, col_ant;
    casilla_a_coordenadas(pos_jugador, fila_ant, col_ant);
    M[fila_ant][col_ant] = valor_original(pos_jugador);

    pos_jugador += dado;
    if (pos_jugador > 20)
        pos_jugador = 20;

    if (find(casillas_adelanto.begin(), casillas_adelanto.end(), pos_jugador) != casillas_adelanto.end()) {
        int extra = 1 + rand() % 4;
        cout << "\nCasilla de impulso! Avanzas " << extra << " casillas extra!\n";
        pos_jugador += extra;
        if (pos_jugador > 20) pos_jugador = 20;
    } else if (find(casillas_retroceso.begin(), casillas_retroceso.end(), pos_jugador) != casillas_retroceso.end()) {
        int menos = 1 + rand() % 4;
        cout << "\nCasilla trampa! Retrocedes " << menos << " casillas!\n";
        pos_jugador -= menos;
        if (pos_jugador < 1) pos_jugador = 1;
    }

    int fila, col;
    casilla_a_coordenadas(pos_jugador, fila, col);
    M[fila][col] = " " + simbolo + " ";
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

int mostrar_menu() {
    int opcion;
    cout << "\n=== MENU DE JUEGO ===\n";
    cout << "1. Nivel facil\n";
    cout << "2. Nivel intermedio\n";
    cout << "3. Nivel dificil\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

void pedir_nombres(string &nombre1, string &nombre2) {
    cout << "Ingrese el nombre del Jugador 1 (Policia): ";
    getline(cin, nombre1);
    cout << "Ingrese el nombre del Jugador 2 (Ladron): ";
    getline(cin, nombre2);
}

void generar_casillas_especiales(vector<int> &adelanto, vector<int> &retroceso, int dificultad) {
    vector<int> disponibles;
    for (int i = 2; i <= 19; ++i) disponibles.push_back(i);
    random_shuffle(disponibles.begin(), disponibles.end());

    if (dificultad == 1) { // fácil
        adelanto.assign(disponibles.begin(), disponibles.begin() + 3);
        retroceso.assign(disponibles.begin() + 3, disponibles.begin() + 4);
    } else if (dificultad == 2) { // intermedio
        adelanto.assign(disponibles.begin(), disponibles.begin() + 3);
        retroceso.assign(disponibles.begin() + 3, disponibles.begin() + 6);
    } else if (dificultad == 3) { // difícil
        adelanto.assign(disponibles.begin(), disponibles.begin() + 2);
        retroceso.assign(disponibles.begin() + 2, disponibles.begin() + 8);
    }
}
void marcar_casillas_especiales(string M[][6], const vector<int>& adelanto, const vector<int>& retroceso) {
    // Primero restablecemos todas las casillas a sus números originales
    for (int c = 1; c <= 20; ++c) {
        int f, col;
        casilla_a_coordenadas(c, f, col);
        M[f][col] = valor_original(c);
    }
    // Marcamos las casillas de adelanto
    for (int c : adelanto) {
        int f, col;
        casilla_a_coordenadas(c, f, col);
        M[f][col] = " + ";
    }
    // Marcamos las casillas de retroceso
    for (int c : retroceso) {
        int f, col;
        casilla_a_coordenadas(c, f, col);
        M[f][col] = " - ";
    }
}

int main() {
    srand(time(NULL));

    cout << "=== Bienvenidos al juego de carreras Ladron y Policia ===\n\n";

    string tablero[6][6] = {
          {"1 ", "2 ", "3 ", "4 ", "5 ", "6 "},
        {"20", "  ", "  ", "  ", "  ", "7 "},
        {"19", "  ", "  ", "  ", "  ", "8 "},
        {"18", "  ", "  ", "  ", "  ", "9 "},
        {"17", "  ", "  ", "  ", "  ", "10"},
        {"16", "15", "14", "13", "12", "11"}
    };

    int opcion = mostrar_menu();
    if (opcion == 4) {
        cout << "Saliendo del juego...\n";
        return 0;
    }
    if (opcion < 1 || opcion > 4) {
        cout << "Opcion no valida. Fin del programa.\n";
        return 0;
    }

    string nombre1, nombre2;
    pedir_nombres(nombre1, nombre2);
    string inicial1 = nombre1.substr(0, 1);
    string inicial2 = nombre2.substr(0, 1);

    vector<int> casillas_adelanto, casillas_retroceso;
    generar_casillas_especiales(casillas_adelanto, casillas_retroceso, opcion);
    marcar_casillas_especiales(tablero, casillas_adelanto, casillas_retroceso);

    int pos_jugador1 = 1, pos_jugador2 = 1;
    int turno = 1;

    while (true) {
        mostrar_tablero(tablero);

        int dado = lanzar_dado();
        mostrarDado(dado);

        if (turno == 1) {
            cout << "\nTurno de " << nombre1 << " (" << inicial1 << ")\n";
            jugador_avanza(tablero, pos_jugador1, dado, inicial1, casillas_adelanto, casillas_retroceso);
            if (juego_finalizado(pos_jugador1)) {
                cout << nombre1 << " ha llegado a la meta y gana el juego!\n";
                break;
            }
            turno = 2;
        } else {
            cout << "\nTurno de " << nombre2 << " (" << inicial2 << ")\n";
            jugador_avanza(tablero, pos_jugador2, dado, inicial2, casillas_adelanto, casillas_retroceso);
            if (juego_finalizado(pos_jugador2)) {
                cout << nombre2 << " ha llegado a la meta y gana el juego!\n";
                break;
            }
            turno = 1;
        }
    }

    cout << "Juego finalizado.\n";
    return 0;
}
