typedef struct eleitor{
    int titulo;
    char nome[100];
    char endereco[100];
    char secao[100];
    Data *dataNascimento;
    struct eleitor *prox;
} Eleitor;

Eleitor *cadastrarEleitor(Eleitor *eleitor);
void alterarEleitor(int tituloEleitor, Eleitor *eleitores);
Eleitor *excluirEleitor(int tituloEleitor, Eleitor *eleitores);
Eleitor *procurarEleitor(int titulo, Eleitor *eleitores);
void imprimirEleitor(Eleitor *eleitor);
void liberarEleitor(Eleitor *eleitor);
void imprimirMenuEleitor();

Eleitor *cadastrarEleitor(Eleitor *eleitores){
    Eleitor *eleitor = (Eleitor*) malloc(sizeof(Eleitor));
    printf("Digite o título do eleitor: ");
    scanf("%d", &eleitor->titulo);
    fflush(stdin);
    printf("Digite o nome do eleitor: ");
    gets(eleitor->nome);
    printf("Digite o endereço do eleitor: ");
    gets(eleitor->endereco);
    printf("Digite a seção do eleitor: ");
    gets(eleitor->secao);
    eleitor->dataNascimento = (Data*) malloc(sizeof(Data));
    printf("Digite a data de nascimento do eleitor: ");
    scanf("%d/%d/%d", &eleitor->dataNascimento->dia, &eleitor->dataNascimento->mes, &eleitor->dataNascimento->ano);
    eleitor->prox = eleitores;
    return eleitor;
}

void alterarEleitor(int tituloEleitor, Eleitor *eleitores){
    Eleitor *eleitor = procurarEleitor(tituloEleitor, eleitores);
    if(eleitor != NULL){
        printf("Digite o título do eleitor: ");
        scanf("%d", &eleitor->titulo);
        fflush(stdin);
        printf("Digite o nome do eleitor: ");
        gets(eleitor->nome);
        printf("Digite o endereço do eleitor: ");
        gets(eleitor->endereco);
        printf("Digite a seção do eleitor: ");
        gets(eleitor->secao);
        eleitor->dataNascimento = (Data*) malloc(sizeof(Data));
        printf("Digite a data de nascimento do eleitor: ");
        scanf("%d/%d/%d", &eleitor->dataNascimento->dia, &eleitor->dataNascimento->mes, &eleitor->dataNascimento->ano);
    } else {
        printf("Eleitor não encontrado!\n");
    }
}

Eleitor *excluirEleitor(int tituloEleitor, Eleitor *eleitores){
    Eleitor *eleitor = procurarEleitor(tituloEleitor, eleitores);
    if(eleitor != NULL){
        Eleitor *aux = eleitores;
        if(aux == eleitor){
            eleitores = eleitor->prox;
        } else {
            while(aux->prox != eleitor){
                aux = aux->prox;
            }
            aux->prox = eleitor->prox;
        }
        liberarEleitor(eleitor);
    } else {
        printf("Eleitor não encontrado!\n");
    }
    return eleitores;
}

Eleitor *procurarEleitor(int titulo, Eleitor *eleitores){
    Eleitor *aux = eleitores;
    while(aux != NULL && aux->titulo != titulo){
        aux = aux->prox;
    }
    return aux;
}

void imprimirEleitor(Eleitor *eleitor){
    printf("Título: %d\n", eleitor->titulo);
    printf("Nome: %s\n", eleitor->nome);
    printf("Endereço: %s\n", eleitor->endereco);
    printf("Seção: %s\n", eleitor->secao);
    printf("Data de nascimento: %d/%d/%d\n", eleitor->dataNascimento->dia, eleitor->dataNascimento->mes, eleitor->dataNascimento->ano);
}

void liberarEleitor(Eleitor *eleitor){
    free(eleitor->dataNascimento);
    free(eleitor);
}

void imprimirMenuEleitor() {
    int opcao;
    int tituloEleitor;
    Eleitor *eleitores = NULL;
    Eleitor *aux = NULL;

    do{
        printf("\n");
        printf("1 - Cadastrar eleitor\n");
        printf("2 - Alterar eleitor\n");
        printf("3 - Excluir eleitor\n");
        printf("4 - Imprimir eleitores\n");
        printf("5 - Voltar\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao){
            case 1:
                eleitores = cadastrarEleitor(eleitores);
                break;
            case 2:
                printf("Digite o título do eleitor: ");
                scanf("%d", &tituloEleitor);
                alterarEleitor(tituloEleitor, eleitores);
                break;
            case 3:
                printf("Digite o título do eleitor: ");
                scanf("%d", &tituloEleitor);
                eleitores = excluirEleitor(tituloEleitor, eleitores);
                break;
            case 4:
                aux = eleitores;
                while(aux != NULL){
                    imprimirEleitor(aux);
                    aux = aux->prox;
                }
                break;
        }
    } while(opcao != 5);
}