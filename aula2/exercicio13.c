/*
13. Implemente uma função que copia o conteúdo de uma string de origem em uma string
de destino. O protótipo da função deve ser void copia_string(char *destino, char *origem).
Utilize ponteiros.
*/

#include <stdio.h>

void copia_string(char *destino, char *origem)
{
    char *p, *q;
    
    for (p = destino, q = origem; *q != '\0'; p++, q++) {
        *p = *q;
    }

    *p = '\0';
}

void main(void)
{
    char origem[] = "Hello, World!";
    char destino[20];
    copia_string(destino, origem);
    printf("%s\n", destino);
}