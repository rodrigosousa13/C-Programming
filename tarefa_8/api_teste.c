#include <stdio.h>
#include "api_dinamica.h"

int main() {
    int a = 0, b = 4, c = 6;
    double *v, *m;

    /* Teste funcoes vetor */
    v = criar_vetor(10);
    atribuir_vetor(v, 0, 7);
    atribuir_vetor(v, 4, 2);
    atribuir_vetor(v, 6, 7);

    printf("v[%d]: %lf\n", a, obter_vetor(v, a));
    printf("v[%d]: %lf\n", b, obter_vetor(v, b));
    printf("v[%d]: %lf\n", c, obter_vetor(v, c));

    liberar_vetor(v);

    /* Teste funcoes matriz*/
    m = criar_matriz(4, 6);
    atribuir_matriz(m, 1, 3, 5);
    atribuir_matriz(m, 2, 3, 5);
    atribuir_matriz(m, 3, 4, 5);

    printf("m[1][3] = %lf\n", obter_matriz(m, 1, 3));
    printf("m[2][3] = %lf\n", obter_matriz(m, 2, 3));
    printf("m[3][4] = %lf\n", obter_matriz(m, 3, 4));
    
    liberar_matriz(m);

    return 0;
}
