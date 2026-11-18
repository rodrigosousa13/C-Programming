#ifndef estruturas_h
#define estruturas_h

typedef struct _node {
	int key;
	float val;
	struct _node *left;
	struct _node *right;
} Node;

typedef struct {
	Node *head;
	Node *tail;
} LDE;

typedef struct {
	Node *root;
	Node *temp_rec;
} ABB;

LDE *inicializar_lista();
ABB *inicializar_arvore();
int inserir_lista(LDE *L, int key, float val);
int inserir_abb(ABB *A, int key, float val);
float buscar_lista(LDE *L, int key);
float buscar_abb(ABB *A, int key);
void percorrer_arvore(ABB *A, int array[], int start_idx);


#endif
