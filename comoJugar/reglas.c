
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

bool cogerCubilete(){
    bool turno = false;


    return(turno);
}

bool soltarCubilete(){
    bool resultado = false;
    return(resultado);
}

int hacerTirada(){
    int resultado = -1;
    return(resultado);
}

int leerResultado(bool npc){
    int resultado;
    return(resultado);
}

