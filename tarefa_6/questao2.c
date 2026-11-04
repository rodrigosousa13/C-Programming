#include <stdio.h>
#include <math.h>

int checa_pg(int N, int nums[], float * r) {
    int i = 1, so_zeros = 1;
    /* so_zeros checa se todos os numeros apos
    o primeiro sao zeros */
    float r_new;
    
    if (N <= 1) return 0; /* considerando que 1 termo nao forma pg*/
    while (so_zeros && i < N) {
        if (nums[i] != 0) so_zeros = 0;
        i++;
    }
    
    if (nums[0] != 0) {
        *r = (float) nums[1] / nums[0];
        if (*r == 0.0) {
            return so_zeros ? 1 : 0;
        }
    } else if (so_zeros) {
        *r = 0.0 / 0.0;
        return 1;
    } else return 0;

    i = 2;
    while (i < N) {
        if (nums[i-1] != 0) {
            r_new = (float) nums[i] / nums[i-1];
            if (r_new != *r) return 0;
        } else return 0;
        i++;
    }
    return 1;
}

int main() {
    int N, i;
    int nums[1000];
    float r;

    do {
        printf("Quantidade de numeros inteiros a serem entrados: ");
        scanf("%d", &N);
    } while (N < 0 || N > 1000);
    
    for (i = 0; i < N; i++) {
        printf("Digite o %do. numero inteiro: ", i+1);
        scanf("%d", &nums[i]);
    }
    
    if (checa_pg(N, nums, &r)) {
        printf("\nOs numeros formam uma PG.\n");
        if (isnan(r)) printf("Razao da PG: indefinido");
        else printf("Razao da PG: %f", r);
    } else {
        printf("\nOs numeros NAO formam uma PG.\n");
    }
    
    return 0;
}
