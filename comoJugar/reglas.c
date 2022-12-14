
#include "reglas.h"


int jugarPartida(int jugadores){
    int resultado;
    bool pnj = false;
    printf("Weno vamo a juga %d\n",jugadores);
    cogerCubilete();
    hacerTirada();
    soltarCubilete();
    resultado = leerResultado(pnj);
    
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

int leerResultado(bool npc){
    int resultado;
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