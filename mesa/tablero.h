#include "inclusion.h"
#include "../comoJugar/reglas.h"

#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_NUM_NPC 3

int esperaJugador();
pthread_t *creaNpc();
void *rutinaNpc();
int tiempoAleatorio();