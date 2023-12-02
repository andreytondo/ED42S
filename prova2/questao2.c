/*
2 - Se uma fila representada por arranjos (vetores) não é considerada circular, sugere-se que
cada operação Desenfileira deve deslocar para “frente” todo elemento restante de uma fila. Um
método alternativo é adiar o deslocamento até que “ultimo” seja igual ao último índice do vetor.
Quando essa situação ocorre e faz-se uma tentativa de inserir um elemento na fila, a fila inteira
é deslocada para “frente”, de modo que o primeiro elemento da fila fique na primeira posição
do vetor, ou posição 0. Quais são as vantagens desse método sobre um deslocamento em cada
operação Desenfileira? Quais as desvantagens? Reescreva as funções Desenfileira, Enfileira e
Vazia usando esse novo método.
*/

/*
As vantagens desse método é que ele não precisa deslocar os elementos da fila a cada desenfileiramento, o que economiza tempo.

A desvantagem é que ele precisa deslocar os elementos da fila quando o último elemento da fila é igual ao último índice do vetor, 
o que pode ser custoso.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int id;
    char nome[50];
    int idade;
    char sexo;
    char cpf[15];
    char telefone[15];
    char email[50];
} Pessoa;

typedef struct {
    Pessoa pessoas[MAX];
    int inicio;
    int fim;
} Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

bool isVazia(Fila *f) {
    return f->fim == -1;
}

bool isCheia(Fila *f) {
    return f->fim == MAX - 1;
}

void enfileirar(Fila *f, Pessoa p) {
    if (isCheia(f)) {
        printf("Fila cheia!\n");
        exit(1);
    }
    f->fim++;
    f->pessoas[f->fim] = p;
}

Pessoa desenfileirar(Fila *f) {
    if (isVazia(f)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    Pessoa p = f->pessoas[f->inicio];
    for (int i = 0; i < f->fim; i++) {
        f->pessoas[i] = f->pessoas[i + 1];
    }
    f->fim--;
    return p;
}