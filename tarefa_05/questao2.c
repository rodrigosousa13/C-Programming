#include <stdio.h>

int MDC(int x, int y);

int main() {
    int x, y, mdcxy;

    printf("Digite dois inteiros positivos para calcular seu MDC (separados por espaco): ");
    scanf("%d %d", &x, &y);

    mdcxy = MDC(x, y);
    printf("MDC(%d, %d) = %d", x, y, mdcxy);

    return 0;
}

int MDC(int x, int y) {
    int r;

    r = x % y;
    if (r == 0) return y;
    else return MDC(y, r);
}
