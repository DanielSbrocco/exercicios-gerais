#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

int main(){
    float x1, x2, y1, y2;
    float dist;
    Ponto ponto1, ponto2;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    ponto1 = pto_cria(x1, y1);
    ponto2 = pto_cria(x2, y2);
    printf("%g", pto_distancia(ponto1, ponto2));
    return 0;
}