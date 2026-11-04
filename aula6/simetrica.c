#include <stdio.h>
#include <math.h>

int main() {
    int m[5][5], i, j, simetrica = 1;

    for (i=0;i<5;i++) {
        for (j=0;j<5;j++) {
            printf("m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);

            if ((i>j) && simetrica && (m[i][j] != m[j][i])) {
                simetrica = 0;
            }
        }
    }

    if (simetrica) {
        printf("Matriz simetrica!");
    } else {
        printf("Matriz NAO simetrica.");
    }

    return 0;
}
