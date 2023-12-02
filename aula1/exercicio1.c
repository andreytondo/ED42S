/*
1. Implemente um programa para registrar pedidos de um restaurante. O programa deve ler
o nome do cliente, descrição do pedido, e valor total e armazenar em uma struct. Depois,
imprima os dados armazenados.
*/

#include <stdio.h>

typedef struct pedido {
    char cliente[50], descricao[50];
    float valor;
} Pedido;

main() {

    Pedido pedido;

    printf("Insira o nome do cliente: ");
    gets(pedido.cliente);

    printf("Insira a descrição do pedido: ");
    gets(pedido.descricao);

    printf("Insira o valor total: ");
    scanf("%f", &pedido.valor);

    printf("\nnNome do cliente: %s", pedido.cliente);
    printf("\nDescrição do pedido: %s", pedido.descricao);
    printf("\nValor total: %.2f", pedido.valor);

}