#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_polimorfica.h"

Node *_constroi_node(int key, char type, void *val) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->key = key;
    node->val = val;
    node->type = type;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void _apaga_node(Node *node) {
    free(node->val);
    if (node->next != NULL)
        node->next->prev = NULL;
    if (node->prev != NULL)
        node->prev->next = NULL;
    free(node);
}

void _insere_antes(Node *node, Node *novo) {
    novo->prev = node->prev;
    novo->next = node;
    node->prev->next = novo;
    node->prev = novo; 
}

int _inserir(Lista **L, Node *novo) {
    Node *atual;
    int first_key, key = novo->key;

    if (L == NULL || *L == NULL) {
        printf("ERRO AO INSERIR: Lista nao inicializada ou endereco de memoria invalido\n");
        return 0;
    }
    atual = (*L)->start;
    if (atual == NULL) {
        (*L)->start = novo;
        novo->prev = novo;
        novo->next = novo;
        return 1;
    } else {
        first_key = atual->key;
        if (key < first_key) {
            _insere_antes(atual, novo);
            (*L)->start = novo;
            return 1;
        }
        atual = atual->next;

        while (atual->key != first_key) {
            if (key < atual->key) {
                _insere_antes(atual, novo);
                return 1;
            } else if (key > atual->key) {
                atual = atual->next;
            } else {
                printf("ERRO: Chave %d ja existente\n", key);
                return 0;
            }
        }
        _insere_antes(atual, novo);
        return 1;
    }
}

void inicializar(Lista **L) {
    (*L)->start = NULL;
}

int inserir_inteiro(Lista **L, int key, int val) {
    Node *novo;
    int *value = malloc(sizeof(int));
    if (value == NULL)
        return 0;
    *value = val;
    novo = _constroi_node(key, 'I', (void*) value);
    if (!_inserir(L, novo)) {
        return 0;
    }

    return 1;
}

int inserir_p_flutuante(Lista **L, int key, float val) {
    Node *novo;
    float *value = malloc(sizeof(float));
    if (value == NULL) 
        return 0;
    *value = val;
    novo = _constroi_node(key, 'F', (void*) value);
    if (!_inserir(L, novo)) {
        return 0;
    }

    return 1;
}

int inserir_c_caracteres(Lista **L, int key, char *val) {
    Node *novo;
    char *value = malloc(strlen(val) + 1);
    if (value == NULL) 
        return 0;
    strcpy(value, val);
    novo = _constroi_node(key, 'S', (void*) value);
    if (!_inserir(L, novo)) {
        return 0;
    }

    return 1;
}

int inserir_caractere(Lista **L, int key, char val) {
    Node *novo;
    char *value = malloc(sizeof(char));
    if (value == NULL) 
        return 0;
    *value = val;
    novo = _constroi_node(key, 'C', (void*) value);
    if (!_inserir(L, novo)) {
        return 0;
    }

    return 1;
}

char obter_tipo(Lista *L, int key) {
    /*
     Retorna:
        - 'I', tipo int
        - 'F', tipo float
        - 'S', tipo string
        - 'C', tipo char
        - ' ', erro/chave inexistente
    */
    Node *atual = L->start;

    if (atual == NULL) {
        printf("Endereco de memoria invalido.\n");
        return ' ';
    }

    do {
        if (atual->key == key)
            return atual->type;
        atual = atual->next;
    } while (atual != L->start);

    return ' ';
}

int obter_inteiro(Lista *L, int key) {
    Node *atual;

    if (L == NULL) {
        printf("ERRO AO OBTER VALOR: Lista nao inicializada ou endereco de memoria invalido\n");
        return -99999;
    }
    atual = L->start;
    if (atual == NULL) {
        printf("ERRO AO OBTER VALOR: Lista vazia");
        return -99999;
    }

    do {
        if (atual->key == key)
            return *((int*)atual->val);
        atual = atual->next;
    } while (atual != L->start);

    printf("ERRO AO OBTER VALOR: Chave %d inexistente", key);
    return -99999;
}

float obter_p_flutuante(Lista *L, int key) {
    Node *atual;

    if (L == NULL) {
        printf("ERRO AO OBTER VALOR: Lista nao inicializada ou endereco de memoria invalido\n");
        return -99999.0;
    }
    atual = L->start;
    if (atual == NULL) {
        printf("ERRO AO OBTER VALOR: Lista vazia");
        return -99999.0;
    }

    do {
        if (atual->key == key)
            return *((float*)atual->val);
        atual = atual->next;
    } while (atual != L->start);

    printf("ERRO AO OBTER VALOR: Chave %d inexistente", key);
    return -99999.0;
}

char *obter_c_caracteres(Lista *L, int key) {
    Node *atual;

    if (L == NULL) {
        printf("ERRO AO OBTER VALOR: Lista nao inicializada ou endereco de memoria invalido\n");
        return NULL;
    }
    atual = L->start;
    if (atual == NULL) {
        printf("ERRO AO OBTER VALOR: Lista vazia");
        return NULL;
    }

    do {
        if (atual->key == key)
            return ((char*)atual->val);
        atual = atual->next;
    } while (atual != L->start);

    printf("ERRO AO OBTER VALOR: Chave %d inexistente", key);
    return NULL;
}

char obter_caractere(Lista *L, int key) {
    Node *atual;

    if (L == NULL) {
        printf("ERRO AO OBTER VALOR: Lista nao inicializada ou endereco de memoria invalido\n");
        return '\0';
    }
    atual = L->start;
    if (atual == NULL) {
        printf("ERRO AO OBTER VALOR: Lista vazia");
        return '\0';
    }

    do {
        if (atual->key == key)
            return *((char*)atual->val);
        atual = atual->next;
    } while (atual != L->start);

    printf("ERRO AO OBTER VALOR: Chave %d inexistente", key);
    return '\0';
}

void listar_elementos(Lista *L) {
    Node *atual = L->start;
    int i = 1;

    printf("======== EXIBINDO LISTA ========\n\n");
    do {
        printf("%d.o elemento:\n", i);
        printf("Chave: %d\n", atual->key);
        printf("Valor: ");
        switch (atual->type) {
            case 'I':
                printf("%d", *((int*)atual->val));
                break;
            case 'F':
                printf("%f", *((float*)atual->val));
                break;
            case 'S':
                printf("%s", ((char*)atual->val));
                break;
            case 'C':
                printf("%c", *((char*)atual->val));
                break;
        }
        printf("\n\n");
        atual = atual->next;
        i++;
    } while (atual != L->start);
    printf("========= FIM DA LISTA =========\n\n");
}

void apaga_lista(Lista **L) {
    Node *atual, *next;
    if (L == NULL || *L == NULL) 
        return;
    
    atual = (*L)->start;
    while (atual != NULL) {
        next = atual->next;
        _apaga_node(atual);
        atual = next;
    }

    free(*L);
    *L = NULL;
}