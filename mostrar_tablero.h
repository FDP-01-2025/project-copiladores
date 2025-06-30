#include <iostream>
using namespace std;

void mostrar_tablero(string M[][6], int nfilas, int ncolumnas){
    for(int i = 0; i < ncolumnas; i++){
        cout << "[ ";
        for(int j = 0; j < ncolumnas; j++){
            cout << M[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "\n";
}