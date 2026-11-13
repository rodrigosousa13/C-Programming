#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    Fila *fila = malloc(sizeof(Fila));
    char *nome;
    if (fila == NULL) {
        return EXIT_FAILURE;
    }

    inicializar(&fila);

    enfileirar(fila, "Ana", 123, 50.0f);
    enfileirar(fila, "Bruno", 456, 75.5f);

    printf("Tamanho: %d\n", fila_tamanho(fila));
    printf("Proxima conta: %d\n", fila_consulta_conta_proximo(fila));
    printf("Proximo valor: %.2f\n", fila_consultar_valor_proximo(fila));
    printf("Fila vazia? %s\n", fila_vazia(fila) ? "sim" : "nao");

    nome = fila_desenfileirar(fila);
    if (nome != NULL) {
        printf("Desenfileirado: %s\n", nome);
        free(nome);
    }

    free(fila);
    return EXIT_SUCCESS;
}