/*
Questão 1 (5 pontos) - Crie um programa para armazenar o cadastro de filmes e séries de
um catálogo online. Para isso faça:
a) Utilize um TAD e o conceito de Encapsulamento estudado, com base em uma das
estruturas estáticas estudadas: Lista, Pilha, Fila ou Deque. (Peso 0,5)
b) Atualize a estrutura do TAD para armazenar dados referentes a código de identificação,
título, gênero e duração (em minutos), e ajuste as funções referentes a: inserir (sem
repetição de chaves) e imprimir. (Peso 2,0)
c) Crie um menu para chamar as funções criadas, com as seguintes opções: inserir novo
elemento no catálogo, excluir elemento, buscar elemento, imprimir todos os elementos
cadastrados, sair. (Peso 1,0)
d) Criar uma nova função, que permite fazer uma cópia de um catálogo para outro, filtrando
por gênero do elemento. (Peso 1,0)
e) Incluir uma opção no menu chamada recomendar para amigo, e então solicite ao usuário
um gênero de filme para usar como filtro, e o e-mail da pessoa que receberá o catálogo
como recomendação. Usar então a função criada na questão (d) para criar uma cópia do
catálogo atual, imprimindo os elementos a partir dessa cópia, e o e-mail da pessoa que
receberá o catálogo como recomendação. (Peso 0,5)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 20

typedef struct filme{
    int codigo;
    char titulo[50];
    char genero[50];
    int duracao;
} Filme;


typedef struct lista{
    Filme filmes[TAMANHO];
    int ultimo;
} Lista;

Lista *criaListaVazia(){
    Lista *L = malloc(sizeof(Lista));
    L->ultimo = -1;
    return L;
};

void imprimirLista(Lista *L){
    int tam = L->ultimo;
    int i;

    printf("\n====Lista de filmes====\n");
    for(i = 0; i <= tam; i++){
        printf("Codigo do filme: %d \n", L->filmes[i].codigo);
        printf("Titulo do filme: %s \n", L->filmes[i].titulo);
        printf("Genero do filme: %s \n", L->filmes[i].genero);
        printf("Duracao do filme: %d \n", L->filmes[i].duracao);
        printf("\n");
    }
};

int isListaCheia(Lista *L){
    return L-> ultimo == TAMANHO -1;
};

void adicionarFilme(Lista *L, int codigo, char titulo[], char genero[], int duracao){
    if(isListaCheia(L)){
        printf("\nLista cheia\n");
    }else{
        Filme novoF;
        novoF.codigo = codigo;
        strcpy(novoF.titulo, titulo);
        strcpy(novoF.genero, genero);
        novoF.duracao = duracao;
        L->ultimo++;
        L->filmes[L->ultimo] = novoF;
        printf("\nFilme adicionado com sucesso\n\n");
    }
};

int buscarFilmePorId(Lista *L, int codigo) {
    for (int i = 0; i <= L->ultimo; i++) {
        if (L->filmes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void excluirFilme(Lista *L, int codigo){
    int pos = buscarFilmePorId(L, codigo);
    int i;

    if(pos == -1){
        printf("\nFilme nao encontrado\n");
    }else{
        for(i = pos; i < L->ultimo; i++){
            L->filmes[i] = L->filmes[i+1];
        }
        L->ultimo--;
        printf("\nFilme excluido com sucesso\n");
    }
};

Lista copiarCatalogo(Lista *L1, char genero[]) {
    Lista *L2 = criaListaVazia();

    for (int i = 0; i <= L1->ultimo; i++) {
        if (strcmp(L1->filmes[i].genero, genero) == 0) {
            L2->filmes[L2->ultimo + 1] = L1->filmes[i];
            L2->ultimo++;
        }
    }

    return *L2;
}

int main(){
    Lista *L;
    L = criaListaVazia();
    int opcao;
    int codigo = 1;
    char titulo[50];
    char genero[50];
    int duracao;
    char email[50];

    do{
        printf("-=-=-=- MENU -=-=-=-\n");
        printf("1 - Adicionar filme\n");
        printf("2 - Imprimir lista de filmes\n");
        printf("3 - Buscar filme por codigo\n");
        printf("4 - Excluir filme\n");
        printf("5 - Recomendar para amigo\n");
        printf("0 - Sair\n");
        printf("Informe a ação que deseja realizar: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                fflush(stdin);
                printf("Informe o titulo do filme: ");
                scanf("%[^\n]", titulo);
                fflush(stdin);
                printf("Informe o genero do filme: ");
                scanf("%[^\n]", genero);
                fflush(stdin);
                printf("Informe a duracao do filme(em minutos): ");
                scanf("%d", &duracao);
                fflush(stdin);
                adicionarFilme(L, codigo, titulo, genero, duracao);
                codigo++;
                break;
            case 2:
                imprimirLista(L);
                break;
            case 3:
                printf("Digite o codigo do filme: ");
                scanf("%d", &codigo);
                int pos = buscarFilmePorId(L, codigo);
                if(pos == -1){
                    printf("\nFilme nao encontrado\n");
                }else{
                    printf("\n");
                    printf("Titulo do filme: %s \n", L->filmes[pos].titulo);
                    printf("Genero do filme: %s \n", L->filmes[pos].genero);
                    printf("Duracao do filme: %d \n", L->filmes[pos].duracao);
                    printf("\n");
                }
                break;
            case 4:
                printf("Digite o codigo do filme: ");
                scanf("%d", &codigo);
                excluirFilme(L, codigo);
                break;
            case 5:
                fflush(stdin);
                printf("Informe o email o qual recebera a recomendacao: ");
                scanf("%[^\n]", email);
                fflush(stdin);
                printf("Digite o genero da lista de filmes: ");
                scanf("%[^\n]", genero);
                fflush(stdin);
                Lista *L2 = criaListaVazia();
                *L2 = copiarCatalogo(L, genero);
                printf("\nLista de filmes recomendados: \n");
                imprimirLista(L2);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("\nOpcao invalida\n\n");
                break;
        }
    }while(opcao != 0);

    free(L);

    return 0;
}
