#include <iostream>
using namespace std;

int main(void){
    string usuario1, usuario2;
    int opcion;


    cout << "Welcome to the police and thief racing game" << endl;
    cout << "   ______________ " << endl;
    cout << "   |     |      |  " << endl;
    cout << " ___________________" << endl;
    cout << "|                   |" << endl;
    cout << " ___________________ " << endl;
    cout << "   |  |       |   |" << endl;
    cout << "   ---         ---" << endl;




    cout << "Elije el nivel de dificultad del juego" << endl;
    cout << " 1. Facil" << endl;
    cout << " 2. Medio" << endl;
    cout << " 3. Dificil" << endl;
    cout << " Si deseas salir selecciona la siguiente opcion" << endl;
    cout << " 4. Salir" << endl;
    cout << "\n";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cout << "Elijiste la opcion facil" << endl;
        cout << "Cargando..." << endl;
        break;
    case 2:
        cout << "Elijiste la opcion medio" << endl;
        cout << "Cargando..." << endl;
        break;
    case 3:
        cout << "Elijiste la opcion dificil" << endl;
        cout << "Cargando..." << endl;
        break;
    case 4:
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Elije una opcion entre 1 y 4" << endl;
        break;
    }
    return 0;
}