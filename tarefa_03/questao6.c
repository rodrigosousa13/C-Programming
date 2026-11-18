#include <stdio.h>
#include <stdlib.h>

int main() {
    int count_3 = 0, count_resto = 0, num;
    float media1 = 0, media2 = 0;

    while (count_3 < 10) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &num);

        if (num % 3 == 0) {
            media1 = media1 + num;   
            count_3++;
        } else {
            media2 = media2 + num;
            count_resto++;
        }
    }
    media1 = media1 / count_3;
    printf("Media dos numeros multiplos de 3: %.3f\n", media1);
    if (count_resto > 0) {
        media2 = media2 / count_resto;
        printf("Media dos outros numeros: %.3f", media2);
    }

    return 0;
}
