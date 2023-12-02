// Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario
{
    int codigo;
    char nome[50];
    char sexo;
    float salario;
    int dependentes;
    char valido;
    struct funcionario *prox;
} Funcionario;

// Protótipos das funções
Funcionario *cadastrarFuncionario(Funcionario *funcionario);
void inserirFuncionario(Funcionario **inicio, Funcionario **fim, Funcionario *novo);
void removerFuncionario(Funcionario **inicio, Funcionario **fim, int codigo);
void imprimirFuncionarios(Funcionario *inicio);
void liberarFuncionario(Funcionario **inicio, Funcionario **fim);
int calculaDependentes(Funcionario *inicio, char sexo);

// Implementacao das funções
Funcionario *cadastrarFuncionario(Funcionario *funcionario)
{
    Funcionario *novo = malloc(sizeof(Funcionario));

    printf("Digite o código do funcionário: ");
    scanf("%d", &novo->codigo);

    printf("Digite o nome do funcionário: ");
    scanf(" %[^\n]s", novo->nome);

    printf("Digite o sexo do funcionário (F ou M): ");
    scanf(" %c", &novo->sexo);

    printf("Digite o salário do funcionário: ");
    scanf("%f", &novo->salario);

    printf("Digite o número de dependentes do funcionário: ");
    scanf("%d", &novo->dependentes);

    // automaticamente seta 'S' no campo validar
    novo->valido = 'S';

    novo->prox = NULL;
    return novo;
}

void inserirFuncionario(Funcionario **inicio, Funcionario **fim, Funcionario *novo)
{
    if (*inicio == NULL)
    {
        *inicio = novo;
    }
    else
    {
        (*fim)->prox = novo;
    }
    *fim = novo;
}

void removerFuncionario(Funcionario **inicio, Funcionario **fim, int codigo)
{
    Funcionario *aux = *inicio;
    Funcionario *ant = NULL;
    while (aux != NULL && aux->codigo != codigo)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        // mudar o valor do campo 'válido' para N
        aux->valido = 'N';
    }
}

// imprime vetor completo independente do campo 'valido'
void imprimirFuncionarios(Funcionario *inicio)
{
    printf("Nome\t\tSexo\t\tSalario\t\tDep.\t\tValido\t\tCodigo\t\t\n");
    while (inicio != NULL)
    {
        if (inicio->valido == 'S')
        {
            printf("%s\t\t%c\t\t%.2f\t\t%d\t\t%c\t\t%d\n", inicio->nome, inicio->sexo, inicio->salario, inicio->dependentes, inicio->valido, inicio->codigo);
        }
        inicio = inicio->prox;
    }
}

float calculaSalarioTotal(Funcionario *inicio)
{
    float total = 0;
    while (inicio != NULL)
    {
        if (inicio->valido == 'S')
        {
            total += inicio->salario;
        }
        inicio = inicio->prox;
    }
    return total;
}

float calculaSalarioPorSexo(Funcionario *inicio, char sexo)
{
    float total = 0;
    while (inicio != NULL)
    {
        if (inicio->valido == 'S' && inicio->sexo == sexo)
        {
            total += inicio->salario;
        }
        inicio = inicio->prox;
    }
    return total;
}

float calculaSalarioMedioPorSexo(Funcionario *inicio, char sexo)
{
    float total = 0;
    int qtd = 0;
    while (inicio != NULL)
    {
        if (inicio->valido == 'S' && inicio->sexo == sexo)
        {
            total += inicio->salario;
            qtd++;
        }
        inicio = inicio->prox;
    }
    return total / qtd;
}

// nome, sexo, salario e dependentes
void imprimirRelatorio(Funcionario *inicio)
{
    //
    printf("Nome\t\t\tSexo\t\t\tSalario\t\t\tDep.\n");
    printf("================================================================================\n");
    while (inicio != NULL)
    {
        if (inicio->valido == 'S')
        {
            printf("%s\t\t\t%c\t\t\t%.2f\t\t\t%d\n", inicio->nome, inicio->sexo, inicio->salario, inicio->dependentes);
        }
        inicio = inicio->prox;
    }
    printf("================================================================================\n");
}

void liberarFuncionario(Funcionario **inicio, Funcionario **fim)
{
    Funcionario *aux = *inicio;
    while (aux != NULL)
    {
        Funcionario *ant = aux;
        aux = aux->prox;
        free(ant);
    }
    *inicio = NULL;
    *fim = NULL;
}

int calculaDependentes(Funcionario *inicio, char sexo)
{
    int total = 0;
    while (inicio != NULL)
    {
        if (inicio->valido == 'S' && inicio->sexo == sexo)
        {
            total += inicio->dependentes;
        }
        inicio = inicio->prox;
    }
    return total;
}

// Função principal
void main()
{
    Funcionario *inicio = NULL;
    Funcionario *fim = NULL;
    int opcao, codigo;

    do
    {
        printf("**** Menu principal ****\n");
        printf("[ 1 ] Cadastrar dados\n");
        printf("[ 2 ] Processar dados\n");
        printf("[ 3 ] Relatório\n");
        printf("[ 4 ] Excluir dados\n");
        printf("[ 5 ] Demonstracao das funcoes\n");
        printf("[ 0 ] Encerrar programa\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserirFuncionario(&inicio, &fim, cadastrarFuncionario(inicio));
            printf("\n");
            break;
        case 2:
            printf("Total de dependentes.............\n");
            printf("Funcionarios Sexo Masculino =\t %d\n", calculaDependentes(inicio, 'M'));
            printf("Funcionarios Sexo Feminino =\t %d\n\n", calculaDependentes(inicio, 'F'));

            printf("Total Salarios = R$ %.2f\n\n", calculaSalarioTotal(inicio));

            printf("Total Salarios.......................\n");
            printf("Funcionarios Sexo Masculino =\t %d\n", calculaSalarioPorSexo(inicio, 'M'));
            printf("Funcionarios Sexo Feminino =\t %d\n\n", calculaSalarioPorSexo(inicio, 'F'));

            printf("Salario Medio dos funcionarios do Sexo Masculino = R$ %.2f\n", calculaSalarioMedioPorSexo(inicio, 'M'));
            break;
        case 3:
            printf("\n");
            imprimirRelatorio(inicio);
            printf("\t\t\t\t\t\tSalário total: R$ %.2f\n", calculaSalarioTotal(inicio));
            printf("\n");
            break;
        case 4:
            printf("\nDigite o código do funcionário: ");
            scanf("%d", &codigo);
            removerFuncionario(&inicio, &fim, codigo);
            break;
        case 5:
           printf("Incluir 5 registros de funcionários\n");
            for (int i = 0; i < 5; i++)
            {
                inserirFuncionario(&inicio, &fim, cadastrarFuncionario(inicio));
            }

            printf("Imprimir os elementos do vetos\n");
            imprimirFuncionarios(inicio);
            printf("\n");

            printf("Remover o registro correspondente ao número do funcionário informado\n");
            printf("Digite o código do funcionário: ");
            scanf("%d", &codigo);
            removerFuncionario(&inicio, &fim, codigo);
            printf("\n");

            printf("Imprimir novamente os elementos do vetor\n");
            imprimirFuncionarios(inicio);
            printf("\n");

        case 0:
            opcao = 0;
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);
}