#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lde.h"

int main() {
    char *nomes[10] = {
        "Gabriela Santos", "Bruno Lima", "Isabela Martins", "Felipe Alves",
        "Ana Souza", "Joao Pereira", "Eduarda Costa", "Daniel Rocha",
        "Henrique Oliveira", "Carla Mendes"
    };
    void *agenda = inicializa_agenda();
    Aluno *aluno;
    int i, matr, tel;
    char tipo[10], email[] = "exemplo @email.com";
    FILE *input, *output;

    srand((int)time(NULL));
    for (i = 0; i < 10; i++) {
        matr = (rand() % 900000) + 100000; /* de 100.000 ate 999.999*/
        tel = 980000000 + (rand() % 10000000); /* de 9.8000.0000 ate 9.8999.9999*/
        i % 2 == 0 ? strcpy(tipo, "Celular") : strcpy(tipo, "Fixo");
        email[7] = 48 + i;
        aluno = cria_aluno(nomes[i], matr, 85, tel, tipo, email);
        if (i % 2 == 0) agd_inserir_inicio(&agenda, aluno);
        else agd_inserir_final(&agenda, aluno);
    }
    percorrer(agenda);

    /* testando ordenar */
    agd_ordenar(&agenda);
    printf("\nPercorrendo agenda apos ordenacao:\n");
    percorrer(agenda);

    /* testando remover */
    printf("Removendo Bruno Lima...\n");
    agd_remover(&agenda, "Bruno Lima");
    printf("Agenda apos a remocao:\n");
    percorrer(agenda);

    /* testando salvar */
    output = fopen("alunos.txt", "w");
    printf("Salvando agenda...\n");
    salvar(output, agenda);
    printf("Agenda salva com sucesso (alunos.txt)\n");
    fclose(output);

    /* testando carregar */
    printf("Apagando agenda para testar funcao carregar()...\n");
    apaga_agenda(&agenda);
    printf("Exibindo agenda:\n");
    percorrer(agenda);

    agenda = inicializa_agenda();
    input = fopen("alunos.txt", "r");
    printf("Carregando dados de alunos na agenda...\n");
    carregar(input, &agenda);
    printf("Exibindo agenda carregada:\n");
    percorrer(agenda);
    fclose(input);

    apaga_agenda(&agenda);
    return 0;
}