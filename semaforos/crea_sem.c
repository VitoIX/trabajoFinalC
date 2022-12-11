#include "crea_sem.h"

int main(int argc, char *argv[])
{
  sem_t *semaforo=NULL;
  char *nombre = argv[1];
  int valor = atoi(argv[2]);
  if (argc !=3){
  	printf("Numero de argumentos incorrecto, debe ser nombre del semaforo y valor inicial \n");
  }
  else{
  	semaforo= sem_open(nombre,O_CREAT,0600,valor);
  	printf("Semaforo de nombre %s y valor %d ha sido creado \n",nombre,valor);
  }
  return (0);
}