#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N, n, k, achou_divisor, achou_primo;
    printf("Digite um numero inteiro: ");
    scanf("%d", &N);

    n = N-1; /*comeca a olhar do numero anterior a N e vai descendo ate achar um primo*/
    achou_primo = 0;
    while (n > 1 && !achou_primo) { 
        achou_divisor = 0;
        if (n % 2 == 0) achou_divisor = 1;
        
        k = 3;
        while ((k <= sqrt(n)) && !achou_divisor) {
            if (n % k == 0) achou_divisor = 1;
            else k = k + 2;
        }

        if (!achou_divisor) achou_primo = 1;
        else n--;
    }
    /*exibe n+1, uma vez que n-- no final do loop*/
    if (achou_primo) printf("Maior primo menor que %d: %d", N, n);
    else printf("Nao existe nenhum numero primo menor que %d", N);
    return 0;
}   
