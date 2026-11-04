#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lde.h"


void *inicializa_agenda() {
    return NULL;
}

int vem_antes(char *nome1, char *nome2) {
    /*
    Retorna 1 se nome1 vem antes de nome2 na ordem alfabetica
    senao, retorna 0
    Se 2 nomes forem iguais, retorna 1
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

    return acabou1;
}

int igual(char *nome1, char *nome2) {
    /* Retorna 1 se os dois nomes sao iguais, 0 caso contrario */
    int i = 0;

    while (nome1[i] != '\0' && nome2[i] != '\0') {
        if (nome1[i] != nome2[i]) return 0;
        i++;
    }
    if (nome1[i] != nome2[i]) return 0;
    return 1;
}

void troca(Aluno *a, Aluno *b) {
    Aluno *a_esq = a->esq;
    Aluno *b_dir = b->dir;

    a->esq = b;
    a->dir = b_dir;
    b->dir = a;
    b->esq = a_esq;

    if (a_esq != NULL) a_esq->dir = b;
    if (b_dir != NULL) b_dir->esq = a;
}

Aluno *cria_aluno(char *nome, int matr, int DDD, int tel, char *tipo, char *email) {
    Aluno *novo;
    novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL)
        return NULL;
    novo->nome = (char*) malloc(strlen(nome) + 1);   /*lembrar de dar free*/ 
    strcpy(novo->nome, nome);
    novo->matricula = matr;
    novo->DDD = DDD;
    novo->telefone = tel;
    novo->tipo = (char*) malloc(strlen(tipo) + 1);   /*lembrar de dar free*/
    strcpy(novo->tipo, tipo);
    novo->email = (char*) malloc(strlen(email) + 1); /*lembrar de dar free*/
    strcpy(novo->email, email);
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

void apaga_aluno(Aluno *aluno) {
    free(aluno->nome);
    free(aluno->tipo);
    free(aluno->email);
    free(aluno);
}   

void apaga_agenda(void **mem) {
    Aluno *atual = *mem;
    Aluno *prox;

    while (atual != NULL) {
        prox = atual->dir;
        apaga_aluno(atual);
        atual = prox;
    }
    *mem = NULL;
}

void agd_remover(void **mem, char *nome) {
    Aluno *atual = *mem, *prox = NULL;
    void *new_head = *mem;

    if (*mem == NULL)
        return;

    while (atual != NULL) {
        prox = atual->dir;
        if (igual(nome, atual->nome)) {
            /* ajustando os ponteiros */
            if (atual->esq != NULL)
                atual->esq->dir = atual->dir;
            else new_head = (void*) atual->dir;
            if (atual->dir != NULL)
                atual->dir->esq = atual->esq;
        
            /* liberando memoria */
            apaga_aluno(atual);
        } 
        atual = prox;
    }

    *mem = new_head;
}

void agd_inserir_inicio(void **mem, Aluno *novo) {
    void *new_head = *mem;

    new_head = (void*) novo;
    novo->dir = (Aluno*) *mem;
    novo->esq = NULL;
    if (novo->dir != NULL) novo->dir->esq = novo;

    *mem = new_head;
}

void agd_inserir_final(void **mem, Aluno *novo) {
    Aluno *atual = *mem;

    if (*mem == NULL) {
        *mem = (void*) novo;
    } else {
        while (atual->dir != NULL) 
            atual = atual->dir;
        
        atual->dir = novo;
        novo->esq = atual;
    }
}

void agd_ordenar(void **mem) {
    /* bubble sort */
    Aluno *atual = *mem;
    void *new_head = *mem;
    int n = 0, i, j, trocou = 0;

    if (*mem == NULL) return;

    while (atual != NULL) {
        n++;
        atual = atual->dir;
    }
    atual = *mem;

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (vem_antes(atual->dir->nome, atual->nome)) {
                if (j == i + 1) {
                    new_head = (void*) atual->dir;
                }
                troca(atual, atual->dir);
                trocou = 1;
            }
            if (!trocou)
                atual = atual->dir;
            trocou = 0;
        }
        atual = (Aluno*) new_head;
    }

    *mem = new_head;
}

void percorrer(void *mem) {
    Aluno *atual = mem;
    int i = 1;

    printf("========= AGENDA DE ALUNOS =========\n\n");
    while (atual != NULL) {
        printf("========= Aluno %d =========\n", i);
        printf("Nome: %s\n", atual->nome);
        printf("Matricula: %d\n", atual->matricula);
        printf("Telefone (%s): (%d)%d\n", atual->tipo, atual->DDD, atual->telefone);
        printf("Email: %s\n\n", atual->email);
        atual = atual->dir;
        i++;
    }
    printf("========= FIM DA LISTA =========\n");
}

void carregar(FILE *input, void **mem) {
    int i = 0;
    int matr, DDD, telefone;
    char nome[101], tipo[11], email[101];
    Aluno *novo;

    while (fscanf(input, " %100[^\n] %d %d %d %10s %100s",
                  nome, &matr, &DDD, &telefone, tipo, email) == 6) {
        novo = cria_aluno(nome, matr, DDD, telefone, tipo, email);
        if (novo != NULL)
            agd_inserir_inicio(mem, novo);
    }
}

void salvar(FILE *output, void *mem) {
    Aluno *atual = mem;

    while (atual != NULL) {
        fprintf(output, "%s\n%d\n%d\n%d\n%s\n%s\n", 
                atual->nome, atual->matricula, atual->DDD,
                atual->telefone, atual->tipo, atual->email);

        atual = atual->dir;
    }
}