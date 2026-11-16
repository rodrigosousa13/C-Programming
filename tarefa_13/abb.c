#include <stdio.h>
#include <stdlib.h>
#include "abb.h"


Node *_criar_node(int key, float val) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        perror("Erro ao criar node");
        return NULL;
    }

    node->key = key;
    node->val = val;
    node->left = NULL; 
    node->right = NULL; 
    
    return node;
}

void _balanceia(ArvoreBB **A);

void inicializar(ArvoreBB **A) {
    (*A)->root = NULL;
    (*A)->temp_rec = NULL;
}

int inserir_iterativo(ArvoreBB **A, int key, float val) {
    Node *new_node = _criar_node(key, val);
    Node *temp, *pai;
    int esquerda, direita;

    if (new_node == NULL || A == NULL || *A == NULL) {
        free(new_node);
        perror("inserir_iterativo");
        return 0;
    }

    if ((*A)->root == NULL) {
        (*A)->root = new_node;
        return 1;
    }

    temp = (*A)->root;
    while (temp != NULL) {
        esquerda = 0;
        direita = 0;
        pai = temp;
        if (key < temp->key) {
            temp = temp->left;
            esquerda = 1;
        } else if (key > temp->key) {
            temp = temp->right;
            direita = 1;
        } else {
            printf("ERRO: chave %d ja existente na arvore\n", key);
            free(new_node);
            return 0;
        }
    }
    if (esquerda)
        pai->left = new_node;
    else if (direita)
        pai->right = new_node;

    return 1;
}

int inserir_recursivo(ArvoreBB **A, int key, float val) {
    Node *new_node = _criar_node(key, val);
    Node *temp;

    if (new_node == NULL || A == NULL || *A == NULL) {
        free(new_node);
        perror("inserir_recursivo");
        return 0;
    }

    if ((*A)->root == NULL) {
        (*A)->root = new_node;
        return 1;
    }

    temp = (*A)->temp_rec;
    if (temp == NULL) {
        temp = (*A)->root;
    }
    if (key < temp->key) {
        (*A)->temp_rec = temp->left;
        if (temp->left == NULL) {
            temp->left = new_node;
            /* _balanceia(A); */
            return 1;
        }
    } else if (key > temp->key) {
        (*A)->temp_rec = temp->right;
        if (temp->right == NULL) {
            temp->right = new_node;
            /* _balanceia(A); */
            return 1;
        }
    } else {
        printf("ERRO: chave %d ja existente na arvore\n", key);
        (*A)->temp_rec = NULL;
        free(new_node);
        return 0;
    }
    
    free(new_node);
    return inserir_recursivo(A, key, val);
}

float buscar_iterativo(ArvoreBB *A, int key) {
    Node *temp;

    if (A == NULL || A->root == NULL) {
        return -99999.99;
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
        return -99999.99;
    }
    return temp->val;
}
float buscar_recursivo(ArvoreBB **A, int key) {
    Node *temp;
    float rval;

    if (A == NULL || *A == NULL || (*A)->root == NULL) {
        return -99999.99;
    }
    temp = (*A)->temp_rec;
    if (temp == NULL) {
        temp = (*A)->root;
    }
    if (key < temp->key) {
        (*A)->temp_rec = temp->left;
        if (temp->left == NULL) {
            return -99999.99;
        }
        rval = buscar_recursivo(A, key);
    } else if (key > temp->key) {
        (*A)->temp_rec = temp->right;
        if (temp->right == NULL) {
            return -99999.99;
        }
        rval = buscar_recursivo(A, key);
    } else {
        (*A)->temp_rec = NULL;
        return temp->val;
    }

    return rval;
}
void listar_elementos(ArvoreBB **A, FILE *f) {
    Node *temp;
    if (A == NULL || *A == NULL || (*A)->root == NULL) {
        fputs(" ==== Arvore vazia ====\n", f);
        return;
    }

    temp = (*A)->temp_rec;
    if (temp == NULL) {
        temp = (*A)->root;
    }

    if (temp->left != NULL) {
        (*A)->temp_rec = temp->left;
        listar_elementos(A, f);
    }
    fprintf(f, "(Chave %d: %f)\n", temp->key, temp->val);

    (*A)->temp_rec = temp;
    if (temp->right != NULL) {
        (*A)->temp_rec = temp->right;
        listar_elementos(A, f);
    }

    (*A)->temp_rec = temp;
    return;
}
