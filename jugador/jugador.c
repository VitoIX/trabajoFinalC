#include "jugador.h"


int main(){
    int seleccion;
    int resultado = -1;
    bool flag = true;
    bool cancelar = false;
    while (flag)
    {
        printf("Bienvenido al jueguito de dados, \168Qu\202 quieres hacer? \n");
        printf("Pulsa un boton para: \n");
        printf(" 1: Iniciar una partida nueva. \n 2: Salir del juego.\n ");

        seleccion = getch() - ASCII_CERO;
        //printf("%d",seleccion);
        switch (seleccion)
        {
        case 1:
            printf("Introduce el n\243mero de jugadores (2 - LIMITE_JUGADORES).\n");
            seleccion = getch() - ASCII_CERO;
            while(!(seleccion >= 2 && seleccion <= LIMITE_JUGADORES)){
                printf("Valor introducido incorrecto, introduce el numero de jugadores entre 2 y LIMITE_JUGADORES \n");
                printf("Introduce q para cancelar.\n");
                seleccion = getch() - ASCII_CERO;
                if(seleccion  == 'q' - ASCII_CERO || seleccion  == 'Q' - ASCII_CERO){
                    cancelar = true;
                    break;
                }
            }
            if(cancelar == true){
                cancelar = false;
            }
            else{//el valor esta bien introducido y no quiere salir
                resultado = jugarPartida(seleccion);
                imprimeResultado(resultado);
                
            }
            break;
        case 2:
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


void imprimeResultado(int resultado){
    if(resultado == GANAR){
        printf(MSG_VICTORIA);
    }
    else if (resultado == PERDER)
    {
        printf(MSG_DERROTA);
    }
    else if (resultado == EMPATE)
    {
        printf(MSG_EMPATE);
    }    
    else{
        printf("Algo ha fallado, resultado");
    }
    

}