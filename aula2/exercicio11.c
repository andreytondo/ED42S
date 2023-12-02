/*
11. Escreva uma função que imprime uma string. Percorra os itens da string através de
aritmética de ponteiros.
*/

#include <stdio.h>

void imprime(char *s)
{
    char *p;
    for (p = s; *p != '\0'; p++)
    {
        printf("%c", *p);
    }
}

void main(void)
{
    char s[] = "Hello, World!";
    imprime(s);
}