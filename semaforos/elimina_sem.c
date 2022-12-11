#include "elimina_sem.h"

int main(int argc, char *argv[]){
  if( argc != 2){
  	printf("Numero de argumentos incorrecto, nombre de semaforo a eliminar. \n");
  }
  else{
  	if( !sem_unlink(argv[1])){
  		printf("Semaforo %s borrado \n", argv[1]);
  	}
  	else{
  		printf("Error al borrar semaforo \n");
  	}
  }
  
  
  
  return(0);
}