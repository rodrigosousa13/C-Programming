#include <stdlib.h>
#include <stdio.h>

int main (int narg, char *argv[]) {
    // dado X anos, exibir quantas batidas de coração
    // uma pessoa teve, dado 70 batidas/min
    // 1 ano = 365,25 dias

    int X;
    printf("Digite sua idade em anos:");
    scanf("%d", &X);

    double batidas = X * 365.25 * 24 * 60 * 70;
    printf("Seu coracao ja bateu aproximadamente %.0f vezes\n", batidas);

    return 0;
}