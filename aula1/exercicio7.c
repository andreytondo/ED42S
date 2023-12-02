/*
7. Crie uma estrutura para armazenar uma coordenada polar, composta por raio (r) e
argumento (a). Crie também uma estrutura para armazenar uma coordenada do plano
cartesiano, composta por x e y, sabendo que:
x = r ∗ cos(a)
y = r ∗ sin(a)
No programa principal, leia e salve um ponto em coordenada polar. Faça a conversão de
coordenada polar para coordenada cartesiana e salve o resultado como um ponto do plano
cartesiano. Mostre o ponto resultante.
*/

#include <stdio.h>
#include <math.h>

typedef struct coordPolar {
    float raio, angulo;
} CoordenadaPolar;

typedef struct coordCartesiana {
    float x,y;
} CoordenadaCartesiana;

main() {
    CoordenadaPolar cPolar;
    CoordenadaCartesiana cCartesiana;

    printf("Digite o raio da coordenada polar: ");
    scanf("%f", &cPolar.raio);

    printf("Digite o angulo da coordenada polar: ");
    scanf("%f", &cPolar.angulo);

    printf("\nO ponto em um plano cartesiano possui as seugintes coordenadas: (%.2f, %.2f)", cPolar.raio * cos(cPolar.angulo), cPolar.raio * sin(cPolar.angulo));
}