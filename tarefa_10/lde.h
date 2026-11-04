#ifndef listaduplamenteencadeada_h
#define listaduplamenteencadeada_h

#include <stdio.h>

typedef struct _aluno {
    char *nome;
    int matricula;
    int DDD;
    int telefone;
    char *tipo;
    char *email;
    struct _aluno *dir;
    struct _aluno *esq;
} Aluno;

void agd_remover(void **mem, char *nome);
void agd_inserir_inicio(void **mem, Aluno *novo);
void agd_inserir_final(void **mem, Aluno *novo);
void agd_ordenar(void **mem);

Aluno *cria_aluno(char *nome, int matr, int DDD, int tel, char *tipo, char *email);   
void *inicializa_agenda();
void percorrer(void *mem);
void carregar(FILE *input, void **mem);
void salvar(FILE *output, void *mem);
void apaga_agenda(void **mem);
int vem_antes(char *nome1, char *nome2);
void troca(Aluno *a, Aluno *b);

#endif