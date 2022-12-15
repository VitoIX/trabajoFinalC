#include "tablero.h"

int main(int argc, char *argv[]){  //tablero debe recibir un parametro con el nombre dle semaforo de inicio, con el que espera al jugador
    printf("Comensamos \n");
    Dados tirada;
    bool flag = true;
    int indice, jugadores = 1;
    pthread_t npcs[MAX_NUM_NPC];


    //SEMAFOROS
    char *nombre = argv[ARG_SEM_INICIO];
    //sem_t *semInicio = sem_open(nombre, O_CREAT, 0600, 0); //este semaforo binario esta inicializado a 0, me da error si lo creo con (nombre,0)
    

    srand(time(NULL));
    
    while(flag){
        jugadores = esperaInicio(nombre);
        //sem_wait(semInicio); //esperamos que el jugador pida empezar a jugar
        for(indice = 0 ; indice < jugadores - 1 ; indice++){
            creaNpc(&npcs[indice]);
            //pthread_join(npcs[indice], NULL);
        }
        
        flag = false;
    }
    tirada.cantidad = CANTIDAD_DADOS_DEFECTO;
    tirada = usaCubilete(tirada);


    printf("Salio un %d y un %d.\n", tirada.numeros[0], tirada.numeros[1]);

    dibujaDado(tirada);
    //sem_close(semInicio);
    return(0);
}

int esperaInicio(char *nombre){
    int numJugadores = -1;    
    //sem_wait(semInicio); en windows los semaforos no funcionan bien si los crea otro proceso
    sem_t *semInicio = sem_open(nombre, O_CREAT, 0600, 0);
    printf("Esperando inicio\n");
    sem_wait(semInicio);
    printf("Me canse de esperar a ver cuantos juegan\n");
    numJugadores = esperaNumJugadores();

    return(numJugadores);
}

void creaNpc(pthread_t *hilo){
    pthread_create(hilo, NULL, rutinaNpc, NULL);
}

void *rutinaNpc(){
    bool npc = true;
    int espera = tiempoAleatorio();
    char *ganador = NULL;
    sleep(espera);
    cogerCubilete();
    hacerTirada();
    soltarCubilete();
    leerGanador(npc, ganador);
    /*sleep(2);
    printf("rutina npc \n");*/
}

int tiempoAleatorio(){
    int tiempo = (rand() % (ESPERA_MAX_NPC)) + 1; //tiempo de espera aleatorio entre 1 y ESPERA_MAX_NPC

    return(tiempo);
}