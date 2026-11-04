#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pot (double x, int k);

int main() {
    double x;
    int k;

    printf("Teste funcao potencia\n");
    printf("Valor da base: ");
    scanf("%lf", &x);
    printf("Valor do expoente (inteiro positivo): ");
    scanf("%d", &k);

    printf("Resultado funcao pot: %lf\n", pot(x, k));
    printf("Resultado funcao pow: %lf", pow(x, k));
}

double pot (double x, int k) {
    if (k == 0) return 1;
    else return x * pot(x, k-1);
}
