/*
5. Qual será a saída do programa?
#include <stdio.h>
int main(void){
 int v[] = {10, 20, 30};
 int *p;
 p = v;
 p++;
 printf("%d\n", *p);
 return 0;
}
Se em vez de:
p++;
fosse:
(*p)++;
Qual seria a saída?

A saída seria 11
*/

#include <stdio.h>
int main(void)
{
    int v[] = {10, 20, 30};
    int *p;
    p = v;
    (*p)++;
    printf("%d\n", *p);
    return 0;
}