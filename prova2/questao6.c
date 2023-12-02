/*
6 - Dado duas pilhas P1 e P2 que armazenam números inteiros, faça um programa que tenha as
seguintes funções:
1 - Uma função para testar se as duas pilhas P1 e P2 são iguais;
2 - Caso não forem iguais diga qual pilha é maior;
3 - Uma função que forneça o maior, o menor e a média aritmética dos elementos de uma pilha;
4 - Uma função para transferir elementos de P1 para P2 (cópia);
5 - Uma função para retornar o número de elementos de uma pilha que possuem valor ímpar;
6 - Uma função para retornar o número de elementos da uma pilha que possuem valor par.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int topo;
    int itens[MAX];
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

bool isVazia(Pilha *p) {
    return p->topo == -1;
}

bool isCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (isCheia(p)) {
        printf("Pilha cheia!\n");
        exit(1);
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

int desempilhar(Pilha *p) {
    if (isVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    int valor = p->itens[p->topo];
    p->topo--;
    return valor;
}

int topo(Pilha *p) {
    if (isVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    return p->itens[p->topo];
}

void imprimir(Pilha *p) {
    if (isVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int maior(Pilha *p) {
    if (isVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    int maior = p->itens[0];
    for (int i = 1; i <= p->topo; i++) {
        if (p->itens[i] > maior) {
            maior = p->itens[i];
        }
    }
    return maior;
}

int menor(Pilha *p) {
    if (isVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    int menor = p->itens[0];
    for (int i = 1; i <= p->topo; i++) {
        if (p->itens[i] < menor) {
            menor = p->itens[i];
        }
    }
    return menor;
}

float media(Pilha *p) {
    if (isVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    float soma = 0;
    for (int i = 0; i <= p->topo; i++) {
        soma += p->itens[i];
    }
    return soma / (p->topo + 1);
}

void transferir(Pilha *p1, Pilha *p2) {
    if (isVazia(p1)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    if (isCheia(p2)) {
        printf("Pilha cheia!\n");
        exit(1);
    }
    for (int i = 0; i <= p1->topo; i++) {
        empilhar(p2, p1->itens[i]);
    }
}

int impares(Pilha *p) {
    if (isVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    int impares = 0;
    for (int i = 0; i <= p->topo; i++) {
        if (p->itens[i] % 2 != 0) {
            impares++;
        }
    }
    return impares;
}

int pares(Pilha *p) {
    if (isVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    int pares = 0;
    for (int i = 0; i <= p->topo; i++) {
        if (p->itens[i] % 2 == 0) {
            pares++;
        }
    }
    return pares;
}

bool isIgual(Pilha *p1, Pilha *p2) {
    if (p1->topo > p2->topo) {
        printf("P1 é maior que P2!\n");
        return false;
    } else if (p1->topo < p2->topo) {
        printf("P2 é maior que P1!\n");
        return false;
    }

    for (int i = 0; i <= p1->topo; i++) {
        if (p1->itens[i] != p2->itens[i]) {
            return false;
        }
    }
    return true;
}


int main() {
    Pilha p1, p2, p3;
    inicializar(&p1);
    inicializar(&p2);
    inicializar(&p3);

    for (int i = 0; i < MAX; i++) {
        empilhar(&p1, i);
    }

    for (int i = 0; i < MAX; i++) {
        if (i % 2 == 0) {
            empilhar(&p2, i + 1);
        }
    }
    
    transferir(&p1, &p3);

    printf("Pilha 1: ");
    imprimir(&p1);

    printf("Pilha 2: ");
    imprimir(&p2);

    printf("Pilha 3: ");
    imprimir(&p3);

    printf("Maior: %d\n", maior(&p1));
    printf("Menor: %d\n", menor(&p1));
    printf("Média: %.2f\n", media(&p1));
    printf("Impares: %d\n", impares(&p1));
    printf("Pares: %d\n", pares(&p1));

    if (isIgual(&p1, &p2)) {
        printf("P1 e P2 são iguais!\n");
    } else {
        printf("P1 e P2 são diferentes!\n");
    }

    if (isIgual(&p1, &p3)) {
        printf("P1 e P3 são iguais!\n");
    } else {
        printf("P1 e P3 são diferentes!\n");
    }

    return 0;
}