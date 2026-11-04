#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define N 10000
#define K 100
/*
   Com esses parametros, o algoritmo mais rapido (comb sort) leva cerca de 
   0.13s na minha maquina. Nao deixei 4s como o pedido pois o algoritmo
   mais lento (bubble sort) levaria cerca de 20 mins para concluir a execucao. 
   
   Output esperado:
   
   Parametros do experimento:
    N = 10000
    K = 100

    Bubble Sort:
    Tempo de execucao: 18.183619 segundos
    Insertion Sort:
    Tempo de execucao: 4.803666 segundos
    Selection Sort:
    Tempo de execucao: 9.366083 segundos
    Comb Sort:
    Tempo de execucao: 0.131144 segundos 
*/

void bubble_sort(int A[], int n);
void insertion_sort(int A[], int n);
void selection_sort(int A[], int n);
void comb_sort(int A[], int n);
void troca(int * a, int * b);
void gera_vetores(int vetores[][N]);
void analisa(void (*sort)(int *, int), int vetores[][N]);
void print_vetor(int vetor[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}


int main() {
    int i, rand;
    static int vetores[K][N];

    srand((int)time(NULL));

    printf("Parametros do experimento:\n");
    printf("N = %d\n", N);
    printf("K = %d\n\n", K);

    printf("Bubble Sort:\n");
    analisa(bubble_sort, vetores);
    printf("Insertion Sort:\n");
    analisa(insertion_sort, vetores);
    printf("Selection Sort:\n");
    analisa(selection_sort, vetores);
    printf("Comb Sort:\n");
    analisa(comb_sort, vetores);

    return 0;

}

void analisa(void (*sort)(int *, int), int vetores[][N]) {
    struct timeval inicio, fim;
    double t = 1.0;
    int i;

    gera_vetores(vetores);
    gettimeofday(&inicio, NULL);
    for (i = 0; i < K; i++) {
        sort(vetores[i], N);
    }
    gettimeofday(&fim, NULL);

    /* print_vetor(vetores[0], 100); */

    t = (double) (fim.tv_usec - inicio.tv_usec) / 1000000 + (double) (fim.tv_sec - inicio.tv_sec);

    printf("Tempo de execucao: %lf segundos\n", t);

}   


void gera_vetores(int vetores[][N]) {
    int i, j;

    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            vetores[i][j] = rand() % (100 * N); 
        }
    }

    /* print_vetor(vetores[0], 100);*/
}

void troca(int * a, int * b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void bubble_sort(int A[], int n) {
    int i, j;

    for (j = n-1; j > 0; j--) 
        for (i = 0; i < j; i++) 
            if (A[i] > A[i+1])
                troca(&A[i], &A[i+1]);
}

void insertion_sort(int A[], int n) {
    int i, j, atual;

    for (i = 1; i < n; i++) {
        atual = A[i];
        j = i-1;
        while ((j >= 0) && (atual < A[j])) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = atual;
    }
}

void selection_sort(int A[], int n) {
    int i, j, menor;
    
    for (i = 0; i < n; i++) {
        menor = i;
        for (j = i+1; j < n; j++)
            if (A[j] < A[menor])
                menor = j;
        troca(&A[i], &A[menor]);
    }
}

void comb_sort(int A[], int n) {
	int i, j, intervalo, trocado = 1;
	intervalo = n;
	while (intervalo > 1 || trocado == 1)
	{
		intervalo = intervalo * 10 / 13;
		if (intervalo == 9 || intervalo == 10) intervalo = 11;
		if (intervalo < 1) intervalo = 1;
		trocado = 0;
		for (i = 0, j = intervalo; j < n; i++, j++)
		{
			if (A[i] > A[j])
                troca(&A[i], &A[j]);
		}
	}
}
