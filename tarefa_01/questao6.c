#include <stdio.h>

int main (int narg, char *argv[]) {
    float valor_compra_dolar, taxa_dolar, icms, percentual_lucro;
    float valor_compra_real;

    printf("Digite o valor da compra, em dolares: ");
    scanf("%f", &valor_compra_dolar);
    printf("Digite o valor da taxa atual do dolar, em reais: ");
    scanf("%f", &taxa_dolar);
    printf("Digite o valor atual do ICMS, em pontos percentuais: ");
    scanf("%f", &icms);
    printf("Digite o percentual de lucro da sua empresa, em pontos percentuais: ");
    scanf("%f", &percentual_lucro);

    valor_compra_real = valor_compra_dolar * taxa_dolar;
    valor_compra_real = valor_compra_real*(1+icms/100)*(1+percentual_lucro/100);

    printf("Valor da compra em reais: R$%.2f", valor_compra_real);

    return 0;
}