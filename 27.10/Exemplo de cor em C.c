#include "stdio.h"

int main()
{
    printf("\x1B[44m");
    printf("\x1B[97m");
    printf("\x1B[12;30H");
    printf("Como essa frase sera apresentada na tela?");
    printf("\x1B[0m");

    return 0;
}
