#include <stdio.h>
#include <stdlib.h>

int mdc (int x, int y);

int main() {
    int x, y, mdcxy;

    do {
        printf("Digite 2 numeros inteiros positivos para calcular seu MDC (separados por espaco): ");
        scanf("%d %d", &x, &y);
    } while (x <=0 | y <= 0);

    mdcxy = mdc(x, y);
    printf("MDC(%d, %d) = %d", x, y, mdcxy);

    return 0;
}

int mdc (int x, int y) {
    int r, temp;
    if (x < y) { 
        temp = x;
        x = y;
        y = temp;
    }

    r = x % y;
    while (r > 0) {
        x = y;
        y = r;
        r = x % y;        
    }
    return y;
}
