#ifndef _reglas_h
#define _reglas_h

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/msg.h>
#include <string.h>

/*includes semaforos */
#include <semaphore.h>
//#include <fcntl.h>
//#include <unistd.h>
#include <pthread.h>


#define LIMITE_JUGADORES 4
#define GANAR 1
#define PERDER 0
#define EMPATE 3

#define ASCII_CERO 48

#define MSG_VICTORIA "VICTORIA\n"
#define MSG_DERROTA "DERROTA\n"
#define MSG_EMPATE "EMPATE\n"

/*SEMAFOROS*/

#define SEM_CUBILETE "cubilete"


#define TIPO_MSG_TIRADA 14
#define TIPO_MSG_LEER_RESULTADO 12
#define TIPO_MSG_INICIAR 231

#define MSG_TIRADA "tirada"

#define MAX_SEND_SIZE 80

struct mymsgbuf{
 long mtype;
 char mtext[MAX_SEND_SIZE];
}; 

int jugarPartida(int, char *);
bool cogerCubilete();
int hacerTirada();
bool soltarCubilete();
int leerGanador(bool, char*);

int escr_msg(int qid,struct mymsgbuf *qbuf);
int leer_msg(int qid,long type,struct mymsgbuf *qbuf); 

void comenzarPartida(char);
int esperaNumJugadores();



#endif