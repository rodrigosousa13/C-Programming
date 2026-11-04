#include <stdio.h>

int main (int narg, char *argv[]) {
    int meses;
    float val_old, val_new, taxa;
    printf("Digite o valor original da prestacao, em reais: ");
    scanf("%f", &val_old);
    printf("Digite o tempo de atraso (em meses): ");
    scanf("%d", &meses);
    printf("Digite a taxa mensal de juros (em porcentagem): ");
    scanf("%f", &taxa);

    val_new = val_old + val_old * (taxa/100) * meses;
    printf("Valor atualizado da prestacao: R$%.2f", val_new);

    return 0;
}