#include <stdio.h>
#include <stdlib.h>

int main() {
    int ano, ehBissexto;

    printf("Digite um ano: ");
    scanf("%d", &ano); 
    if (ano < 1752) ehBissexto = 0;
    else if (ano % 400 == 0) ehBissexto = 1;
    else if ( (ano % 4 == 0) && !(ano % 100 == 0) ) ehBissexto = 1;
    else ehBissexto = 0;
    
    if (ehBissexto) printf("Eh bissexto.");
    else printf("NAO eh bissexto.");

    return 0;
}
