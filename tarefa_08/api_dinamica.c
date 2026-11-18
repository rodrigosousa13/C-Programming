#include <stdlib.h>
#include "api_dinamica.h"

void * criar_vetor(int tamanho) {
    void *mem;
    mem = malloc((tamanho + 1) * sizeof(double));
    ((double*) mem)[0] = tamanho;
    return (double*)mem + 1;
}
double obter_vetor(void *mem, int x) {
    int tamanho;
    if (mem != NULL)
        tamanho = (int) ((double*) mem)[-1];
        if (x >= 0 && x < tamanho)
            return ((double*) mem)[x];
    return 0.0 / 0.0; /* nan */
    }
int atribuir_vetor(void *mem, int x, double valor) {
    int tamanho;
    if (mem == NULL)
        return 1;
    tamanho = (int) ((double*) mem)[-1];
    if (x >= tamanho)
        return 1;
    ((double*) mem)[x] = valor;
    return 0;
}
void liberar_vetor(void *mem) {
    if (mem != NULL)
       free((double*)mem - 1);
}

void * criar_matriz(int tamanho_x, int tamanho_y) {
    void *mem;
    mem = malloc((2 + tamanho_x * tamanho_y) * sizeof(double));
    ((double*) mem)[0] = tamanho_x;
    ((double*) mem)[1] = tamanho_y;

    return (double*)mem + 2;
}
double obter_matriz(void *mem, int x, int y) {
    int tam_x, tam_y;
    if (mem != NULL){
        tam_x = ((double*) mem)[-2];
        tam_y = ((double*) mem)[-1];
        if (x >= 0 && x < tam_x && y >= 0 && y < tam_y)
            return ((double*) mem)[x * tam_y + y];
    }
    return 0.0 / 0.0; /* nan */
    }
int atribuir_matriz(void *mem, int x, int y, double valor) {
    int tam_x, tam_y;
    if (mem == NULL)
        return 1;
    tam_x = (int) ((double*) mem)[-2];
    tam_y = (int) ((double*) mem)[-1];

    if (x >= 0 && x < tam_x && y >= 0 && y < tam_y)
        ((double*) mem)[x * tam_y + y] = valor;
        return 0;
    return 1;
}
void liberar_matriz(void *mem) {
    if (mem != NULL)
        free((double*)mem - 2);
}