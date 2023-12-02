/*
6. Faça um programa que leia os dados de 8 alunos (nome, matrícula e média final),
armazenando em um vetor. Uma vez lidos os dados, divida estes dados em 2 novos
vetores, o vetor dos aprovados e o vetor dos reprovados, considerando a média mínima
para a aprovação como sendo 5.0. Exibir na tela os dados do vetor de aprovados, seguido
dos dados do vetor de reprovados.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 8

typedef struct aluno
{
    char nome[50], matricula[50];
    float mediaFinal;
} Aluno;

void mostraAlunos(int tamanho, Aluno alunos[tamanho]) {
    for (int i = 0; i < tamanho; i ++) {
        printf("\nMostrando aluno %d:", i + 1);
        printf("\n Nome: %s", alunos[i].nome);
        printf("\n Matricula: %s", alunos[i].matricula);
        printf("\n Media final: %f", alunos[i].mediaFinal);
    }
}

main() {
    Aluno alunos[TAMANHO], aprovados[TAMANHO], reprovados[TAMANHO];

    for (int i = 0; i < TAMANHO; i++) {
        fflush(stdin);
        
        printf("Digite o nome do aluno %d: ", i + 1);
        gets(alunos[i].nome);

        printf("Digite a matricula do aluno %d: ", i + 1);
        gets(alunos[i].matricula);

        printf("Digite a media final do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].mediaFinal);
    }
    
    int contadorAprovados = 0;
    int contadorReprovados = 0;

    for (int i = 0; i < TAMANHO; i++) {
        if (alunos[i].mediaFinal >= 5) {
            aprovados[contadorAprovados] = alunos[i];
            contadorAprovados++;
        } else {
            reprovados[contadorReprovados] = alunos[i];
            contadorReprovados++;
        }
    }

    printf("ALUNOS APROVADOS: %d", contadorAprovados);
    mostraAlunos(contadorAprovados, aprovados);

    printf("\n\n");

    printf("ALUNOS REPROVADOS: %d", contadorReprovados);
    mostraAlunos(contadorReprovados, reprovados);
}
