/*
9. Escreva um programa para fazer a criação dos novos tipos de dados conforme solicitado
abaixo:
• Horário: composto de hora, minutos e segundos. ́
• Data: composto de dia, mês e ano.
• Compromisso: composto de uma data, horário e texto que descreve o compromisso.
Faça o cadastro de alguns compromissos e imprima todos os compromissos de um mês
solicitado pelo usuário.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 2

typedef struct horario {
    int segundos, minutos, hora;
} Horario;

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct compromisso
{
    Horario hora;
    Data data;
    char descricao[300]
} Compromisso;


mostraHora(Horario hora) {
    printf("\n Horario: %d:%d:%d", hora.hora, hora.minutos, hora.segundos);
}

mostraData(Data data) {
    printf("\n Data: %d/%d/%d", data.dia, data.mes, data.ano);
}

mostraCompromisso(Compromisso compromisso) {
    printf("\nCompromisso");
    mostraHora(compromisso.hora);
    mostraData(compromisso.data);
    printf("\n Descricao: %s", compromisso.descricao);
}

main() {
    Compromisso compromissos[TAMANHO];

    for (int i = 0; i < TAMANHO; i++) {
        fflush(stdin);

        printf("Informe o horário do compromisso (segundos, minutos e horas): ");
        scanf("%d", &compromissos[i].hora.segundos);
        scanf("%d", &compromissos[i].hora.minutos);
        scanf("%d", &compromissos[i].hora.hora);

        printf("Informe a data do compromisso (dia, mês e ano): ");
        scanf("%d", &compromissos[i].data.dia);
        scanf("%d", &compromissos[i].data.mes);
        scanf("%d", &compromissos[i].data.ano);

        fflush(stdin);

        printf("Digite a descricao do compromisso: ");
        gets(compromissos[i].descricao);
    }

    int mes = -1;
    printf("Informe um mês para filtrar os compromissos: ");
    scanf("%d", &mes);

    for (int i = 0; i < TAMANHO; i++) {
        if (compromissos[i].data.mes == mes) {
            mostraCompromisso(compromissos[i]);
        }
    }
}
