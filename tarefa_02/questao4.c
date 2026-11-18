#include <stdio.h>
#include <stdlib.h>

int main() {
    int dia, mes, ano, dia_n, mes_n, ano_n, idade;

    printf("Digite o dia, mes e ano atual, separado por espacos: ");
    scanf("%d %d %d", &dia, &mes, &ano);
    
    printf("Digite o dia, mes e ano de nascimento, separado por espacos: ");
    scanf("%d %d %d", &dia_n, &mes_n, &ano_n);

    idade = ano - ano_n - 1;
    if ((dia >= dia_n) && (mes == mes_n) || (mes > mes_n)) idade++;

    if (idade >= 16) printf("Pode votar!");
    else printf("Nao pode votar!");

    return 0;

}
