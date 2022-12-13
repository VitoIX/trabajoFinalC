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

int esperaInicio();
void creaNpc(pthread_t *);
void *rutinaNpc();
int tiempoAleatorio();