#ifndef _reglas_h
#define _reglas_h

#include <stdbool.h>
#include <stdio.h>


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

#endif