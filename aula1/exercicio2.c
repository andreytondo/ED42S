/*
2. Faça um programa que leia um vetor com os dados de 5 instrumentos musicais: modelo,
marca e preço. Leia um valor p e mostre as informações de todos os instrumentos com
preço menor que p. Repita este processo até que seja lido um valor p = 0.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct instrumento
{
    char modelo[50], marca[50];
    float preco;
} Instrumento;

mostraInstrumento(Instrumento instrumento)
{
    printf("\nModelo: %s", instrumento.modelo);
    printf("\nMarca: %s", instrumento.marca);
    printf("\nPreço: %.2f", instrumento.preco);
}

main()
{
    int tamanho = 5;
    Instrumento instrumentos[tamanho];
    float p;

    for (int i = 0; i < tamanho; i++)
    {
        fflush(stdin);
        printf("Digite o modelo do instrumento: ");
        gets(instrumentos[i].modelo);

        printf("Digite a marca do instrumento: ");
        gets(instrumentos[i].marca);

        printf("Digite o preço do instrumento: ");
        scanf("%f", &instrumentos[i].preco);
    }

    printf("Digite um valor: ");
    scanf("%f", &p);

    for (int i = 0; i < tamanho; i++)
    {
        if (instrumentos[i].preco < p)
        {
            mostraInstrumento(instrumentos[i]);
        }
    }
}