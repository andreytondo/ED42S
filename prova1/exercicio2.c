typedef struct data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct livroCaixa
{
    char situacao;       // Situação do registro (X- ocupado e *- apagado)
    Data dataLancamento; // Data do lançamento (item agregado com os campos: dia, mês e ano)
    char tipo;           // Tipo do lançamento (D- Despesa e R- Receita)
    char historico[35];  // Histórico do Lançamento (como uma cadeia de 35 caracteres)
    float valor;         // Valor do lançamento (R$)
    struct livroCaixa *prox;
} LivroCaixa;