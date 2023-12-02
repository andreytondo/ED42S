/*
14. Implemente uma função que concatena uma string "b" no final de uma string "a". O
protótipo da função deve ser void concatena_strings(char *sa, char *sb). Utilize ponteiros.
*/

#include <stdio.h>

void concatena_strings(char *sa, char *sb)
{
    char *p, *q;
    for (p = sa; *p != '\0'; p++) {}
    for (q = sb; *q != '\0'; p++, q++) {
        *p = *q;
    }

    *p = '\0';
}

void main(void)
{
    char sa[20] = "Hello, ";
    char sb[] = "World!";
    
    concatena_strings(sa, sb);
    printf("%s\n", sa);
}
