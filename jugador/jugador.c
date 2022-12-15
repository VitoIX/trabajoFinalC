#include "jugador.h"


int main(int argc, char *argv[]){
    char seleccion;
    int resultado = -1;
    bool flag = true;
    bool cancelar = false;
    char *ganador = NULL;

    char *nombre = argv[ARG_SEM_INICIO];

    while (flag)
    {
        printf("Bienvenido al jueguito de dados, \168Qu\202 quieres hacer? \n");
        printf("Pulsa un boton para: \n");
        printf(" 1: Iniciar una partida nueva. \n 2: Salir del juego.\n ");

        //seleccion = getch() - ASCII_CERO;
        seleccion = getch() ;
        printf("%c\n",seleccion);
        switch (seleccion)
        {
        case '1':
            printf("Introduce el n\243mero de jugadores (2 - LIMITE_JUGADORES).\n");
            //seleccion = getch() - ASCII_CERO;
            seleccion = getch() ;
            while(!(seleccion >= '2' && seleccion <= '4')){
                printf("Valor introducido incorrecto, introduce el numero de jugadores entre 2 y LIMITE_JUGADORES \n");
                printf("Introduce q para cancelar.\n");
                seleccion = getch();
                if(seleccion  == 'q' || seleccion  == 'Q'){
                    cancelar = true;
                    break;
                }
            }
            if(cancelar == true){
                cancelar = false;
            }
            else{//el valor esta bien introducido y no quiere salir
                //printf("Voy a iniciar partida \n");
                comenzarPartida(seleccion, nombre);
                resultado = jugarPartida(seleccion, ganador);
                imprimeResultado(resultado, ganador);
                printf("Pulsa un bot\243n para continuar \n");
                getch();
                
            }
            break;
        case '2':
            flag = false;
            break;
        default:
            printf("Valor introducido no v\240lido. \n");
            break;
        }

        //getch();
    }
    

    return(0);
}


void imprimeResultado(int resultado, char *ganador){
    if(resultado == GANAR){
        printf(MSG_VICTORIA);
    }
    else if (resultado == PERDER)
    {
        printf(MSG_DERROTA);
        printf("El ganador es el NPC%s\n", ganador);
        //añadir un lee tirada para ver cuanto saca jugador y quien ganó
    }
    else if (resultado == EMPATE)
    {
        printf(MSG_EMPATE);
    }    
    else{
        printf("Algo ha fallado %d\n", resultado);
    }
    

}