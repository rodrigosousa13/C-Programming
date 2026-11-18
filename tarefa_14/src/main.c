#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "estruturas.h"
#include "buscas.h"

#define N 5000000
#define K 100


int main(int narg, char *argv[]) {
    int i, j, r, chave, sucesso;
    static int chaves[N];
    float valor;
    LDE *lista = inicializar_lista();
    ABB *arvore = inicializar_arvore();
    struct timeval inicio, fim;
    double t = 1.0;
    char *print[] = {
        "Busca na ABB", "Busca na LDE", "Busca sequencial", "Busca binaria"
    };

    srand((int)time(NULL));

    printf("Preenchendo arvore e lista...\n");
    for (i = 0; i < N; i++) {
        chave = rand();
        valor = ((float) rand() / RAND_MAX) * 1000.0;

        sucesso = inserir_abb(arvore, chave, valor);
        while (!sucesso) {
            chave = rand();
            sucesso = inserir_abb(arvore, chave, valor);
        }
        inserir_lista(lista, chave, valor);
    }

    printf("Preenchendo vetor de chaves...\n");
    percorrer_arvore(arvore, chaves, 0);

    for (i = 0; i < 4; i++) {

        gettimeofday(&inicio, NULL);
        printf("%s\n", print[i]);
        for (j = 0; j < K; j++) {

            chave = rand();
            switch (i) {
                case 0:
                    buscar_abb(arvore, chave);
                    break;
                case 1:
                    buscar_lista(lista, chave);
                    break;
                case 2:
                    busca_sequencial(chaves, N, chave);
                    break;
                case 3:
                    busca_binaria(chaves, 0, N-1, chave);
                    break;
            }
            
        }
        gettimeofday(&fim, NULL);
        t = (double) (fim.tv_usec - inicio.tv_usec) / 1000000 + (double) (fim.tv_sec - inicio.tv_sec);
        printf("Tempo de execucao: %lf segundos\n", t);
    }

    free(arvore);
    free(lista);

    return EXIT_SUCCESS;

}