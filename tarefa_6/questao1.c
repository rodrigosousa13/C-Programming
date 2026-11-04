#include <stdio.h>

int main() {
    int N, i, j, res, achou, cont = 0;
    int nums[15], acertos[6];

    do {
        printf("Quantidade de numeros preenchidos: ");
        scanf("%d", &N);
    } while (N < 6 || N > 15);

    for (i = 0; i < N; i++) {
        printf("Palpite no. %d: ", i+1);
        scanf("%d", &nums[i]);
    }

    printf("\nAgora insira os 6 numeros sorteados\n");
    for (i = 0; i < 6; i++) {
        printf("%do. numero: ", i+1);
        scanf("%d", &res);
        j = 0;
        achou = 0;
        while (!achou && j < N) {
            if (res == nums[j]) {
                achou = 1;
                acertos[cont] = res;
                cont++;
            }
            j++;
        }
    }

    printf("\nQuantidade de acertos: %d", cont);
    if (cont == 6)
        printf(" (Mega-Sena!)");
    else if (cont == 5)
        printf(" (Quina!)");
    else if (cont == 4)
        printf(" (Quadra!)");
    printf("\n");

    if (cont > 0) {
        printf("Palpites certos: ");
        for (i = 0; i < cont; i++)
            printf("%d ", acertos[i]);
        printf("\n");
    }

    return 0;
}
