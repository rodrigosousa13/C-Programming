#include <stdio.h>
#include <stdlib.h>

int main() {
    float a, b, div;
    printf("Esse programa faz a divisao de 2 numeros\n");
    printf("Digite o numerador: ");
    scanf("%F", &a);
    printf("Digite o denominador: ");
    scanf("%f", &b);

    if (b != 0) {
        div = a / b;
        printf("%f / %f = %f", a, b, div);
    } else {
        printf("Erro: divisao por zero. Digite um denominador valido");
    }
    return 0;
}
