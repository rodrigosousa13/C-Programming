#include <stdio.h>

#define MAX 20

void mult(int A[][MAX], int B[][MAX], int M[][MAX], int x, int y, int z);

int main() {
    int A[MAX][MAX];
    int B[MAX][MAX];
    int AB[MAX][MAX];
    int x, y, z;
    int i, j;

    printf("Digite 3 inteiros entre 2 e 20, separados por espaco: ");
    scanf("%d %d %d", &x, &y, &z);

    printf("Digite os numeros da primeira matriz (%dx%d):\n", x, y);
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("Digite os numeros da segunda matriz (%dx%d):\n", y, z);
    for (i = 0; i < y; i++) {
        for (j = 0; j < z; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    mult(A, B, AB, x, y, z);

    printf("\nProduto das matrizes:\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < z; j++) {
            printf("%d ", AB[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void mult(int A[][MAX], int B[][MAX], int M[][MAX], int x, int y, int z) {
    int i, j, k;

    for (i = 0; i < x; i++) {
        for (j = 0; j < z; j++) {
            for (k = 0; k < y; k++) {
                M[i][j] = M[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }
}
