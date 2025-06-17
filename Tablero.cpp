#include <iostream>
using namespace std;

void mostrar_tablero(string M){
    for(int i = 0; i < 6; i++){
        cout << M;
    }
}

int main(void){
    string tablero = "======================== \n   ->     |     ->       \n ========================";

    mostrar_tablero(tablero);

    return 0;
}