/*
10. Criar uma estrutura para armazenar dados de filmes: título, diretor, gênero, duração (em
minutos) e nota (1, 2, 3, 4 ou 5 estrelas).
• Leia e armazene informações de alguns filmes;
• Crie uma função para retornar o cadastro do filme mais longo.
• Crie uma função para mostrar os dados dos filmes com 5 estrelas.
• Crie uma função para mostrar os dados dos filmes com apenas 1 estrela.
• Crie uma função para mostrar todos os filmes de um determinado diretor.
• Crie uma função para mostrar todos os filmes de um determinado gênero
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 2

typedef struct filme
{
    char titulo[50], diretor[50], genero[50];
    int minutos, nota;
} Filme;

mostraFilme(Filme filme) {
    printf("\nFilme");
    printf("\n Titulo: %s", filme.titulo);
    printf("\n Diretor: %s", filme.diretor);
    printf("\n Genero: %s", filme.genero);
    printf("\n Duração: %d", filme.minutos);
    printf("\n Nota: %d", filme.nota);
}

int buscaFilmeMaisLongo(Filme filmes[TAMANHO])
{
    int index = -1, minutos = -1;
    for (int i = 0; i < TAMANHO; i++)
    {
        if (filmes[i].minutos > minutos)
        {
            minutos = filmes[i].minutos;
            index = i;
        }
    }

    return index;
}

mostraPorNota(Filme filmes[TAMANHO], int nota) {
    for (int i = 0; i < TAMANHO; i++) {
        if (filmes[i].nota == nota) {
            mostraFilme(filmes[i]);
        }
    }
}

mostraPorDiretor(Filme filmes[TAMANHO], char diretor[]) {
    for (int i = 0; i < TAMANHO; i++) {
        if (strcmp(filmes[i].diretor, diretor) == 0) {
            mostraFilme(filmes[i]);
        }
    }
}

mostraPorGenero(Filme filmes[TAMANHO], char genero[]) {
    for (int i = 0; i < TAMANHO; i++) {
        if (strcmp(filmes[i].genero, genero) == 0) {
            mostraFilme(filmes[i]);
        }
    }
}

main()
{
    Filme filmes[TAMANHO];

    for (int i = 0; i < TAMANHO; i++)
    {
        fflush(stdin);

        printf("\nInforme o titulo do filme: ");
        gets(filmes[i].titulo);

        printf("Informe o diretor: ");
        gets(filmes[i].diretor);

        printf("Informe o genero do filme: ");
        gets(filmes[i].genero);

        printf("Informe a duracao (em minutos): ");
        scanf("%d", &filmes[i].minutos);

        printf("Informe a nota (em estrelas): ");
        scanf("%d", &filmes[i].nota);
    }

    printf("\n\nFilme mais longo:");
    int index = buscaFilmeMaisLongo(filmes);
    mostraFilme(filmes[index]);

    printf("\n\nFilmes com 5 estrelas:");
    mostraPorNota(filmes, 5);

    printf("\n\nFilmes com 1 estrela:");
    mostraPorNota(filmes, 1);
    
    printf("\n\n");
    char diretor[50];
    fflush(stdin);
    printf("Busque por diretor:");
    gets(diretor);
    printf("\n\nFilmes do diretor informado:");
    mostraPorDiretor(filmes, diretor);

    printf("\n\n");
    char genero[50];
    fflush(stdin);
    printf("Busque por genero: ");
    gets(genero);
    printf("\n\nFilmes do genero informado");
    mostraPorGenero(filmes, genero);
}
