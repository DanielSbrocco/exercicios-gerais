#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

char *CriaVetor(int tamanho){
    char*vetor = (char*)malloc(tamanho*sizeof(char*));
    for(int i = 0; i < tamanho; i++){
        vetor[i] = '_';
    }
    return vetor;
}

void LeVetor(char *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        scanf("%c", &vetor[i]);
    }
}

void ImprimeString(char *vetor, int tamanho){
    printf("\n");
    for(int i = 0; i < tamanho; i++){
        printf("%c", vetor[i]);
    }
}

void LiberaVetor(char *vetor){
    free(vetor);
}