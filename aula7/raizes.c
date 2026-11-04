#include <stdio.h>
#include <math.h>

int raizes(float a, float b, float c, float *x1, float *x2) {
    float delta;

    delta = b * b - 4 * a * c;

    if (delta < 0)
        return 0;
    else if (delta == 0) {
        *x1 = -b / (2 * a);
        return 1;
    }
    else {
        *x1 = (-b - sqrt(delta)) / (2 * a);
        *x2 = (-b + sqrt(delta)) / (2 * a);
        return 2;
    }
}

int main() {
    float a = 1, b = -5, c = 6, x1, x2;
    int rts;

    rts = raizes(a, b, c, &x1, &x2);

    if (rts == 0)
        printf("Nao existem raizes reais\n");
    else {
        printf("x1 = %.2f\n", x1);
        if (rts == 2)
            printf("x2 = %.2f\n", x2);
    }

    return 0;
}