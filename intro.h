#include <iostream>
using namespace std;

// Función para mostrar el arte inicial del juego
void mostrarBanner() {
    cout << "Welcome to the police and thief racing game" << endl;
    cout << "   ______________ " << endl;
    cout << "   |     |      |  " << endl;
    cout << " ___________________" << endl;
    cout << "|                   |" << endl;
    cout << " ___________________ " << endl;
    cout << "   |  |       |   |" << endl;
    cout << "   ---         ---" << endl;
}

// Función para pedir los nombres de los jugadores
void pedirUsuarios(string &usuario1, string &usuario2) {
    cout << "Ingrese usuario 1 su nombre: " << endl;
    cin >> usuario1;
    cout << "Ingrese usuario 2 su nombre: " << endl;
    cin >> usuario2;
}

// Función para mostrar el menú y devolver la opción
int mostrarMenu() {
    int opcion;
    cout << "Elije el nivel de dificultad del juego" << endl;
    cout << " 1. Facil" << endl;
    cout << " 2. Medio" << endl;
    cout << " 3. Dificil" << endl;
    cout << " 4. Salir" << endl;
    cout << "\n";
    cin >> opcion;
    return opcion;
}

// Función para procesar la dificultad elegida
void procesarDificultad(int opcion) {
    switch (opcion) {
        case 1:
            cout << "Elegiste la opcion fácil" << endl;
            cout << "Cargando..." << endl;
            break;
        case 2:
            cout << "Elegiste la opcion media" << endl;
            cout << "Cargando..." << endl;
            break;
        case 3:
            cout << "Elegiste la opción dificil" << endl;
            cout << "Cargando..." << endl;
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Elige una opción entre 1 y 4" << endl;
            break;
    }
}

int main() {
    string usuario1, usuario2;
    int opcion;

    mostrarBanner();
    pedirUsuarios(usuario1, usuario2);
    opcion = mostrarMenu();
    procesarDificultad(opcion);

    return 0;
}
