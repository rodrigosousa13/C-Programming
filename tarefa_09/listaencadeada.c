#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"

int vem_antes(char *nome1, char *nome2) {
    /*
    Retorna 1 se nome1 vem antes de nome2 na ordem alfabetica
    senao, retorna 0 
    Se 2 nomes forem iguais, retorna 0 tambem 
    */
    int i = 0, acabou1 = 0, acabou2 = 0, c1, c2;
    while (!acabou1 && !acabou2) {
        c1 = nome1[i];
        if (c1 >= 'a' && c1 <= 'z')
            c1 = c1 - 32;
        c2 = nome2[i];
        if (c2 >= 'a' && c2 <= 'z')
            c2 = c2 - 32;
        if (c1 < c2) return 1;
        else if (c1 > c2) return 0;

        i++;
        if (nome1[i] == '\0') acabou1 = 1;
        if (nome2[i] == '\0') acabou2 = 1; 
    }

    return 0;
}

Aluno *cria_aluno(const char *nome, int matr, int DDD, int tel, char tipo) {
    Aluno *novo;
    novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL)
        return NULL;
    strcpy(novo->nome, nome);
    novo->matricula = matr;
    novo->DDD = DDD;
    novo->telefone = tel;
    novo->tipo = tipo;
    novo->prox = NULL;

    return novo;
}

void apaga_aluno(Aluno *head, int matr) {
    Aluno *atual = head, *anterior = NULL;

    if (head == NULL) return;

    while (atual->matricula != matr) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual->prox != NULL)
        anterior->prox = NULL;
    else
        anterior->prox = atual->prox;

    free(atual);
}

Aluno *inserir(Aluno *head, Aluno *novo) {
    Aluno *atual = head, *anterior = NULL;
    if (head == NULL)
        return novo;
    
    while ((atual != NULL)) {
        if (vem_antes(novo->nome, atual->nome)) {
            novo->prox = atual;
            if (anterior != NULL) {
                anterior->prox = novo;
                return head;
            } else return novo;
        }
        anterior = atual;
        atual = atual->prox;
    }
    anterior->prox = novo;

    return head;
}

void percorrer(Aluno *head) {
    Aluno *atual = head;
    char tipo[8];
    int i = 1;

    printf("========= LISTA TELEFONICA =========\n\n");
    while (atual != NULL) {
        printf("========= Aluno %d =========\n", i);
        printf("Nome: %s\n", atual->nome);
        printf("Matricula: %d\n", atual->matricula);
        if (atual->tipo == 'C') strcpy(tipo, "Celular");
        else strcpy(tipo, "Fixo");
        printf("Telefone (%s): (%d)%d\n\n", tipo, atual->DDD, atual->telefone);

        atual = atual->prox;
        i++;
    }
    printf("========= FIM DA LISTA =========\n");
}

void carregar(FILE *input, Aluno **head) {
    int i = 0;
    int matr, DDD, telefone;
    char nome[101], tipo;
    Aluno *novo;

    while (fscanf(input, " %100[^\n] %d %d %d %c",
                  nome, &matr, &DDD, &telefone, &tipo) == 5) {
        novo = cria_aluno(nome, matr, DDD, telefone, tipo);
        if (novo != NULL)
            *head = inserir(*head, novo);
    }
}

void salvar(FILE *output, Aluno *head) {
    Aluno *atual = head;

    while (atual != NULL) {
        fprintf(output, "%s\n%d\n%d\n%d\n%c\n", 
                atual->nome, atual->matricula, atual->DDD,
                atual->telefone, atual->tipo);

        atual = atual->prox;
    }
}

void apaga_lista(Aluno **head) {
    Aluno *atual = (*head)->prox, *proximo;

    free(*head);
    *head = NULL;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}
