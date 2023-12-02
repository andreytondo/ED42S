/*
12. Escrever uma função para contar a quantidade de caracteres de uma string, usando
ponteiros para percorre-la.
*/

#include <stdio.h>

int conta(char *s)
{
    char *p;
    int n = 0;
    
    for (p = s; *p != '\0'; p++)
    {
        n++;
    }
    
    return n;
}

void main(void)
{
    char s[] = "Hello, World!";
    printf("%d\n", conta(s));
}