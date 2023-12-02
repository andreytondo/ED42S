/*
6. (Exercício extraído do material do prof. Paulo Feofiloff
- https://www.ime.usp.br/~pf/algoritmos/). O que está acontecendo no código abaixo?
#include <stdio.h>
#include <string.h>
void imprime(char *s, int n) {
 char *c;
 for (c = s; c < s + n; c++)
 printf ("%c", *c);
}
void main(void){
 char s[] = "bom dia";
 imprime(s, strlen(s));
}

A função imprime recebe um ponteiro s e um inteiro n
e imprime os n primeiros caracteres a partir do endereço s. Nesse, caso
imprimirá 'bom dia'.
*/

#include <stdio.h>
#include <string.h>

void imprime(char *s, int n)
{
    char *c;
    for (c = s; c < s + n; c++)
        printf("%c", *c);
}

void main(void)
{
    char s[] = "bom dia";
    imprime(s, strlen(s));
}