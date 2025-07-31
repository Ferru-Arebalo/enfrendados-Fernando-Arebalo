#pragma once
#include <string>

using namespace std;
int pedirEntero(string mensaje);
void pausar();
bool esSumaValida(int seleccionados[], int cantidad, int objetivo);
int calcularPuntaje(int cantidadDados, int objetivo);
void copiarStockSinUsados(int original[], int &cantOriginal, int usados[], int cantUsados);

