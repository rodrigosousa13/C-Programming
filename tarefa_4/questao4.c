#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double exponencial (double x);

int main() {
    double x, ans;
    printf("Digite um valor para calcular sua exponencial: ");
    scanf("%lf", &x);

    ans = exponencial(x);
    printf("e^(%lf) = %lf", x, ans);

    return 0;
}

double exponencial (double x) {
    double ans = 0, k = 1;
    int i = 1;

    while (fabsf(k) > 1e-6) {
        ans = ans + k;
        k = k * x / i;
        i++;
    }

    return ans;
}
