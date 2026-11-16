#ifndef abb_h
#define abb_h

typedef struct _node {
    int key;
    float val;
    struct _node *left;
    struct _node *right;
} Node;

typedef struct {
    Node *root;
    Node *temp_rec; /* armazena o estado usado nas funcoes recursivas */
} ArvoreBB;

void inicializar(ArvoreBB **arvore);
int inserir_iterativo(ArvoreBB **arvore, int key, float val);
int inserir_recursivo(ArvoreBB **arvore, int key, float val);
float buscar_iterativo(ArvoreBB *arvore, int key);
float buscar_recursivo(ArvoreBB **arvore, int key);
void listar_elementos(ArvoreBB **arvore, FILE *f);

#endif