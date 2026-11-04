#include <stdio.h>

int mdc (int x, int y);

int main() {
    int a, b, c, mdcabc;
    printf("Digite 3 numeros inteiro positivos (separados por espaco): ");
    scanf("%d %d %d", &a, &b, &c);
    
    mdcabc = mdc(mdc(a, b), c);
    printf("MDC(%d, %d, %d) = %d", a, b, c, mdcabc);
    
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
