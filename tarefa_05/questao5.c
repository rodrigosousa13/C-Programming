#include <stdio.h>

int eh_palindromo(long int num);

int main() {
    long int num;
    printf("Digite um inteiro positivo para checar se eh palindromo: ");
    scanf("%ld", &num);

    if (eh_palindromo(num)) printf("Eh palindromo!");
    else printf("NAO eh palindromo");

    return 0;
}

int eh_palindromo (long int num) {
    long int k = 10, dig1;
    while (k < num) k = k * 10;
    k = k / 10;
    dig1 = num / k;

    if (num < 10) return 1;
    else if (dig1 != num % 10) return 0;
    else {
        num = (num - dig1 * k) / 10;
        return eh_palindromo(num);
    }
}
