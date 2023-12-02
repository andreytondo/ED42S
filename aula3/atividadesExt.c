#include <stdio.h>
#include "atividadesExt.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

Data *dataNova(int d, int m, int a);
Data *dataHoje(void);
int atividadeConcluida(Data *dt);
void imprimirData(Data *dt);
void liberarData(Data *dt);

Data *dataHoje(void)
{
    Data *dt = malloc(sizeof(Data));
    time_t tempo;
    struct tm *hj;
    tempo = time(NULL);     // obtem o tempo corrente
    hj = localtime(&tempo); // obtem a data do sistema operacional
    dt->dia = hj->tm_mday;
    dt->mes = hj->tm_mon + 1;
    dt->ano = hj->tm_year + 1900;
    return (dt);
}

Data *dataNova(int d, int m, int a)
{
    Data *dt = malloc(sizeof(Data));
    dt->dia = d;
    dt->mes = m;
    dt->ano = a;
    return (dt);
}

int atividadeConcluida(Data *dt)
{
    if (dt != NULL) {
        Data *hoje = dataHoje();
        int concluida = 0;
        if (dt->ano < hoje->ano)
            concluida = 1;
        else if (dt->ano == hoje->ano && dt->mes < hoje->mes)
            concluida = 1;
        else if (dt->ano == hoje->ano && dt->mes == hoje->mes && dt->dia <= hoje->dia)
            concluida = 1;
        liberarData(hoje);
        return (concluida);
    }
}

void imprimirData(Data *dt)
{
    if (dt != NULL)
    {
        printf("%02d/%02d/%04d", dt->dia, dt->mes, dt->ano);
    }
}

void liberarData(Data *dt)
{
    free(dt);
}

AtividadeExt *inserirAtividade(AtividadeExt *atividades, int ra, char descricao[100], int cargaHoraria, Data *dataInicial, Data *dataFinal)
{
    AtividadeExt *novaAtividade = malloc(sizeof(AtividadeExt));
    novaAtividade->ra = ra;
    strcpy(novaAtividade->descricao, descricao);
    novaAtividade->cargaHoraria = cargaHoraria;
    novaAtividade->dataInicial = dataInicial;
    novaAtividade->dataFinal = dataFinal;
    novaAtividade->prox = NULL;
    if (atividades == NULL)
        atividades = novaAtividade;
    else
    {
        AtividadeExt *aux = atividades;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novaAtividade;
    }
    return (atividades);
}

AtividadeExt *cadastrarAtividade(AtividadeExt *atividades)
{
    int ra, cargaHoraria;
    char descricao[100];
    Data *dataInicial, *dataFinal;

    printf("Digite o RA: ");
    scanf("%d", &ra);

    fflush(stdin);
    printf("Digite a descricao: ");
    gets(descricao);

    printf("Digite a carga horaria: ");
    scanf("%d", &cargaHoraria);

    int dia, mes, ano;
    printf("Digite a data inicial (dia): ");
    scanf("%d", &dia);

    printf("Digite a data inicial (mes): ");
    scanf("%d", &mes);

    printf("Digite a data inicial (ano): ");
    scanf("%d", &ano);

    dataInicial = dataNova(dia, mes, ano);

    printf("Digite a data final (dia): ");
    scanf("%d", &dia);

    printf("Digite a data final (mes): ");
    scanf("%d", &mes);

    printf("Digite a data final (ano): ");
    scanf("%d", &ano);
    dataFinal = dataNova(dia, mes, ano);

    atividades = inserirAtividade(atividades, ra, descricao, cargaHoraria, dataInicial, dataFinal);
    return (atividades);
}

void imprimirAtividades(AtividadeExt *atividades)
{
    AtividadeExt *aux = atividades;
    while (aux != NULL)
    {
        printf("RA: %d\n", aux->ra);
        printf("Descricao: %s\n", aux->descricao);
        printf("Carga Horaria: %d\n", aux->cargaHoraria);
        printf("Data Inicial: ");
        imprimirData(aux->dataInicial);
        printf("\n");
        printf("Data Final: ");
        imprimirData(aux->dataFinal);
        printf("\n");
        aux = aux->prox;
    }
}

void liberarAtividades(AtividadeExt *atividades)
{
    AtividadeExt *aux = atividades;
    while (aux != NULL)
    {
        AtividadeExt *aux2 = aux->prox;
        liberarData(aux->dataInicial);
        liberarData(aux->dataFinal);
        free(aux);
        aux = aux2;
    }
}

void verificarAtividades(AtividadeExt *atividades)
{
    AtividadeExt *aux = atividades;
    while (aux != NULL)
    {
        printf("Descricao: %s\n", aux->descricao);
        if (atividadeConcluida(aux->dataFinal))
            printf("Atividade concluida\n");
        else
            printf("Atividade nao concluida\n");
        aux = aux->prox;
    }
}