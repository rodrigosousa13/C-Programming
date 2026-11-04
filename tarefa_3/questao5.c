#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long num, inv = 0;
    int i;

    do {
        printf("Digite um numero inteiro positivo de 10 digitos: ");
        scanf("%lld", &num);
    } while (num < pow(10, 9) || num >= pow(10, 10));

    
    for (i=0; i<10; i++) {
        inv = inv * 10 + num % 10;
        num = num / 10;
    }

    printf("Numero invertido: %lld", inv);
    return 0;
}