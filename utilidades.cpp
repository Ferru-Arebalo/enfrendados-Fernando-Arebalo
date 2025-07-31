#include <iostream>
#include "utilidades.h"
using namespace std;

int pedirEntero(string mensaje) {
    int valor;
    cout << mensaje;
    cin >> valor;
    return valor;
}

void pausar() {
    cout << "Presiona ENTER para continuar..." << endl;
    cin.ignore();
    cin.get();
}

bool esSumaValida(int seleccionados[], int cantidad, int objetivo) {
    int suma = 0;
    for (int i = 0; i < cantidad; i++) suma += seleccionados[i];
    return suma == objetivo;
}

int calcularPuntaje(int cantidadDados, int objetivo) {
    return objetivo * cantidadDados;
}

void copiarStockSinUsados(int original[], int &cantOriginal, int usados[], int cantUsados) {
    int nuevo[20];
    int nuevoCant = 0;
    for (int i = 0; i < cantOriginal; i++) {
        bool estaUsado = false;
        for (int j = 0; j < cantUsados; j++) {
            if (original[i] == usados[j]) {
                usados[j] = -1;
                estaUsado = true;
                break;
            }
        }
        if (!estaUsado) {
            nuevo[nuevoCant++] = original[i];
        }
    }
    for (int i = 0; i < nuevoCant; i++) {
        original[i] = nuevo[i];
    }
    cantOriginal = nuevoCant;
}
