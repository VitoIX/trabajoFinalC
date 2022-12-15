#ifndef _reglas_h
#define _reglas_h

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/msg.h>
#include <string.h>

/*includes semaforos */
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

/*MEMORIA COMPARTIDA*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>


#define LIMITE_JUGADORES 4
#define GANAR 1
#define PERDER 0
#define EMPATE 3

#define INDICE_JUGADOR 168


#define ASCII_CERO 48

#define MSG_VICTORIA "VICTORIA\n"
#define MSG_DERROTA "DERROTA\n"
#define MSG_EMPATE "EMPATE\n"

/*SEMAFOROS*/

#define SEM_CUBILETE "cubilete"

/*MEMORIA COMPARTIDA*/
#define MEMORIA_INDICE_JUGADOR 0  //debe ser 0 porque en algun lugar los npcs los recorro sumandole a esto




#define TIPO_MSG_TIRADA 14
#define TIPO_MSG_LEER_RESULTADO 12
#define TIPO_MSG_INICIAR 231

#define MSG_TIRADA '9'

#define MAX_SEND_SIZE 80

struct mymsgbuf{
 long mtype;
 char mtext[MAX_SEND_SIZE];
}; 

int jugarPartida(int, char *);
bool cogerCubilete();
int hacerTirada(int);
bool soltarCubilete();
int leerGanador(bool, char*);

int escr_msg(int qid,struct mymsgbuf *qbuf);
int leer_msg(int qid,long type,struct mymsgbuf *qbuf); 

void comenzarPartida(char);
int esperaNumJugadores();



#endif