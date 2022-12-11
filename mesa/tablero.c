#include "tablero.h"

int main(){
    printf("Comensamos \n");
    Dados tirada;
    bool flag = true;
    int indice, jugadores = 1;
    pthread_t npcs[MAX_NUM_NPC];

    srand(time(NULL));
    
    while(flag){
        jugadores = esperaJugador();
        for(indice = 0 ; indice < jugadores ; indice++){
            npcs[indice]= creaNpc();
        }

    }
    tirada.cantidad = CANTIDAD_DADOS_DEFECTO;
    tirada = usaCubilete(tirada);


    printf("Salio un %d y un %d.\n", tirada.numeros[0], tirada.numeros[1]);

    dibujaDado(tirada);
    return(0);
}

int esperaJugador(){
    int jugadores = 0;

    return(jugadores);
}

pthread_t *creaNpc(){

}

void *rutinaNpc(){
    bool npc = true;
    int espera = tiempoAleatorio();
    sleep(espera);
    cogerCubilete();
    hacerTirada();
    soltarCubilete();
    leerResultado(npc);
}

int tiempoAleatorio(){
    int tiempo = 0;

    return(tiempo);
}