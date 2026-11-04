#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_polimorfica.h"

int main() {
    Lista *lista = malloc(sizeof(lista));
    int i, k = 0, ival, keys[12];
    float fval;
    char *nomes[] = {"Ana", "Beto", "Carla"};
    char cval;
    
    inicializar(&lista);
    printf("\n\nPreenchendo lista com elementos aleatorios...\n\n");
    srand((int)time(NULL));
    for (i = 0; i < 3; i++) {
        keys[k] = rand() % 100;
        ival = rand() % 100;
        if (!inserir_inteiro(&lista, keys[k], ival)) {
            printf("Valor %d nao foi inserido na lista\n", ival);
            keys[k] = -1;
        } else k++;

        keys[k] = rand() % 100;
        fval = (float) rand() / RAND_MAX;
        if (!inserir_p_flutuante(&lista, keys[k], fval)) {
            printf("Valor %f nao foi inserido na lista\n", fval);
            keys[k] = -1;
        } else k++;

        keys[k] = rand() % 100;
        if (!inserir_c_caracteres(&lista, keys[k], nomes[i])) {
            printf("Valor \"%s\" nao foi inserido na lista\n", nomes[i]);
            keys[k] = -1;
        } else k++;

        keys[k] = rand() % 100;
        cval = 64 + (rand() % 62);
        if (!inserir_caractere(&lista, keys[k], cval)) {
            printf("Valor '%c' nao foi inserido na lista\n", cval);
            keys[k] = -1;
        } else k++;
    }
    listar_elementos(lista);

    printf("======= TESTANDO FUNCOES 'OBTER' =======\n\n");
    for (i = 0; i < k; i++) {
        switch (obter_tipo(lista, keys[i])) {
            case 'I':
                printf("\tValor do elemento de chave %d: %d\n", keys[i], obter_inteiro(lista, keys[i]));
                break;
            case 'F':
                printf("\tValor do elemento de chave %d: %f\n", keys[i], obter_p_flutuante(lista, keys[i]));
                break;
            case 'S':
                printf("\tValor do elemento de chave %d: \"%s\"\n", keys[i], obter_c_caracteres(lista, keys[i]));
                break;
            case 'C':
                printf("\tValor do elemento de chave %d: '%c'\n", keys[i], obter_caractere(lista, keys[i]));
                break;
            case ' ':
                printf("\tNao existe elemento com chave %d\n", keys[i]);
                break;
        }
    }

    apaga_lista(&lista);
    return 0;
}