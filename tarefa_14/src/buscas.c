#include "buscas.h"

int busca_sequencial(int array[], int n, int key) {
    /* 
        busca pela key no vetor
        retorna 1 caso exista, 0 caso contrario
    */
    int i;

    for (i = 0; i < n; i++) {
        if (array[i] == key) {
            return 1;
        }
    }
    return 0;
}

int busca_binaria(int array[], int s, int f, int key) {
    int m = (s + f) / 2;

    if (s >= f) return 0;

    if (array[m] < key)
        return busca_binaria(array, m+1, f, key);
    else if (array[m] > key)
        return busca_binaria(array, s, m-1, key);

    return 1;
}