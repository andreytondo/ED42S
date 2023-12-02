/*
4 - Faça um programa que apresente o menu de opções abaixo:
MENU
1 - Cadastrar tipo
2 - Cadastrar produto
3 - Consultar preço de um produto
4 - Excluir tipo
5 - Sair
Observações:
a) Mostrar mensagem de opção inválida no meu. A opção 5 é a única que sai do programa;
b) Para a implementação do programa acima é necessário utilizar duas estruturas de dados do
tipo fila;
c) Na primeira estrutura serão armazenados os tipos dos produtos com seus respectivos
percentuais de impostos. Lembrando que não é necessário validar a repetição de tipos, ou seja,
suponha que todos os tipos cadastrados são diferentes. Cada tipo é apenas uma letra.
d) Na segunda estrutura serão armazenados os produtos cujo número (Código) deve ser gerado
automaticamente. O preço, o nome e o tipo devem ser digitados. Lembrando que um produto
só pode ser cadastrado se for de um tipo também já cadastrado, fazer a verificação antes de
cadastrar o produto e se não tiver o tipo gerar uma mensagem.
e) Na primeira opção do menu serão cadastrados os tipos, um de cada vez: cada vez que o
usuário escolhe a opção 1 do menu, ele tem a possibilidade de cadastrar um novo tipo (Letra
que representa o tipo e o percentual de imposto). Nessa opção a mensagem de retorno deverá
ser: Tipo cadastrado.
f) Na segunda opção do menu serão cadastrados os produtos, um de cada vez: cada vez que o
usuário escolhe a opção 2 do menu, ele tem a possibilidade de cadastrar um novo produto
(número gerado automaticamente, nome, preço e tipo). Lembrando que um produto só pode
ser cadastrado se o tipo ao qual ele pertence já existe na fila de tipo. Nesta opção as mensagens
disponíveis são: Produto cadastrado e Tipo de produto inexistente.
g) Na terceira opção do menu o usuário digita o número do produto que deseja consultar o preço
e, se este existir na fila de produtos, o programa deve procurar por seu percentual de imposto,
de acordo com o tipo do produto na fila de tipos, calcular e mostrar seu preço, ou seja, preço
cadastrado menos o percentual de imposto. Nesta opção, as mensagens são: Preço = Valor
Calculado, Produto não encontrado e Fila vazia.
h) Na quarta opção o programa deve excluir um tipo da fila de tipos, respeitando a forma de
organização de uma fila. Lembrando que um tipo só pode ser excluído se não existir nenhum
produto cadastrado para ele, então primeiro devem ser excluídos todos os produtos que fazem
parte do tipo que será excluído.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    char tipo;
    float imposto;
} Tipo;

typedef struct {
    Tipo tipos[MAX];
    int inicio;
    int fim;
} FilaTipos;

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    char tipo;
} Produto;

typedef struct {
    Produto produtos[MAX];
    int inicio;
    int fim;
} FilaProdutos;

void inicializarTipos(FilaTipos *ft) {
    ft->inicio = 0;
    ft->fim = -1;
}

bool isTiposVazia(FilaTipos *ft) {
    return ft->fim == -1;
}

bool isTipoCheia(FilaTipos *ft) {
    return ft->fim == MAX - 1;
}

void enfileirarTipos(FilaTipos *ft, Tipo t) {
    if (isTipoCheia(ft)) {
        printf("Fila de tipos cheia!\n");
        exit(1);
    }
    ft->fim++;
    ft->tipos[ft->fim] = t;
}

Tipo desenfileirarTipos(FilaTipos *ft) {
    if (isTiposVazia(ft)) {
        printf("Fila de tipos vazia!\n");
        exit(1);
    }
    Tipo t = ft->tipos[ft->inicio];
    for (int i = 0; i < ft->fim; i++) {
        ft->tipos[i] = ft->tipos[i + 1];
    }
    ft->fim--;
    return t;
}

void inicializarProdutos(FilaProdutos *fp) {
    fp->inicio = 0;
    fp->fim = -1;
}

bool isProdutosVazia(FilaProdutos *fp) {
    return fp->fim == -1;
}

bool isProdutosCheia(FilaProdutos *fp) {
    return fp->fim == MAX - 1;
}

void enfileirarProdutos(FilaProdutos *fp, Produto p) {
    if (isProdutosCheia(fp)) {
        printf("Fila de produtos cheia!\n");
        exit(1);
    }
    fp->fim++;
    fp->produtos[fp->fim] = p;
}

Produto desenfileirarProdutos(FilaProdutos *fp) {
    if (isProdutosVazia(fp)) {
        printf("Fila de produtos vazia!\n");
        exit(1);
    }
    Produto p = fp->produtos[fp->inicio];
    for (int i = 0; i < fp->fim; i++) {
        fp->produtos[i] = fp->produtos[i + 1];
    }
    fp->fim--;
    return p;
}

int buscarTipo(FilaTipos *ft, char tipo) {
    for (int i = 0; i <= ft->fim; i++) {
        if (ft->tipos[i].tipo == tipo) {
            return i;
        }
    }
    return -1;
}

int buscarProduto(FilaProdutos *fp, int codigo) {
    if (isProdutosVazia(fp)) {
        printf("Fila de produtos vazia!\n");
        return -1;
    }

    for (int i = 0; i <= fp->fim; i++) {
        if (fp->produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void cadastrarTipo(FilaTipos *ft) {
    Tipo t;
    printf("Digite o tipo: ");
    scanf(" %c", &t.tipo);
    printf("Digite o percentual de imposto: ");
    scanf("%f", &t.imposto);
    enfileirarTipos(ft, t);
    printf("Tipo cadastrado!\n");
}

int gerarCodigoProduto(FilaProdutos *fp) {
    if (isProdutosVazia(fp)) {
        return 1;
    }
    return fp->produtos[fp->fim].codigo + 1;
}

void cadastrarProduto(FilaTipos *ft, FilaProdutos *fp) {
    Produto p;
    p.codigo = gerarCodigoProduto(fp);
    printf("Código: %d\n", p.codigo);
    printf("Digite o nome: ");
    scanf(" %[^\n]", p.nome);
    printf("Digite o preço: ");
    scanf("%f", &p.preco);
    printf("Digite o tipo: ");
    scanf(" %c", &p.tipo);
    int posicao = buscarTipo(ft, p.tipo);
    if (posicao == -1) {
        printf("Tipo de produto inexistente!\n");
    } else {
        enfileirarProdutos(fp, p);
        printf("Produto cadastrado!\n");
    }
}

void consultarPreco(FilaTipos *ft, FilaProdutos *fp) {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    int posicao = buscarProduto(fp, codigo);
    if (posicao == -1) {
        printf("Produto não encontrado!\n");
    } else {
        int posicaoTipo = buscarTipo(ft, fp->produtos[posicao].tipo);
        float preco = fp->produtos[posicao].preco - (fp->produtos[posicao].preco * ft->tipos[posicaoTipo].imposto / 100);
        printf("Preço = %.2f\n", preco);
    }
}

void excluirProdutoPorTipo(FilaTipos *ft, FilaProdutos *fp, char tipo) {
    for (int i = 0; i <= fp->fim; i++) {
        if (fp->produtos[i].tipo == tipo) {
            Produto p = desenfileirarProdutos(fp);
            printf("Produto excluído!\n");
        }
    }
}

void excluirTipo(FilaTipos *ft, FilaProdutos *fp) {
    char tipo;
    printf("Digite o tipo: ");
    scanf(" %c", &tipo);

    int posicao = buscarTipo(ft, tipo);
    if (posicao == -1) {
        printf("Tipo não encontrado!\n");
    } else {
        excluirProdutoPorTipo(ft, fp, tipo);
        Tipo t = desenfileirarTipos(ft);
        printf("Tipo excluído!\n");
    }
}

void menu(FilaTipos *ft, FilaProdutos *fp) {
    int opcao;
    do {
        printf("MENU\n");
        printf("1 - Cadastrar tipo\n");
        printf("2 - Cadastrar produto\n");
        printf("3 - Consultar preço de um produto\n");
        printf("4 - Excluir tipo\n");
        printf("5 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarTipo(ft);
                break;
            case 2:
                cadastrarProduto(ft, fp);
                break;
            case 3:
                consultarPreco(ft, fp);
                break;
            case 4:
                excluirTipo(ft, fp);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);
}

int main() {
    FilaTipos ft;
    inicializarTipos(&ft);
    FilaProdutos fp;
    inicializarProdutos(&fp);
    menu(&ft, &fp);
    return 0;
}