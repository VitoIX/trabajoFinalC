#ifndef reglas_h
#include "reglas.h"
#endif

int jugarPartida(int jugadores){
    int resultado;
    printf("Weno vamo a juga %d\n",jugadores);
    cogerCubilete();
    hacerTirada();
    soltarCubilete();
    resultado = leerResultado();
    
    return(resultado);
}

bool cogerCubilete(){
    bool turno = false;


    return(turno);
}

bool soltarCubilete(){
    bool resultado = false;
    return(resultado);
}

int hacerTirada(){
    int resultado;
    return(resultado);
}

int leerResultado(){
    int resultado;
    return(resultado);
}

