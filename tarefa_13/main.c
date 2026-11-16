#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "abb.h"

void shuffle(int *array, size_t n) {
    size_t i, j;
    int t;
    if (n > 1) {
        for (i = 0; i < n - 1; i++) {
          j = i + rand() / (RAND_MAX / (n - i) + 1);
          t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main() {
    ArvoreBB *arvore = malloc(sizeof(ArvoreBB));
    FILE *f;
    static int chaves[1000000];
    int i, sucesso;
    float valor = 1.0;
    /* tempo de execucao */
    struct timeval inicio, fim;
    double t = 1.0;

    gettimeofday(&inicio, NULL);
    printf("Inicializando arvore...\n");
    srand((int)time(NULL));
    inicializar(&arvore);

    /* gerando chaves unicas */
    printf("Gerando chaves...\n");
    chaves[0] = 1;
    for (i = 1; i < 1000000; i++) {
        chaves[i] = chaves[i-1] + (rand() % 3) + 1; 
    }
    printf("Embaralhando chaves...\n");
    shuffle(chaves, 1000000);
    
    printf("Populando arvore...\n");
    for (i = 0; i < 1000000; i++) {
        valor = (float) 100 * rand() / RAND_MAX;
        if (i % 2 == 0) {
            sucesso = inserir_recursivo(&arvore, chaves[i], valor);
        } else {
            sucesso = inserir_iterativo(&arvore, chaves[i], valor);
        }

        if (!sucesso) {
            fprintf(stderr, "Erro ao inserir chave %d\n", chaves[i]);
        }
    }
    printf("Elementos adicionados com sucesso.\n\n");

    printf("Buscando elemento de chave %d:", chaves[0]);
    valor = buscar_iterativo(arvore, chaves[0]);
    if (valor < 0) {
        printf("Nao achado\n");
    } else {
        printf(" valor -> %f\n", valor);
    }
    
    printf("Buscando elemento de chave %d:", chaves[1]);
    valor = buscar_recursivo(&arvore, chaves[1]);
    if (valor < 0) {
        printf("Nao achado\n");
    } else {
        printf(" valor -> %f\n", valor);
    }

    printf("Listando todos os elementos...\n");
    f = fopen("elementos.txt", "w");
    if (f == NULL) {
        perror("fopen");
        free(arvore);
        return EXIT_FAILURE;
    }
    listar_elementos(&arvore, f);
    printf("Lista de elementos salvo em elementos.txt\n");
    fclose(f);

    gettimeofday(&fim, NULL);
    t = (double) (fim.tv_usec - inicio.tv_usec) / 1000000 + (double) (fim.tv_sec - inicio.tv_sec);
    printf("\nTempo de execucao: %lf segundos\n", t);

    free(arvore);
    return EXIT_SUCCESS;
}