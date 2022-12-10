#include "inclusion.h"

int main(){
    printf("Comensamos \n");
    Dados tirada;

    srand(time(NULL));

    tirada.cantidad = CANTIDAD_DADOS_DEFECTO;
    tirada = usaCubilete(tirada);


    printf("Salio un %d y un %d.\n", tirada.numeros[0], tirada.numeros[1]);
    return(0);
}