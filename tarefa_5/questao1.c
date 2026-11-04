#include <stdio.h>
#include <stdlib.h>

int resto (int a, int b);

int main() {
    int a, b, res;

    printf("Calcule o resto da divisao de um numero pelo outro (inteiros positivos)\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
     
    res = resto(a, b);
    if (res != -1) {
        printf("%d %% %d = %d", a, b, res);
    }

    return 0;
}

int resto(int a, int b) {
    if (b == 0) {
        printf("Erro: divisao por zero\n");
        return -1;
    }
    if (a < b) return a;
    else return resto(a-b, b);
}
