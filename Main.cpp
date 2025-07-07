#include ".\src\Funciones.cpp"

int main(){
    int pos_jugador1 = 1;
    int pos_jugador2 = 1;
    string personaje1 = "@";
    string personaje2 = "$";
    int jugador_actual = 1;
    int op;

    string tablero[6][6] = {
        {"1  ", "2  ", "3  ", "4  ", "5  ", "6  "},
        {"20 ", "   ", "   ", "   ", "   ", "7  "},
        {"19 ", "   ", "   ", "   ", "   ", "8  "},
        {"18 ", "   ", "   ", "   ", "   ", "9  "},
        {"17 ", "   ", "   ", "   ", "   ", "10 "},
        {"16 ", "15 ", "14 ", "13 ", "12 ", "11 "}};

    srand(time(NULL));

    do {
        cout << "===== BIENVENIDO ======\n";
        cout << "== Thief and Policeman ==\n";

        cout << "===== MENU =====\n";
        cout << "1. Jugar\n2. Escoger Personaje\n3. Salir\n";
        cin >> op;
        cin.ignore(); 

        switch (op){
        case 1:
                int fila1, col1, fila2, col2;
                casilla_a_coordenadas(pos_jugador1, fila1, col1);
                casilla_a_coordenadas(pos_jugador2, fila2, col2);
                tablero[fila1][col1] = personaje1;
                tablero[fila2][col2] = personaje2;

            while (true) {
                mostrar_tablero(tablero, 6, 6);
                int dado = lanzar_dado(jugador_actual);
                mostrarDado(dado);

                if (jugador_actual == 1) {
                    jugador_avanza(tablero, pos_jugador1, "1", personaje1, personaje2, dado, 6, 6);
                    if (juego_finalizado(pos_jugador1)) {
                        cout << "¡Jugador 1 ha ganado!\n";
                        break;
                    }
                } else {
                    jugador_avanza(tablero, pos_jugador2, "2", personaje1, personaje2, dado, 6, 6);
                    if (juego_finalizado(pos_jugador2)) {
                        cout << "¡Jugador 2 ha ganado!\n";
                        break;
                    }
                }

                jugador_actual = (jugador_actual == 1) ? 2 : 1; // Alternar turno
            }
            break;

        case 2:
            for (int i = 1; i <= 2; i++) {
                int eleccion;
                cout << "Jugador #" << i << ", elige tu personaje:\n";
                cout << "1. @\n2. $\n3. !\n4. *\n";
                cin >> eleccion;

                switch (eleccion) {
                case 1: (i == 1) ? personaje1 = "@" : personaje2 = "@"; break;
                case 2: (i == 1) ? personaje1 = "$" : personaje2 = "$"; break;
                case 3: (i == 1) ? personaje1 = "!" : personaje2 = "!"; break;
                case 4: (i == 1) ? personaje1 = "*" : personaje2 = "*"; break;
                default:
                    cout << "Opción inválida, se usará '@' por defecto.\n";
                    (i == 1) ? personaje1 = "@" : personaje2 = "@"; break;
                }
            }
            break;

        case 3:
            cout << "Gracias por jugar, ¡hasta la próxima!\n";
            break;

        default:
            cout << "Opción inválida.\n";
            break;
        }
    } while (op != 3);

    return 0;
}