#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadgen.h"

typedef struct generic{
    void* vetGen;
    Type tipo;
    int numElem;
}tGeneric;

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric* gen = (tGeneric*)calloc(1, sizeof(tGeneric));
    gen->numElem = numElem;
    gen->tipo = type;

    if(type == FLOAT){
        gen->vetGen = (float*)calloc(numElem, sizeof(float));
    }

    if(type == INT){
        gen->vetGen = (int*)calloc(numElem, sizeof(int));
    }

    return gen;
}

void DestroiGenerico(tGeneric* gen){
    free(gen->vetGen);
    free(gen);
}

void LeGenerico(tGeneric* gen){

    printf("\nDigite o vetor:\n");
    if(gen->tipo == FLOAT){
        for(int i = 0; i < gen->numElem; i++){
            scanf("%f", (float*)gen->vetGen+i);
//          SERA QUE DA ERRADO?
        }
    }

    if(gen->tipo == INT){
        for(int i = 0; i < gen->numElem; i++){
            scanf("%d", (int*)gen->vetGen+i);
//          SERA QUE DA ERRADO?
        }
    }
}

void ImprimeGenerico(tGeneric* gen){

    if(gen->tipo == FLOAT){
        for(int i = 0; i < gen->numElem; i++){
            printf("%.2f ", ((float*)gen->vetGen)[i]);
//          SERA QUE DA ERRADO?
        }
    }

    if(gen->tipo == INT){
        for(int i = 0; i < gen->numElem; i++){
            printf("%d ", ((int*)gen->vetGen)[i]);
//          SERA QUE DA ERRADO?
        }
    }
}