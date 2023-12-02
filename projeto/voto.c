typedef struct voto{
    int numeroCandidato;
    int numeroUrna;
    int numeroEleitor;
    Data *dataVoto;
    struct voto *prox;
} Voto;

Voto *cadastrarVoto(Voto *voto);
Voto *procurarVoto(int numeroEleitor, Voto *votos);
void imprimirVoto(Voto *voto);
void imprimirMenuVoto();

Voto *cadastrarVoto(Voto *votos){
    Voto *voto = (Voto*) malloc(sizeof(Voto));
    printf("Digite o número do candidato: ");
    scanf("%d", &voto->numeroCandidato);
    fflush(stdin);
    printf("Digite o número da urna: ");
    scanf("%d", &voto->numeroUrna);
    fflush(stdin);
    printf("Digite o número do eleitor: ");
    scanf("%d", &voto->numeroEleitor);
    fflush(stdin);
    voto->dataVoto = (Data*) malloc(sizeof(Data));
    printf("Digite a data do voto: ");
    scanf("%d/%d/%d", &voto->dataVoto->dia, &voto->dataVoto->mes, &voto->dataVoto->ano);
    voto->prox = votos;
    return voto;
}

Voto *procurarVoto(int numeroEleitor, Voto *votos){
    Voto *aux = votos;
    while(aux != NULL && aux->numeroEleitor != numeroEleitor){
        aux = aux->prox;
    }
    return aux;
}

void imprimirVoto(Voto *voto){
    printf("Número do candidato: %d\n", voto->numeroCandidato);
    printf("Número da urna: %d\n", voto->numeroUrna);
    printf("Número do eleitor: %d\n", voto->numeroEleitor);
    printf("Data do voto: %d/%d/%d\n", voto->dataVoto->dia, voto->dataVoto->mes, voto->dataVoto->ano);
}

void imprimirMenuVoto() {
    int opcao;
    int numeroEleitor;
    Voto *votos = NULL;
    Voto *aux = NULL;

    do {
        printf("1 - Cadastrar voto\n");
        printf("2 - Imprimir votos\n");
        printf("3 - Voltar\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                votos = cadastrarVoto(votos);
                break;
            case 2:
                aux = votos;
                while(aux != NULL) {
                    imprimirVoto(aux);
                    aux = aux->prox;
                }
                break;
        }
    } while(opcao != 3);
}
