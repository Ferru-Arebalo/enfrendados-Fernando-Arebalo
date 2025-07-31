#include <iostream>
#include <string>
#include "juego.h"
#include "estadistica.h"
#include "utilidades.h"
using namespace std;

        ///Rellenar con mis compañeros y los profesores
void mostrarCreditos() {
    cout << "\nCREDITOS\n";
    cout << "Equipo: Enfrentados++\n";
    cout << "- Integrante 1 - Legajo: X\n";
    cout << "- Integrante 2 - Legajo: X\n";
    pausar();
}

void mostrarMenu() {
    int mayorPuntaje = 0;
    string mejorJugador = "";
    int opcion;
    do {
        cout << "\n==== MENU PRINCIPAL ====\n";
        cout << "1 - JUGAR\n";
        cout << "2 - ESTADISTICAS\n";
        cout << "3 - CREDITOS\n";
        cout << "0 - SALIR\n";
        opcion = pedirEntero("Elige una opcion: ");

        switch (opcion) {
            case 1: jugarPartida(mejorJugador, mayorPuntaje); break;
            case 2: mostrarEstadisticas(mejorJugador, mayorPuntaje); break;
            case 3: mostrarCreditos(); break;
            case 0:
                char confirmar;
                cout << "Seguro que quieres salir? (s/n): ";
                cin >> confirmar;
                if (confirmar != 's' && confirmar != 'S') opcion = -1;
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    cout << "\nGracias por jugar Enfrentados!\n";
}
