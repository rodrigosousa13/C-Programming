#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaencadeada.h"

int main() {
    const char *nomes[10] = {
        "Gabriela Santos", "Bruno Lima", "Isabela Martins", "Felipe Alves",
        "Ana Souza", "Joao Pereira", "Eduarda Costa", "Daniel Rocha",
        "Henrique Oliveira", "Carla Mendes"
    };
    Aluno *aluno, *head = NULL;
    int i, matr, tel;
    FILE *arq_alunos;

    srand((int)time(NULL));
    for (i = 0; i < 10; i++) {
        matr = (rand() % 900000) + 100000; /* de 100.000 ate 999.999*/
        tel = 980000000 + (rand() % 10000000); /* de 9.8000.0000 ate 9.8999.9999*/
        aluno = cria_aluno(nomes[i], matr, 85, tel, i % 2 == 0 ? 'C' : 'F');
        head = inserir(head, aluno);
    }

    printf("Lista inicial:\n");
    percorrer(head);

    arq_alunos = fopen("lista_alunos.txt", "w");
    if (arq_alunos == NULL) {
        printf("ERRO: Falha na abertura do arquivo\n");
        apaga_lista(&head);
        return 1;
    }
    salvar(arq_alunos, head);    
    printf("Arquivo salvo com sucesso.\n");

    fclose(arq_alunos);
    apaga_lista(&head);
    
    printf("Testando funcao carregar...\n\n");
    arq_alunos = fopen("lista_alunos.txt", "r");
    if (arq_alunos == NULL) {
        printf("ERRO: Falha na abertura do arquivo\n");
        apaga_lista(&head);
        return 1;
    }
    carregar(arq_alunos, &head);
    fclose(arq_alunos);

    printf("Imprimindo lista apos carregamento...\n");
    percorrer(head);

    apaga_lista(&head);

    return 0;
}