/*
8. Corrija o problema do código abaixo:
#include <stdio.h>
void troca(int *a, int *b) {
 int *t;
 *t = *a;
 *a = *b;
 *b = *t;
}
void main(void){
 int a = 10;
 int b = 20;
 printf("a: %d, b: %d\n", a, b);
 troca(&a, &b);
 printf("a: %d, b: %d\n", a, b);
}

O ponteiro t não foi inicializado, logo, não aponta para lugar nenhum.
O correto seria:

#include <stdio.h>
void troca(int *a, int *b) {
 int t;
 t = *a;
 *a = *b;
 *b = t;
}
void main(void){
 int a = 10;
 int b = 20;
 printf("a: %d, b: %d\n", a, b);
 troca(&a, &b);
 printf("a: %d, b: %d\n", a, b);
}
*/

#include <stdio.h>

void troca(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void main(void)
{
    int a = 10;
    int b = 20;
    
    printf("a: %d, b: %d\n", a, b);
    troca(&a, &b);
    printf("a: %d, b: %d\n", a, b);
}