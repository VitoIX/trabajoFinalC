#ifndef _reglas_h
#define _reglas_h

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
//#include <sys/msg.h>
#include <string.h>



#define LIMITE_JUGADORES 4
#define GANAR 1
#define PERDER 0
#define EMPATE 3

#define MSG_VICTORIA "VICTORIA\n"
#define MSG_DERROTA "DERROTA\n"
#define MSG_EMPATE "EMPATE\n"

#define MAX_SEND_SIZE 80

int jugarPartida(int);
bool cogerCubilete();
int hacerTirada();
bool soltarCubilete();
int leerResultado(bool);

struct mymsgbuf{
 long mtype;
 char mtext[MAX_SEND_SIZE];
}; 

#endif