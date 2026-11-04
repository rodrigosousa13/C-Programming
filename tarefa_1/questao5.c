#include <stdio.h>

int main (int narg, char *argv[]) {
    char nome[50];
    int horas, filhos;
    float valor_por_hora, salario, gratificacao;

    printf("Digite seu nome: ");
    scanf("%s", &nome);
    printf("Digite a quantidade de horas trabalhadas: ");
    scanf("%d", &horas);
    printf("Digite o valor ganho por hora trabalhada: ");
    scanf("%f", &valor_por_hora);
    printf("Digite quantos filhos voce tem: ");
    scanf("%d", &filhos);

    salario = horas * valor_por_hora;

    if (filhos > 3) {
        gratificacao = 0.03 * filhos * salario;
        salario += gratificacao;
    } else {
        gratificacao = 0;
    }

    printf("\n========== %s ==========\n", nome);
    printf("Salario: R$%.2f\n", salario);
    if (gratificacao > 0) {
        printf("Gratificacao por numero de filhos (inclusa no salario): R$%.2f", gratificacao);
    }

    return 0;
}