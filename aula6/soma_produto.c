#include <stdio.h>
#include <math.h>

int main() {
    double v[10], soma = 0, produto = 1;
    int i;
    for (i=0;i<10;i++) {
        printf("%do. numero: ", i+1);
        scanf("%lf", &v[i]);
        soma = soma + v[i];
        produto = produto * v[i];
    }

    printf("Somatorio: %lf", soma);
    printf("Produtorio: %lf", produto);

    return 0; 
}
