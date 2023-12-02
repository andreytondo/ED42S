/*
1. O código abaixo imprime os valores e endereços de um vetor e de uma string.Por que os
    endereços do vetor v aumentam de 4 em 4 e os endereços da string c aumentam de 1 em 1?

    Pois o tamanho do caractere é 1 byte e o tamanho do inteiro é 4 bytes.
*/

#include <stdio.h>
#include <string.h>
    void
    main(void)
{
    int v[] = {1, 2, 3, 4, 5};
    char s[] = "ola";
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("valor: %d, end.: %ld, sizeof: %d\n,", v[i], &v[i], sizeof(v[i]));
    }
    printf("\n");
    for (i = 0; i < strlen(s); i++)
    {
        printf("valor: %c, end.: %ld, sizeof: %d\n", s[i], &s[i], sizeof(s[i]));
    }
}