#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N, n = 2, k, achou_divisor, cnt = 0;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &N);

    printf("Mostrando os %d primeiros numeros primos:\n", N);
    while (cnt < N) {
        achou_divisor = 0;
        if (n % 2 == 0 && n > 2) achou_divisor = 1;

        k = 3;
        while (k <= sqrt(n) && !achou_divisor) {
            if (n % k == 0) achou_divisor = 1;
            else k = k+2;
        }   
        
        if (!achou_divisor) {
            printf("%d\n", n);
            cnt++;
        }
        n++;
    }
    return 0;
}
