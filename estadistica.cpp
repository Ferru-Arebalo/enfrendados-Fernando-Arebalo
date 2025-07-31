#include <iostream>
#include "estadistica.h"
#include "utilidades.h"
using namespace std;

void mostrarEstadisticas(string mejorJugador, int mayorPuntaje) {
    cout << "\nESTADISTICAS\n";
    if (mayorPuntaje > 0)
        cout << "Mayor puntaje: " << mejorJugador << " con " << mayorPuntaje << " puntos.\n";
    else
        cout << "No se han jugado partidas.\n";
    pausar();
}
