/*
15. Implemente uma função que compara duas strings. O protótipo da função deve ser: int
compara_string(char *sa, char *sb), retornando um número inteiro para indicar se são
iguais ou não. Utilize ponteiros.
*/

#include <stdio.h>

int compara_string(char *sa, char *sb)
{
    char *p, *q;
    for (p = sa, q = sb; *p != '\0' || *q != '\0'; p++, q++) {
        if (*p != *q) {
            return 0;
        }
    }
    return 1;
}

void main(void)
{
    char sa[] = "Hello, World!";
    char sb[] = "Hello, World!";
    char sc[] = "Hello, World";
    
    printf("%d\n", compara_string(sa, sb));
    printf("%d\n", compara_string(sa, sc));
}