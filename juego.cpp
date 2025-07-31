#include <iostream>
#include "juego.h"
#include "dados.h"
#include "utilidades.h"

void jugarTurno(string nombres[], int puntajes[], int stock[][20], int cantidadStock[], int actual, int rival) {
    cout << "\nTurno de " << nombres[actual] << endl;
    int objetivo = tirarDosDados12();
    cout << "Dados del jugador: ";
    mostrarDados(stock[actual], cantidadStock[actual]);

    int seleccionados[20];
    int cantSeleccionados = 0;
    int suma = 0;
    while (true) {
        for (int i = 0; i < cantidadStock[actual]; i++) {
            cout << i + 1 << ": " << stock[actual][i] << endl;
        }
        int eleccion = pedirEntero("Selecciona el numero del dado (0 para terminar): ");
        if (eleccion == 0) break;
        if (eleccion >= 1 && eleccion <= cantidadStock[actual]) {
            int val = stock[actual][eleccion - 1];
            seleccionados[cantSeleccionados++] = val;
            suma += val;
            if (suma >= objetivo) break;
        } else {
            cout << "Opcion invalida.\n";
        }
    }

    if (esSumaValida(seleccionados, cantSeleccionados, objetivo)) {
        int puntos = calcularPuntaje(cantSeleccionados, objetivo);
        puntajes[actual] += puntos;

        cout << "\nTirada exitosa!\n";
        cout << "Puntos ganados: " << puntos << endl;
        cout << "Dados transferidos: " << cantSeleccionados << endl;

        copiarStockSinUsados(stock[actual], cantidadStock[actual], seleccionados, cantSeleccionados);

        for (int i = 0; i < cantSeleccionados; i++) {
            stock[rival][cantidadStock[rival]++] = seleccionados[i];
        }

        if (cantidadStock[actual] == 0) {
            cout << nombres[actual] << " gano automaticamente!\n";
            puntajes[actual] += 10000;
        }
    } else {
        cout << "\nTirada no exitosa.\n";
        if (cantidadStock[rival] > 1) {
            int nuevoDado = tirarDado(6);
            stock[actual][cantidadStock[actual]++] = nuevoDado;
            cout << nombres[actual] << " recibe un dado extra.\n";
        } else {
            cout << "El rival no tiene dados suficientes para penalizar.\n";
        }
    }
    pausar();
}

void jugarPartida(string &mejorJugador, int &mayorPuntaje) {
    string nombres[2];
    int puntajes[2] = {0, 0};
    int stock[2][20];
    int cantidadStock[2] = {0, 0};

    cout << "Nombre del jugador 1: ";
    cin >> nombres[0];
    cout << "Nombre del jugador 2: ";
    cin >> nombres[1];

    tirarDadosStock(stock[0], cantidadStock[0]);
    tirarDadosStock(stock[1], cantidadStock[1]);

    int primero = tirarDado(6), segundo = tirarDado(6);
    int turno = (primero >= segundo) ? 0 : 1;

    for (int ronda = 1; ronda <= 3; ronda++) {
        cout << "\n========= RONDA " << ronda << " =========\n";
        jugarTurno(nombres, puntajes, stock, cantidadStock, turno, 1 - turno);
        if (cantidadStock[turno] == 0) break;
        jugarTurno(nombres, puntajes, stock, cantidadStock, 1 - turno, turno);
        if (cantidadStock[1 - turno] == 0) break;
    }

    cout << "\n===== RESULTADOS FINALES =====\n";
    for (int i = 0; i < 2; i++) {
        cout << nombres[i] << ": " << puntajes[i] << " puntos\n";
    }

    if (puntajes[0] > puntajes[1]) {
        cout << "Ganador: " << nombres[0] << endl;
        if (puntajes[0] > mayorPuntaje) {
            mayorPuntaje = puntajes[0];
            mejorJugador = nombres[0];
        }
    } else if (puntajes[1] > puntajes[0]) {
        cout << "Ganador: " << nombres[1] << endl;
        if (puntajes[1] > mayorPuntaje) {
            mayorPuntaje = puntajes[1];
            mejorJugador = nombres[1];
        }
    } else {
        cout << "Empate!\n";
    }
    pausar();
}
