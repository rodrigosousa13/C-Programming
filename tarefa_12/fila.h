#ifndef fila_h
#define fila_h

typedef struct _node {
    char nome[250];
    int conta;
    float valor;
    struct _node *prox;
} Node;

typedef struct {
    Node *primeiro;
    Node *ultimo;
    int tamanho;
} Fila;

void inicializar(Fila **f);
int enfileirar(Fila *f, char nome[250], int conta, float valor);
float fila_consultar_valor_proximo(Fila *f);
int fila_consulta_conta_proximo(Fila *f);
int fila_vazia(Fila *f);
char *fila_desenfileirar(Fila *f);
int fila_tamanho(Fila *f);

#endif