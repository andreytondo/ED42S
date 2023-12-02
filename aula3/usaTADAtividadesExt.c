#include <stdio.h>
#include <stdlib.h>
#include "atividadesExt.c"

void main() {
    int opcao;
    AtividadeExt *atividades = NULL;
    do {
        printf("\n1 - Cadastrar atividade\n");
        printf("2 - Imprimir atividades\n");
        printf("3 - Verificar atividades\n");
        printf("4 - Liberar atividades da memória\n");
        printf("5 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                atividades = cadastrarAtividade(atividades);
                break;
            case 2:
                imprimirAtividades(atividades);
                break;
            case 3:
                verificarAtividades(atividades);
                break;
            case 4:
                liberarAtividades(atividades);
                break;
        }
    } while (opcao != 5);

    verificarAtividades(atividades);
}