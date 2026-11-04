#ifndef lista_poli_h
#define lista_poli_h

typedef struct _node {
    int key;
    void *val;
    char type;
    struct _node *prev;
    struct _node *next;
} Node;

typedef struct {
    Node *start;
} Lista; /* circular polimorfica */

void inicializar(Lista **L);
int inserir_inteiro(Lista **L, int key, int val);
int inserir_p_flutuante(Lista **L, int key, float val);
int inserir_c_caracteres(Lista **L, int key, char *val);
int inserir_caractere(Lista **L, int key, char val);
char obter_tipo(Lista *L, int key);
int obter_inteiro(Lista *L, int key);
float obter_p_flutuante(Lista *L, int key);
char *obter_c_caracteres(Lista *L, int key);
char obter_caractere(Lista *L, int key);
void listar_elementos(Lista *L);
void apaga_lista(Lista **L);

#endif