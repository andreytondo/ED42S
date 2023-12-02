typedef struct candidato{
    int numero;
    char nome[100];
    char partido[100];
    char cargo[100];
    Data *dataNascimento;
    struct candidato *prox;
} Candidato;

Candidato *cadastrarCandidato(Candidato *candidato);\
void alterarCandidato(int numeroCandidato, Candidato *candidatos);
Candidato *excluirCandidato(int numeroCandidato, Candidato *candidatos);
Candidato *procurarCandidato(int numero, Candidato *candidatos);
void imprimirCandidato(Candidato *candidato);
void liberarCandidato(Candidato *candidato);
void imprimirMenuCandidato();

Candidato *cadastrarCandidato(Candidato *candidatos){
    Candidato *candidato = (Candidato*) malloc(sizeof(Candidato));
    printf("Digite o número do candidato: ");
    scanf("%d", &candidato->numero);
    fflush(stdin);
    printf("Digite o nome do candidato: ");
    gets(candidato->nome);
    printf("Digite o partido do candidato: ");
    gets(candidato->partido);
    printf("Digite o cargo do candidato: ");
    gets(candidato->cargo);
    candidato->dataNascimento = (Data*) malloc(sizeof(Data));
    printf("Digite a data de nascimento do candidato: ");
    scanf("%d/%d/%d", &candidato->dataNascimento->dia, &candidato->dataNascimento->mes, &candidato->dataNascimento->ano);
    candidato->prox = candidatos;
    return candidato;
}

void alterarCandidato(int numeroCandidato, Candidato *candidatos){
    Candidato *candidato = procurarCandidato(numeroCandidato, candidatos);
    if(candidato != NULL){
        printf("Digite o número do candidato: ");
        scanf("%d", &candidato->numero);
        fflush(stdin);
        printf("Digite o nome do candidato: ");
        gets(candidato->nome);
        printf("Digite o partido do candidato: ");
        gets(candidato->partido);
        printf("Digite o cargo do candidato: ");
        gets(candidato->cargo);
        candidato->dataNascimento = (Data*) malloc(sizeof(Data));
        printf("Digite a data de nascimento do candidato: ");
        scanf("%d/%d/%d", &candidato->dataNascimento->dia, &candidato->dataNascimento->mes, &candidato->dataNascimento->ano);
    } else {
        printf("Candidato não encontrado!\n");
    }
}

Candidato *excluirCandidato(int numeroCandidato, Candidato *candidatos){
    Candidato *candidato = procurarCandidato(numeroCandidato, candidatos);
    if(candidato != NULL){
        Candidato *aux = candidatos;
        if(aux == candidato){
            candidatos = candidatos->prox;
        } else {
            while(aux->prox != candidato){
                aux = aux->prox;
            }
            aux->prox = candidato->prox;
        }
        liberarCandidato(candidato);
    } else {
        printf("Candidato não encontrado!\n");
    }
    return candidatos;
}

Candidato *procurarCandidato(int numero, Candidato *candidatos){
    Candidato *aux = candidatos;
    while(aux != NULL && aux->numero != numero){
        aux = aux->prox;
    }
    return aux;
}

void imprimirCandidato(Candidato *candidato){
    printf("Número: %d\n", candidato->numero);
    printf("Nome: %s\n", candidato->nome);
    printf("Partido: %s\n", candidato->partido);
    printf("Cargo: %s\n", candidato->cargo);
    printf("Data de nascimento: %d/%d/%d\n", candidato->dataNascimento->dia, candidato->dataNascimento->mes, candidato->dataNascimento->ano);
}

void liberarCandidato(Candidato *candidato){
    free(candidato->dataNascimento);
    free(candidato);
}

void imprimirMenuCandidato() {
    Candidato *candidatos = NULL;
    Candidato *aux = NULL;
    int opcao;
    int numeroCandidato;

    do{
        printf("1 - Cadastrar candidato\n");
        printf("2 - Alterar candidato\n");
        printf("3 - Excluir candidato\n");
        printf("4 - Listar candidatos\n");
        printf("5 - Voltar\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                candidatos = cadastrarCandidato(candidatos);
                break;
            case 2:
                printf("Digite o número do candidato: ");
                scanf("%d", &numeroCandidato);
                alterarCandidato(numeroCandidato, candidatos);
                break;
            case 3:
                printf("Digite o número do candidato: ");
                scanf("%d", &numeroCandidato);
                candidatos = excluirCandidato(numeroCandidato, candidatos);                
                break;
            case 4:
                aux = candidatos;
                while(aux != NULL){
                    imprimirCandidato(aux);
                    aux = aux->prox;
                }
                break;
        }
    } while(opcao != 5);
}



