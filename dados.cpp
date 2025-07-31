#include <iostream>
#include <cstdlib>
#include "dados.h"
using namespace std;

int tirarDado(int caras) {
    return rand() % caras + 1;
}

int tirarDosDados12() {
    int d1 = tirarDado(12);
    int d2 = tirarDado(12);
    cout << "Dados objetivo: " << d1 << " + " << d2 << " = " << d1 + d2 << endl;
    return d1 + d2;
}

void tirarDadosStock(int stock[], int &cantidad) {
    for (int i = 0; i < 6; i++) {
        stock[i] = tirarDado(6);
    }
    cantidad = 6;
}

void mostrarDados(int dados[], int cantidad) {
    cout << "[ ";
    for (int i = 0; i < cantidad; i++) {
        cout << dados[i] << " ";
    }
    cout << "]\n";
}

