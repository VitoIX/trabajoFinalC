#include "jugador.h"

int main(){
    int seleccion;
    bool flag = true;
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
            /* code */
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