#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, a, b;
    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &N);
    } while (N <= 0);

    a = 0;
    b = 1;
    printf("Termos de fibonacci menores que %d:\n", N);
    while (b < N) {
        printf("%d\n", b);
        b = a + b;
        a = b - a;
    }
    return 0;
}
