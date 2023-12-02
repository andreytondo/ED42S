typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct atividadeExt {
    int ra;
    char descricao[100];
    int cargaHoraria;
    Data *dataInicial;
    Data *dataFinal;
    struct atividadeExt *prox;
} AtividadeExt;