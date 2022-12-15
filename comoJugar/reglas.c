
#include "reglas.h"


int jugarPartida(int jugadores, char *ganador){ //esta funcion solo la ejecutan los jugadores, los npcs no
    int resultado;
    bool pnj = false;
    printf("Weno vamo a juga %d\n",jugadores);
    cogerCubilete();
    hacerTirada();
    soltarCubilete();
    resultado = leerGanador(pnj, ganador);
    
    return(resultado);
}

bool cogerCubilete(){  //el semaforo cubilete es un semaforo binario inicializado a 1
    bool turno = false;
	 sem_t *cubilete = NULL;
	 char *nombre = NULL;
	 nombre = SEM_CUBILETE; //guardo nombre del semaforo
	 printf("abro semaforo cubilete \n");
	 cubilete = sem_open(nombre, 0); //abrimos el semaforo binario
	 printf("Procedo a bajar el semaforo cubilete \n");
	 sem_wait(cubilete); //bajo el semaforo
	 sem_close(cubilete);
	 turno = true;

    return(turno);
}

bool soltarCubilete(){
    bool resultado = false;
    sem_t *cubilete = NULL;
	 char *nombre = NULL;
	 nombre = SEM_CUBILETE; //guardo nombre del semaforo
	 cubilete = sem_open(nombre, 0); //abrimos el semaforo binario
	 printf("Procedo a subir el semaforo cubilete \n");
	 sem_post(cubilete);
	 sem_close(cubilete);

	 resultado = true;
    return(resultado);
}

int hacerTirada(){
    int resultado = -1;
    
    //PREPARO LA COLA DE MENSAJES
    key_t clave;
 	 int msgqueue_id;
 	 long tipo = TIPO_MSG_TIRADA;
 	 struct mymsgbuf qbuffer;
 	 clave=ftok(".",'m');
 	 
 	 char *mensaje = MSG_TIRADA;
 	 
 	 if ((msgqueue_id=msgget(clave,IPC_CREAT|0660))==-1) //iniciamos la cola
 		{
 			printf("Error al iniciar la cola\n");
 		}
 	 else{
 	 	qbuffer.mtype = tipo;
 	 	strncpy(qbuffer.mtext, mensaje, MAX_SEND_SIZE-1);
 	 	escr_msg(msgqueue_id, &qbuffer);
 	 	printf("Mensaje de tirada enviado \n");
 	 	resultado = 1;
 	 }
        
    
    return(resultado);
}

int leerGanador(bool npc, char *ganador){
    int resultado = -1;

	key_t clave;
 	int msgqueue_id;
 	long tipo = TIPO_MSG_LEER_RESULTADO;
 	struct mymsgbuf qbuffer;
 	clave=ftok(".",'m');

	if(npc){
		printf("npc va a leer mensaje \n");
		leer_msg(msgqueue_id, tipo, &qbuffer);
		printf("npc leyo mensaje \n");
	}
	else{
		printf("Jugador va a leer ganador \n");
		leer_msg(msgqueue_id, tipo, &qbuffer);
		strncpy(ganador, qbuffer.mtext, MAX_SEND_SIZE - 1);
	}
 	 


    return(resultado);
}

int escr_msg(int qid,struct mymsgbuf *qbuf) 
{ 
   int resultado;
   
   resultado=msgsnd(qid,qbuf,MAX_SEND_SIZE,0);
   printf("Enviando mensaje...\n");
      
   return (resultado);

} 

int leer_msg(int qid,long type,struct mymsgbuf *qbuf) 
{ 
   int resultado;
   
   resultado=msgrcv(qid,qbuf,MAX_SEND_SIZE,type,0); 
    
   return (resultado); 
} 

void comenzarPartida(char numJugadores){
    char mensaje[2];
    mensaje[0] = numJugadores;
    //printf("iniciando partida \n");
    mensaje[1] = '\0';
    //printf("%s \n", mensaje);

    //PREPARO LA COLA DE MENSAJES
    key_t clave;
 	 int msgqueue_id;
 	 long tipo = TIPO_MSG_INICIAR;
 	 struct mymsgbuf qbuffer;
 	 clave=ftok(".",'m');
 	 
 	 if ((msgqueue_id=msgget(clave,IPC_CREAT|0660))==-1) //iniciamos la cola
 		{
 			printf("Error al iniciar la cola\n");
 		}
 	 else{
 	 	qbuffer.mtype = tipo;
 	 	strncpy(qbuffer.mtext, mensaje, 2);
 	 	escr_msg(msgqueue_id, &qbuffer);
 	 	printf("Mensaje de iniciar enviado \n"); 	 	
 	 }
}

int esperaNumJugadores(){
	int numJugadores = -1;
	char *mensaje = NULL;
	key_t clave;
 	 int msgqueue_id;
 	 long tipo = TIPO_MSG_INICIAR;
 	 struct mymsgbuf qbuffer;
 	 clave=ftok(".",'m');

	 leer_msg(msgqueue_id, tipo, &qbuffer);
	strncpy(mensaje, qbuffer.mtext, 2);
	numJugadores = mensaje[0] - ASCII_CERO;

	return(numJugadores);
}