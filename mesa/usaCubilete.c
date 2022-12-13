#include "inclusion.h"
#include "usaCubilete.h"

Dados usaCubilete(Dados tirada){
    int indice;

    for(indice = 0; indice < tirada.cantidad ; indice++){
        tirada.numeros[indice] = aleatorio();
    }
    


    return(tirada);
}

int aleatorio(){ // funcion que devuelve un número aleatorio entre 1 y TAMAÑO_DADO
    int numero = 0; //un dado no puede valer 0 si vale 0 algo falló

    numero = (rand() % (TAMANO_DADO)) + 1; //numero aleatorio entre 1 y TAMAÑO_DADO

    return(numero);
}