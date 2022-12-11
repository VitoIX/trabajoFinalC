#ifndef jugador_h
#include <stdbool.h>
#endif

#define GANAR 1
#define PERDER 0
#define EMPATE 3

int jugarPartida(int);
bool cogerCubilete();
int hacerTirada();
bool soltarCubilete();
int leerResultado();
