#include "tablero.h"

int main(int argc, char *argv[]){  //tablero debe recibir un parametro con el nombre dle semaforo de inicio, con el que espera al jugador
    printf("Comensamos \n");
    Dados tirada,tiradaMax;
    bool flag = true;
    int indice, jugadores = 1;
    pthread_t npcs[MAX_NUM_NPC];
    bool empate = false; //esto es temporal habria que mejorarlo


    //SEMAFOROS
    char *nombre = argv[ARG_SEM_INICIO];
    //sem_t *semInicio = sem_open(nombre, O_CREAT, 0600, 0); //este semaforo binario esta inicializado a 0, me da error si lo creo con (nombre,0)
    

    /*MEMORIA COMPARTIDA*/
    key_t clave;
    int shmid;
    //char *seg;
    clave=ftok(".",'S');
    if((shmid=shmget(clave,(MAX_NUM_NPC + 1) * sizeof(Dados),IPC_CREAT|IPC_EXCL|0660))==-1)
    {
        printf("El segmento de memoria compartida ya existe\n");
        printf(" Abriendo como cliente\n");
        if((shmid=shmget(clave,(MAX_NUM_NPC + 1) * sizeof(Dados),0))==-1)
            {printf("Error al abrir el segmento\n");}
    }
    else{
        printf("Segmento de memoria creado");
    }

    srand(time(NULL));
    
    tirada.cantidad = CANTIDAD_DADOS_DEFECTO;
    tiradaMax.cantidad = CANTIDAD_DADOS_DEFECTO;
    while(flag){
        jugadores = esperaInicio(nombre);
        //sem_wait(semInicio); //esperamos que el jugador pida empezar a jugar
        for(indice = 0 ; indice < jugadores - 1 ; indice++){ //la cantidad de npcs a crear es jugadores - 1, ese 1 es el jugador
            creaNpc(&npcs[indice], indice);
            //pthread_join(npcs[indice], NULL);
        }
        for(indice = 0 ; indice < jugadores ; indice++){
            tirada = esperaTirada(tirada);
            printf("Tirada del");
            if(tirada.id == ID_JUGADOR){
                printf(" Jugador: \n");
            }
            else{
                printf(" NPC%d\n",tirada.id);
            }
            dibujaDado(tirada);
            printf("----------------------------\n");
            almacenaTirada(tirada, shmid);
            switch (comparaTiradas(tiradaMax, tirada))  //sera ganar si la nueva tirada, aspirante, es mayor
            {
            case GANAR:
                if(empate == true){
                    empate = false;
                }
                tiradaMax = tirada;
                break;
            case PERDER:
                break;

            case EMPATE: //demomento si hay empate teiene prioridad el primero
                empate = true;
                break;
            default:
                printf("Algo fallo comparando las tiradas \n");
                break;
            }
        }
        anunciaGanador(tiradaMax);

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
    sem_t *semInicio = sem_open(nombre, 0);
    printf("Esperando inicio\n");
    sem_wait(semInicio);
    printf("Me canse de esperar a ver cuantos juegan\n");
    numJugadores = esperaNumJugadores();
    printf("estoy en esperaInicio seran %d juigadores",numJugadores);
    sem_close(semInicio);
    return(numJugadores);
}

void creaNpc(pthread_t *hilo, int indice){
    pthread_create(hilo, NULL, rutinaNpc, &indice);
}

void *rutinaNpc(void *indice){
    bool npc = true;
    int espera = tiempoAleatorio();
    char *ganador = NULL;
    sleep(espera);
    cogerCubilete();
    hacerTirada(*((int *)indice));
    soltarCubilete();
    leerGanador(npc, ganador);
    /*sleep(2);
    printf("rutina npc \n");*/
}

int tiempoAleatorio(){
    int tiempo = (rand() % (ESPERA_MAX_NPC)) + 1; //tiempo de espera aleatorio entre 1 y ESPERA_MAX_NPC

    return(tiempo);
}

Dados esperaTirada(Dados tirada){
tirada.cantidad = CANTIDAD_DADOS_DEFECTO;
    char *mensaje = NULL;
    key_t clave;
 	int msgqueue_id;
 	long tipo = TIPO_MSG_TIRADA;
 	struct mymsgbuf qbuffer;
 	clave=ftok(".",'m');
    if ((msgqueue_id=msgget(clave,IPC_CREAT|0660))==-1) //iniciamos la cola
 	{
 			printf("Error al iniciar la cola\n");
 	}
    else{
        leer_msg(msgqueue_id, tipo, &qbuffer);
        strncpy(mensaje, qbuffer.mtext, 2);

        if(mensaje[0] == MSG_TIRADA){
            tirada.id = ID_JUGADOR;
        }
        else{//es un NPC
            tirada.id = mensaje[0];
        }

        tirada = usaCubilete(tirada);
    }
    return(tirada);
}
int comparaTiradas(Dados tiradaMax, Dados tirada){
    int resultado = -1;
    int sumaMax,suma;
    int indice;
    for(indice = 0; indice < tiradaMax.cantidad ; indice++){
        sumaMax = sumaMax + tiradaMax.numeros[indice];
    }
    for(indice = 0; indice < tirada.cantidad ; indice++){
        suma = suma + tirada.numeros[indice];
    }
    if(suma > sumaMax){
        resultado = GANAR;
    }
    else if (suma < sumaMax)
    {
        resultado = PERDER;
    }
    else{
        resultado = EMPATE;
    }
    

    return(resultado);
}

void almacenaTirada(Dados tirada, int shmid){
    Dados *seg = NULL;

    if((seg=shmat(shmid,NULL,0))== (char *)-1)
        printf("Error al mapear el segmento\n");
    else{
        if(tirada.id == ID_JUGADOR){
            seg[MEMORIA_INDICE_JUGADOR] = tirada;
        }
        else{
            seg[MEMORIA_INDICE_JUGADOR + tirada.id] = tirada;
        }
    }
shmdt(seg); //des-mapeo el segmento de memoria

}
void anunciaGanador(Dados tirada){
    key_t clave;
 	int msgqueue_id;
 	long tipo = TIPO_MSG_LEER_RESULTADO;
 	struct mymsgbuf qbuffer;
 	clave=ftok(".",'m');
    char *mensaje = NULL;
    mensaje[1] = '\0';

    if ((msgqueue_id=msgget(clave,IPC_CREAT|0660))==-1) //iniciamos la cola
 	{
 			printf("Error al iniciar la cola\n");
 	}
    else{

        if(tirada.id == ID_JUGADOR){
            mensaje[0] = MEMORIA_INDICE_JUGADOR;
        }
        else{
            mensaje[0] = tirada.id;
        }
        qbuffer.mtype = tipo;
            strncpy(qbuffer.mtext, mensaje, MAX_SEND_SIZE-1);
            escr_msg(msgqueue_id, &qbuffer);
            printf("Mensaje de anuncio de Ganador enviado \n");
    }
}