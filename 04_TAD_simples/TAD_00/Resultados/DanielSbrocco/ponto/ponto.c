#include <stdio.h>
#include <math.h>
#include "ponto.h"

Ponto pto_cria (float x, float y){
    Ponto p1;
    p1 = pto_atribui_x(p1, x);
    p1 = pto_atribui_y(p1, y);
    return p1;
}

float pto_acessa_x (Ponto p){
    return p.x;
}

float pto_acessa_y (Ponto p){
    return p.y;
}
Ponto pto_atribui_x (Ponto p, float x){
    p.x = x;
    return p;
}

Ponto pto_atribui_y (Ponto p, float y){
    p.y = y;
    return p;
}

float pto_distancia (Ponto p1, Ponto p2){
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}