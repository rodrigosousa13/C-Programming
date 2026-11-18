
#include <stdio.h>
#include <math.h>

int main()
{
    printf("%f\n", M_PI);

    double R, h;

    printf("Digite o raio da lata, em metros: ");
    scanf("%lf", &R);

    printf("Digite a altura da lata, em metros: ");
    scanf("%lf", &h);
    
    double area = 2 * M_PI * pow(R, 2) + 2 * M_PI * R * h;
    double custo = 100.0 * area;

    printf("Custo da lata: R$ %.2f\n", custo);
    
    return 0;
}
