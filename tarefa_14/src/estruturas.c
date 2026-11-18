#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

#define NOT_FOUND -99999.99


LDE *inicializar_lista() {
    LDE *lista = malloc(sizeof(LDE));
    if (lista == NULL)
        return NULL;

    lista->head = NULL;
    lista->tail = NULL;

    return lista;
}
ABB *inicializar_arvore() {
    ABB *arvore = malloc(sizeof(ABB));
    if (arvore == NULL)
        return NULL;

    arvore->root = NULL;
    arvore->temp_rec = NULL;

    return arvore;
}

Node *_cria_node(int key, float val) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
        return NULL;

    node->key = key;
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int inserir_lista(LDE *L, int key, float val) {
    Node *new_node = _cria_node(key, val);
    if (new_node == NULL || L == NULL) {
        free(new_node);
        return 0;
    }

    if (L->head == NULL) {
        L->head = new_node;
    }
    if (L->tail != NULL) {
        L->tail->right = new_node;
        new_node->left = L->tail;
    } 
    L->tail = new_node;

    return 1;
}

int inserir_abb(ABB *A, int key, float val) {
    Node *new_node = _cria_node(key, val);
    Node *temp;

    if (new_node == NULL || A == NULL) {
        free(new_node);
        perror("inserir_abb");
        return 0;
    }

    if (A->root == NULL) {
        A->root = new_node;
        return 1;
    }

    temp = A->temp_rec;
    if (temp == NULL) {
        temp = A->root;
    }
    if (key < temp->key) {
        A->temp_rec = temp->left;
        if (temp->left == NULL) {
            temp->left = new_node;
            return 1;
        }
    } else if (key > temp->key) {
        A->temp_rec = temp->right;
        if (temp->right == NULL) {
            temp->right = new_node;
            return 1;
        }
    } else {
        A->temp_rec = NULL;
        free(new_node);
        return 0;
    }
    
    free(new_node);
    return inserir_abb(A, key, val);
}

float buscar_lista(LDE *L, int key) {
    Node *temp;
    if (L == NULL || L->head == NULL)
        return NOT_FOUND;
    
    temp = L->head;
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->val;
        }
        temp = temp->right;
    }

    return NOT_FOUND;
}

float buscar_abb(ABB *A, int key) {
    Node *temp;

    if (A == NULL || A->root == NULL) {
        return NOT_FOUND;
    }

    temp = A->root;
    while (temp != NULL && temp->key != key) {
        if (key < temp->key) {
            temp = temp->left;
        } else if (key > temp->key) {
            temp = temp->right;
        }
    }
    if (temp == NULL) {
        return NOT_FOUND;
    }
    return temp->val;
}

void percorrer_arvore(ABB *A, int array[], int start_idx) {
    Node *temp;
    if (A == NULL || A->root == NULL) {
        return;
    }

    temp = A->temp_rec;
    if (temp == NULL) {
        temp = A->root;
    }

    if (temp->left != NULL) {
        A->temp_rec = temp->left;
        percorrer_arvore(A, array, start_idx+1);
    }
    array[start_idx] = temp->key;

    A->temp_rec = temp;
    if (temp->right != NULL) {
        A->temp_rec = temp->right;
        percorrer_arvore(A, array, start_idx+1);
    }

    A->temp_rec = temp;
    return;
}
