#include <stdio.h>
#include <stdlib.h>

int main() {
    float l1, l2, l3, maior, soma, produto;

    printf("Digite os lados do triangulo (maiores que zero) para determinar se ele eh retangulo\n");
    printf("Lado 1: ");
    scanf("%f", &l1);
    maior = l1;
    printf("Lado 2: ");
    if (l2 > l1)
        maior = l2;
    scanf("%f", &l2);
    printf("Lado 3: ");
    scanf("%f", &l3);
    if (l3 > maior)
        maior = l3;

    soma = l1 + l2 + l3 - maior;
    produto = l1 * l2 * l3 / maior;
    /* a^2 + b^2 = (a+b)^2 - 2ab */
    if ( maior*maior == soma*soma - 2*produto )
        printf("Eh retangulo.");
    else
        printf("NAO eh retangulo.");
    return 0;
}