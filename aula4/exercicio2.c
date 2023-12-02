/*
Questão 2 (5 pontos) – A struct abaixo representa um agendamento de hospedagem em um
hotel:
struct reservas {
 int {identificação da reserva};
 char {texto com a identificação do hóspede e do quarto};
 float {custo da diária};
};
Baseado nessa estrutura, crie:
a) Um TAD para manipular os dados usando uma das estruturas estáticas estudadas (Lista,
Pilha, Fila ou Deque), diferente da utilizada na Questão 1. (Peso 1,0)
b) O TAD deve conter funções básicas para criar, inserir uma reserva, remover uma reserva,
e imprimir todas as reservas. (Peso 2,0)
c) Crie uma função que recebe uma coleção de reservas e retorna outra coleção contendo
os valores das reservas acrescidas de 10%, referente à taxa de limpeza. (Peso 1,0)
d) Demonstre o uso das funções criadas em um programa. (Peso 1,0)
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 20
#define DESCRICAO 50

typedef struct reservas {
 int chave;
 char descricao[DESCRICAO];
 float valor;
} Reserva;

typedef struct fila{
    Reserva reserva[TAMANHO];
    int primeiro;
    int ultimo;
    int tamanho;
} Fila;
 
Fila *criarisFilaVazia(){
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;

    return f;
};

void imprimirFila(Fila *f){
    int t, i;
    i = f->primeiro;
    for(t = 0; t< f->tamanho; t++){
        printf("Numero: %d\n", f->reserva[i].chave);
        printf("Descricao: %s\n", f->reserva[i].descricao);
        printf("Valor: %.2f\n\n", f->reserva[i].valor);
        i = (i+1) % TAMANHO;
    }
};

int isFilaCheia(Fila *f){
    return f->tamanho == TAMANHO;
};

int enfileirar(Fila *f, int chave, char descricao[], float valor){
    if(isFilaCheia(f)){
        printf("Erro: Sem quartos disponiveis\n");
    }else{
        Reserva reserva;
        reserva.chave = chave;
        strcpy(reserva.descricao, descricao);
        reserva.valor = valor;
        f->reserva[f->ultimo] = reserva;
        f->ultimo = (f->ultimo + 1) % TAMANHO;
        f->tamanho++;
    }
};

void desenfileirar(Fila *f){
    if(isFilaVazia(f)){
        printf("Sem reservas\n");
    }else{
        f->primeiro = (f->primeiro + 1) % TAMANHO;
        f->tamanho--;
        printf("Reserva mais antiga encerrada\n");
    }
};

int isFilaVazia(Fila *f){
    return f->tamanho == 0;
};

void liberarFila(Fila *f){
    free(f);
};

Fila *reservasComTaxaDeLimpeza(Fila *f) {
    Fila *reservasComTaxa;
     reservasComTaxa = criarisFilaVazia();

    int t, i;
    i = f->primeiro;
    for (t = 0; t < f->tamanho; t++) {
        Reserva reserva = f->reserva[i];
        reserva.valor *= 1.1;  // Aumenta o valor em 10% para taxa de limpeza
        enfileirar(reservasComTaxa, reserva.chave, reserva.descricao, reserva.valor);
        i = (i + 1) % TAMANHO;
    }

    return reservasComTaxa;
}

int main(){
    int opcao, chave;
    char descricao[DESCRICAO];
    float valor;
    Fila *f;
    f = criarisFilaVazia();

    do{
        printf("-=-=-=- MENU -=-=-=-\n");
        printf("1 - Reservar quarto\n");
        printf("2 - Encerrar reserva\n");
        printf("3 - Imprimir reservas\n");
        printf("4 - Reservas com taxa de limpeza\n");
        printf("0 - Sair\n");
        printf("Informe uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Informe o numero do quarto: ");
                scanf("%d", &chave);
                fflush(stdin);
                printf("Informe a descricao: ");
                scanf("%[^\n]", descricao);
                printf("Informe o valor: ");
                scanf("%f", &valor);
                enfileirar(f, chave, descricao, valor);
                break;
            case 2:
                desenfileirar(f);
                break;
            case 3:
                imprimirFila(f);
                break;
            case 4:
                printf("Reservas com taxa de limpeza:\n");
                imprimirFila(reservasComTaxaDeLimpeza(f));

                break;
            case 0:
                liberarFila(f);
                liberarFila(reservasComTaxaDeLimpeza(f));
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while(opcao != 0);
}
