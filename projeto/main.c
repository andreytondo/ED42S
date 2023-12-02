/*
• Criar um projeto prático, implementado na linguagem C, empregando os conceitos de TADs
e encapsulamento, voltado para armazenar e recuperar dados de uma determinada aplicação,
inserida no contexto do seguintes item: Eleição

Definir quais dados serão armazenados (no mínimo 5 campos de tipos diversos).

• Permitir a execução de operações básicas como: inserção, consulta, alteração e exclusão, que
devem ser apresentadas ao usuário na forma de um menu.

• Em um documento, descreva o contexto em que o projeto foi desenvolvido, justificando a escolha
do estudo de caso.

• Apresentar para o professor o projeto finalizado ou em desenvolvimento, descrevendo o contexto
escolhido e implementação realizada.
*/

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#include "data.h"
#include "candidato.c"
#include "eleitor.c"
#include "urna.c"
#include "voto.c"

#define MAX 100

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    Candidato *candidatos = NULL;
    Eleitor *eleitores = NULL;
    Urna *urnas = NULL;
    Voto *votos = NULL;
    do{
        printf("\n1 - Menu de candidatos\n");
        printf("2 - Menu de eleitores\n");
        printf("3 - Menu de urnas\n");
        printf("4 - Menu de votos\n");
        printf("5 - Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                imprimirMenuCandidato();
                break;
            case 2:
                imprimirMenuEleitor();
                break;
            case 3:
                imprimirMenuUrna();
                break;
            case 4:
                imprimirMenuVoto();
                break;
        }
    } while(opcao != 5);
}


