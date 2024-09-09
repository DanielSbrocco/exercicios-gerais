#include <stdio.h>
#include "vector.h"
#include <stdlib.h>

typedef struct Vector{
    data_type *dado;
    int numAlocados;
}Vector;

Vector *VectorConstruct(){
    Vector *vec = (Vector*)calloc(1, sizeof(Vector));
    vec->dado = NULL;
    vec->numAlocados = 0;
    return vec;
}

void VectorPushBack(Vector *v, data_type val){
    v->dado = realloc(v->dado, (v->numAlocados+1)*sizeof(data_type));
    v->dado[v->numAlocados] = val;
    v->numAlocados++;
}

data_type VectorGet(Vector *v, int i){
    return v->dado[i];
}

int VectorSize(Vector *v){
    return v->numAlocados;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    for(int i = 0; i < v->numAlocados; i++){
        destroy(v->dado[i]);
    }
    free(v->dado);
    free(v);
}
