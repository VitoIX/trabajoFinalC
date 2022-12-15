#ifndef _tablero_h
#define _tablero_h

#include "inclusion.h"
#include "../comoJugar/reglas.h"

#include "usaCubilete.h"
#include "dibujaDado.h"


#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

#define MAX_NUM_NPC 3
#define ARG_SEM_INICIO 1
#define ESPERA_MAX_NPC 6

int esperaInicio(char *);
void creaNpc(pthread_t *);
void *rutinaNpc();
int tiempoAleatorio();

#endif