#include <stdbool.h>

#ifndef stdio_h
#include <stdio.h>
#endif

#define LIMITE_JUGADORES 4
#define GANAR 1
#define PERDER 0
#define EMPATE 3

#define MSG_VICTORIA "VICTORIA\n"
#define MSG_DERROTA "DERROTA\n"
#define MSG_EMPATE "EMPATE\n"

int jugarPartida(int);
bool cogerCubilete();
int hacerTirada();
bool soltarCubilete();
int leerResultado(bool);
