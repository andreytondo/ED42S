/*
8. Faça um programa que leia um vetor com dados de 5 livros: título, autor e ano. Permita ao
usuário:
• Cadastrar um livro;
• Buscar livros pelo título (mostrar todos os livros com o título igual ao buscado);
• Buscar livros pelo ano (mostrar todos os livros com o ano igual ao buscado);
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 3
#define TAMANHO_TITULO 50

typedef struct livro
{
    char titulo[TAMANHO_TITULO], autor[50];
    int ano;
} Livro;

void mostraLivro(Livro livro)
{
    printf("\nTitulo: %s", livro.titulo);
    printf("\nAutor: %s", livro.autor);
    printf("\nAno: %d", livro.ano);
}

int main()
{
    struct livro livros[TAMANHO];

    for (int i = 0; i < TAMANHO; i++)
    {
        fflush(stdin);

        printf("Informe o titulo do livro %d: ", i + 1);
        gets(livros[i].titulo);

        printf("Informe o autor do livro %d: ", i + 1);
        gets(livros[i].autor);

        printf("Informe o ano do livro %d: ", i + 1);
        scanf("%d", &livros[i].ano);
    }

    char busca[TAMANHO_TITULO];

    fflush(stdin);
    printf("\nInforme o título do livro que deseja pesquisar: ");
    gets(busca);


    printf("\n LIVROS ENCONTRADOS:\n");
    for (int i = 0; i < TAMANHO; i++)
    {
        if (strcmp(livros[i].titulo, busca) == 0)
        {
            mostraLivro(livros[i]);
        }
    }

    int ano = -1;
    printf("\nInforme o ano do livro que deseja pesquisar: ");
    scanf("%d", &ano);

    printf("\n LIVROS ENCONTRADOS:\n");
    for (int i = 0; i < TAMANHO; i++)
    {
        if (livros[i].ano == ano)
        {
            mostraLivro(livros[i]);
        }
    }

    return 0;
}