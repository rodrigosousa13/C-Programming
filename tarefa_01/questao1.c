#include <stdio.h>

int main()
{
    int kwh_eco, kwh_norm;
    double total;
    
    printf("Digite a quantidade de Kwh consumida durante o período econômico: ");
    scanf("%d", &kwh_eco);
    
    printf("Digite a quantidade de Kwh consumida durante o período normal: ");
    scanf("%d", &kwh_norm);
    
    double fixo = 10;
    total = 0.1 * kwh_eco + 0.13 * kwh_norm + fixo;
    
    printf("Valor da conta: R$ %.2f\n", total);
    
    return 0;
}