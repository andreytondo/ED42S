/*
3. Construa uma estrutura DosesVacina para amazenar a previsão de aplicação de
doses de vacina a pacientes de acordo com sua idade. Registre o nome do
paciente, cidade e idade. Leia do usuário a informação de 5 pacientes, armazene em
vetor dessa estrutura e imprima os dados na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 2

typedef struct dosesVacina
{
    char previsaoAplicacao[10];
    int idadeAplicacao;
} DosesVacina;

typedef struct paciente
{
    char nome[50], cidade[50];
    int idade;
} Paciente;

int randomInteger(int min, int max)
{
   return min + rand() % (max+1 - min);
}

// Function to generate a random date string in ISO format (YYYY-MM-DD)
void randomDate(char *date_string) {
    int year = randomInteger(1970, 2023);  // Intervalo de anos
    int month = randomInteger(1, 12);
    int day = randomInteger(1, 28);  // Assumindo todos os meses com 28 dias para simplificar

    snprintf(date_string, 11, "%04d-%02d-%02d", year, month, day);
}

void printaPaciente(Paciente paciente) {
    printf("\nNome: %s", paciente.nome);
    printf("\nCidade: %s", paciente.cidade);
    printf("\nIdade: %d\n", paciente.idade);
}

main()
{
    char data[11];
    Paciente pacientes[TAMANHO];
    DosesVacina doses[TAMANHO];

    srand(time(NULL));

    for (int i = 0; i < TAMANHO; i++)
    {

        randomDate(data);
        strcpy(doses[i].previsaoAplicacao, data);
        doses[i].idadeAplicacao = randomInteger(0, 110);

        printf("Informe o nome do paciente %d: ", i + 1);
        gets(pacientes[i].nome);

        printf("Informe a cidade do paciente %d: ", i + 1);
        gets(pacientes[i].cidade);

        printf("Informe a idade do paciente %d: \n", i + 1);
        scanf("%d", &pacientes[i].idade);
        fflush(stdin);

        printaPaciente(pacientes[i]);
    }
    
}