typedef struct urna{
    int numero;
    char local[100];
    char zona[100];
    char secao[100];
    struct urna *prox;
} Urna;

Urna *cadastrarUrna(Urna *urna);
Urna *procurarUrna(int numero, Urna *urnas);
void imprimirUrna(Urna *urna);
void imprimirMenuUrna();

Urna *cadastrarUrna(Urna *urnas){
    Urna *urna = (Urna*) malloc(sizeof(Urna));
    printf("Digite o número da urna: ");
    scanf("%d", &urna->numero);
    fflush(stdin);
    printf("Digite o local da urna: ");
    gets(urna->local);
    printf("Digite a zona da urna: ");
    gets(urna->zona);
    printf("Digite a seção da urna: ");
    gets(urna->secao);
    urna->prox = urnas;
    return urna;
}

Urna *procurarUrna(int numero, Urna *urnas){
    Urna *aux = urnas;
    while(aux != NULL && aux->numero != numero){
        aux = aux->prox;
    }
    return aux;
}

void imprimirUrna(Urna *urna){
    printf("Número: %d\n", urna->numero);
    printf("Local: %s\n", urna->local);
    printf("Zona: %s\n", urna->zona);
    printf("Seção: %s\n", urna->secao);
}

void imprimirMenuUrna(){
    int opcao;
    int numeroUrna;
    Urna *urnas = NULL;
    Urna *aux = NULL;

    do{
        printf("1 - Cadastrar urna\n");
        printf("2 - Imprimir urnas\n");
        printf("3 - Voltar\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch(opcao){
            case 1:
                urnas = cadastrarUrna(urnas);
                break;
            case 2:
                printf("Digite o número da urna: ");
                scanf("%d", &numeroUrna);
                alterarUrna(numeroUrna, urnas);
                break;
        }
    } while(opcao != 3);
}