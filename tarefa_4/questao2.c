#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float d_euclid(float x1, float x2, float y1, float y2, float z1, float z2);

int main() {
    float x1, x2, y1, y2, z1, z2, d;
    printf("Digite as coordenadas do primeiro ponto (separadas por espaco): ");
    scanf("%f %f %f", &x1, &y1, &z1);
    printf("Digite as coordenadas do segundo ponto (separadas por espaco): ");
    scanf("%f %f %f", &x2, &y2, &z2);

    d = d_euclid(x1, x2, y1, y2, z1, z2);
    printf("Distancia euclidiana: %.3f", d);

    return 0;
}

float d_euclid (float x1, float x2, float y1, float y2, float z1, float z2) {

    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}
