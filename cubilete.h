#if !defined(TAMANO_DADO)
#define TAMANO_DADO 6
#endif // tamaño de los dados

#if !defined(CANTIDAD_DADOS_DEFECTO)
#define CANTIDAD_DADOS_DEFECTO 2
#endif // CANTIDAD_DADOS

#if !defined(MAX_CANT_DADOS)
#define MAX_CANT_DADOS 5
#endif // MAX_CANT_DADOS



/*ESTRUCTURAS*/

typedef struct dados
{
    /* data */
    int cantidad = CANTIDAD_DADOS_DEFECTO;
    int numeros[MAX_CANT_DADOS] = {0, 0, 0, 0, 0};
} Dados;


/*CABECERAS*/

int aleatorio();
Dados usaCubilete(Dados);