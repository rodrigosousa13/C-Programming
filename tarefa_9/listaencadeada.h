#ifndef listaencadeada_h
#define listaencadeada_h

#include <stdio.h>

typedef struct _aluno {
    char nome[100];
    int matricula;
    int DDD;
    int telefone;
    char tipo;
    struct _aluno *prox;
} Aluno;

Aluno *inserir(Aluno *head, Aluno *a);
void percorrer(Aluno *head);
void carregar(FILE *input, Aluno **head);
void salvar(FILE *output, Aluno *head);

Aluno *cria_aluno(const char *nome, int matr, int DDD, int tel, char tipo);
void apaga_aluno(Aluno *head, int matr);
void apaga_lista(Aluno **head);


#endif