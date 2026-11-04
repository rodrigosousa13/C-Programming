#include <stdio.h>
#include <math.h>

double expo(double x, double acc, int i);

int main() {
    double x;
    printf("Digite um valor para calcular sua exponencial: ");
    scanf("%lf", &x);

    printf("e^(%lf) = %lf", x, expo(x, 1, 1));
    return 0;
}

double expo (double x, double acc, int i) {
    int j;
    double k = 1.0;
    
    for (j=1; j<=i; j++) {
        k = k * x / j;
    }
    if (k <= 1e-6) return acc;
    else return expo(x, acc+k, i+1);
}
