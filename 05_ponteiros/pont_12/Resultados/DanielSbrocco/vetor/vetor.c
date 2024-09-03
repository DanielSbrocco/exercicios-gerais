#include <stdio.h>
#include "vetor.h"

void LeVetor(Vetor *vetor){
    scanf("%d", &vetor->tamanhoUtilizado);
    for(int i = 0; i < vetor->tamanhoUtilizado; i++){
        scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int result = vetor->elementos[0];
    for(int i = 1; i < vetor->tamanhoUtilizado; i++){
        result = op(result, vetor->elementos[i]);
    }
    return result;
}