/*
9. Escreva um programa para somar dois valores usando ponteiros.
*/

#include <stdio.h>

void soma(int *a, int *b, int *c)
{
    *c = *a + *b;
}

void main(void)
{
    int a = 10, b = 20, c;
    
    soma(&a, &b, &c);
    printf("a: %d, b: %d, c: %d\n", a, b, c);
}