/*
5. Faça um programa que armazene em uma estrutura os dados de um atleta profissional,
compostos de: Nome, CPF, Data de Nascimento, Modalidade esportiva e Salário. Os
dados devem ser digitados pelo usuário, armazenados na estrutura e exibidos na tela.
Obs.: crie uma estrutura para armazenar a data de nascimento e use esta estrutura dentro
da estrutura do cadastro.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 2

typedef struct dataNascimento
{
    int dia, mes, ano;
} DataNascimento;

typedef struct atleta
{
    char nome[50], cpf[20], modalidade[100];
    float salario; 
    DataNascimento dataNascimento;
} Atleta;


void mostraDataNascimento(DataNascimento dataNascimento) {
    printf("\n Nascido no dia: %d/%d/%d", dataNascimento.dia, dataNascimento.mes, dataNascimento.ano);
}

void mostraAtleta(Atleta atleta) {
    printf("\n Nome: %s", atleta.nome);
    printf("\n CPF: %s", atleta.cpf);
    printf("\n Modalidade: %s", atleta.modalidade);
    printf("\n Salario: R$: %.2f", atleta.salario);
    mostraDataNascimento(atleta.dataNascimento);
}

main()
{
    Atleta atletas[TAMANHO];

    for (int i = 0; i < TAMANHO; i++)
    {
        fflush(stdin);

        printf("Digite o nome do atleta %d: ", i + 1);
        gets(atletas[i].nome);

        printf("Digite o cpf do atleta %d: ", i + 1);
        gets(atletas[i].cpf);

        printf("Digite a modalidade do atleta %d: ", i + 1);
        gets(atletas[i].modalidade);


        printf("Digite o salario do atleta %d: ", i + 1);
        scanf("%f", &atletas[i].salario);

        int dia, mes, ano;

        printf("Digite o dia de nascimento do atleta %d: ", i + 1);
        scanf("%d", &atletas[i].dataNascimento.dia);

        printf("Digite o mes de nascimento do atleta %d (1 a 12): ", i + 1);
        scanf("%d", &atletas[i].dataNascimento.mes);

        printf("Digite o ano de nascimento do atleta %d: ", i + 1);
        scanf("%d", &atletas[i].dataNascimento.ano);
    }

    for (int i = 0; i < TAMANHO; i++) {
        printf("\nMostrando atleta %d", i + 1);
        mostraAtleta(atletas[i]);
    }
}
