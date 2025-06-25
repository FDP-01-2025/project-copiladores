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

int main(){
    string tablero[9][6] = { {"1  ", "2  ", "3  ", "4  ", "5  ", "6  "}, {"20 ", "   ", "   ", "   ", "   ", "7  "}, {"19 ", "   ", "   ", "   ", "   ", "8  "}, {"18 ", "   ", "   ", "   ", "   ", "9  "}, {"17 ", "   ", "   ", "   ", "   ", "10 "}, {"16", "15 ", "14 ", "13 ", " 12 ", "11 "} }; 

    mostrar_tablero(tablero, 9, 6);

    return 0;
}