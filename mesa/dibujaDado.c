#include "inclusion.h"
#include "dibujaDado.h"


void dibujaDado(Dados dado) {
    char *cara[6][5] = {{"+-------+\n", "|       |\n", "|   *   |\n", "|       |\n", "+-------+\n"}, //1
                       {"+-------+\n", "| *     |\n", "|       |\n", "|     * |\n", "+-------+\n"}, //2
                       {"+-------+\n", "| *     |\n", "|   *   |\n", "|     * |\n", "+-------+\n"}, //3
                       {"+-------+\n", "| *   * |\n", "|       |\n", "| *   * |\n", "+-------+\n"}, //4
                       {"+-------+\n", "| *   * |\n", "|   *   |\n", "| *   * |\n", "+-------+\n"}, //5
                       {"+-------+\n", "| *   * |\n", "| *   * |\n", "| *   * |\n", "+-------+\n"}};
    char *carab[6][5] = {{"+-------+", "|       |", "|   *   |", "|       |", "+-------+"}, //1
                       {"+-------+", "| *     |", "|       |", "|     * |", "+-------+"}, //2
                       {"+-------+", "| *     |", "|   *   |", "|     * |", "+-------+"}, //3
                       {"+-------+", "| *   * |", "|       |", "| *   * |", "+-------+"}, //4
                       {"+-------+", "| *   * |", "|   *   |", "| *   * |", "+-------+"}, //5
                       {"+-------+", "| *   * |", "| *   * |", "| *   * |", "+-------+"}};
for(int i = 0 ; i < 5 ; i++){
    printf("%s", carab[dado.numeros[0] - 1][i]);
    printf("%s",cara[dado.numeros[1] - 1][i]);
}
/*
    if (face < 1 || face > 6) {
        printf("Invalid dice face: %d\n", face);
        return;
    }

    switch (face) {
        case 1:
            printf("+-------+\n");
            printf("|       |\n");
            printf("|   *   |\n");
            printf("|       |\n");
            printf("+-------+\n");
            break;
        case 2:
            printf("+-------+\n");
            printf("| *     |\n");
            printf("|       |\n");
            printf("|     * |\n");
            printf("+-------+\n");
            break;
        case 3:
            printf("+-------+\n");
            printf("| *     |\n");
            printf("|   *   |\n");
            printf("|     * |\n");
            printf("+-------+\n");
            break;
        case 4:
            printf("+-------+\n");
            printf("| *   * |\n");
            printf("|       |\n");
            printf("| *   * |\n");
            printf("+-------+\n");
            break;
        case 5:
            printf("+-------+\n");
            printf("| *   * |\n");
            printf("|   *   |\n");
            printf("| *   * |\n");
            printf("+-------+\n");
            break;
        case 6:
            printf("+-------+\n");
            printf("| *   * |\n");
            printf("| *   * |\n");
            printf("| *   * |\n");
            printf("+-------+\n");
            break;
        default:
            printf("Invalid dice face: %d\n", face);
            break;
    }*/
}
