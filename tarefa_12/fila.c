#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializar(Fila **f) {
    (*f)->primeiro = NULL;
    (*f)->ultimo = NULL;
    (*f)->tamanho = 0;
}

Node *_criar_node(char nome[250], int conta, float valor) {
    Node *no = malloc(sizeof(Node));

    strcpy(no->nome, nome);
    no->conta = conta;
    no->valor = valor;

    return no;
}

int enfileirar(Fila *f, char nome[250], int conta, float valor) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return 0;

    if (valor <= 0) return 0;

    strcpy(new_node->nome, nome);
    new_node->conta = conta;
    new_node->valor = valor;
    new_node->prox = NULL;

    if (f->ultimo == NULL) {
        f->primeiro = new_node;
        f->ultimo = new_node;
    } else {
        f->ultimo->prox = new_node;
        f->ultimo = new_node;
    }

    f->tamanho++;
    return 1;
}

float fila_consultar_valor_proximo(Fila *f) {
    if (f != NULL && f->primeiro != NULL) {
        return f->primeiro->valor;
    }
    return -1.0;
}

int fila_consulta_conta_proximo(Fila *f) {
    if (f != NULL && f->primeiro != NULL) {
        return f->primeiro->conta;
    }
    return -1;
}

int fila_vazia(Fila *f) {
    if (f == NULL) {
        printf("AVISO: Fila nao inicializada\n");
        return 0;
    }
    return f->tamanho == 0;
}

char *fila_desenfileirar(Fila *f) {
    Node *removido;
    size_t tamanho;    
    char *nome;

    if (fila_vazia(f)) {
        printf("AVISO: Fila vazia\n");
        return nome;
    }
    removido = f->primeiro;
    tamanho = strlen(removido->nome);
    nome = malloc(tamanho);

    strcpy(nome, removido->nome);
    f->primeiro = removido->prox;
    if (f->primeiro == NULL) {
        f->ultimo = NULL;
    }
    f->tamanho--;

    free(removido);
    return nome;
}

int fila_tamanho(Fila *f) {
    if (f == NULL) {
        printf("AVISO: fila nao inicializada\n");
        return 0;
    }
    return f->tamanho;
}
