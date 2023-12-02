/*
4. Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
da terceira prova.
• Permita ao usuário entrar com os dados de 5 alunos;
• Encontre o aluno com maior nota da primeira prova;
• Encontre o aluno com maior média geral;
• Encontre o aluno com menor média geral; ́
• Percorra o vetor de alunos e para cada aluno diga se ele foi aprovado ou reprovado,
considerando o valor 6 para aprovação.
*/

#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 2

typedef struct aluno
{
    int matricula;
    float notaUm, notaDois, notaTres, mediaFinal;
} Aluno;

float buscaAlunoMaiorMedia(Aluno alunos[TAMANHO])
{
    float valor = 0;
    for (int i = 0; i < TAMANHO; i++)
    {
        if (alunos[i].mediaFinal >= valor)
        {
            valor = alunos[i].mediaFinal;
        }
    }
    return valor;
}

float buscaAlunoMenorMedia(Aluno alunos[TAMANHO])
{
    float valor = 10;
    for (int i = 0; i < TAMANHO; i++)
    {
        if (alunos[i].mediaFinal <= valor)
        {
            valor = alunos[i].mediaFinal;
        }
    }
    return valor;
}

float buscaAlunoMaiorNotaUm(Aluno alunos[TAMANHO])
{
    float valor = 0;
    for (int i = 0; i < TAMANHO; i++)
    {
        if (alunos[i].notaUm >= valor)
        {
            valor = alunos[i].notaUm;
        }
    }
    return valor;
}

int main(void)
{
    Aluno alunos[TAMANHO];

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("\nInforme a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        printf("Informe a nota da primeira prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notaUm);

        printf("Informe a nota da segunda prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notaDois);

        printf("Informe a nota da terceira prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].notaTres);

        alunos[i].mediaFinal = (alunos[i].notaUm + alunos[i].notaDois + alunos[i].notaTres) / 3;
        printf("O aluno %d esta %s com a media: %.2f", i + 1, alunos[i].mediaFinal >= 6 ? "aprovado" : "reprovado", alunos[i].mediaFinal);
    }

    printf("\nA maior nota da primeira prova: %.2f", buscaAlunoMaiorNotaUm(alunos));
    printf("\nA maior media final: %.2f", buscaAlunoMaiorMedia(alunos));
    printf("\nA menor media final: %.2f", buscaAlunoMenorMedia(alunos));

    return 0;
}