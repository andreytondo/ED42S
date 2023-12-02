/*
10. Escreva um programa que imprime um vetor. Percorra os itens do vetor através de
aritmética de ponteiros.
*/

#include <stdio.h>

void imprime(int *v, int n)
{
    int *p;
    for (p = v; p < v + n; p++)
    {
        printf("%d ", *p);
    }
}

void main(void)
{
    int v[] = {1, 2, 3, 4, 5};
    imprime(v, 5);
}