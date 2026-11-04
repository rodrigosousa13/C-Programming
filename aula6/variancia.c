#include <stdio.h>
#include <math.h>

int main() {
    double v[5], media = 0, var = 0;
    int i;

    for (i=0;i<5;i++) {
        printf("%d numero: ", i+1);
        scanf("%lf", &v[i]);
        media = media + v[i];
    }
    media = media / 5;

    for (i=0;i<5;i++) {
        var = var + pow((v[i] - media), 2);
    }
    var = var / 5;

    printf("Variancia dos numeros digitados: %lf", var);
    return 0;
}
