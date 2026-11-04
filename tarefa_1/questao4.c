#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
    printf("Digite o numero de 3 digitos: ");
    int num;
    scanf("%d", &num);

    int d1, d2, d3;
    d1 = num / 100;
    d2 = num % 100 / 10;
    d3 = num % 10;

    int num_inv = 100*d3 + 10*d2 + d1;
    printf("O numero invertido eh %d\n", num_inv);

}