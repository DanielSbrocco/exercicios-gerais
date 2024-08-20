#include <stdio.h>
#include "utils.h"

int *CriaVetor(int tamanho){
    int* vetor = (int*)malloc(tamanho*sizeof(int));
    if(vetor == NULL){
        printf("Problema na Alocacao");
        exit(0);
    }
    return vetor;
}

void LeVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho){
    float media = 0;
    for(int i = 0; i < tamanho; i++){
        media += vetor[i];
    }
    media = (media/tamanho*1.0);
    return media;
}

void LiberaVetor(int *vetor){
    free(vetor);
}