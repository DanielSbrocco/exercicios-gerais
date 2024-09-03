#include <stdio.h>
#include "utils_char2.h"
#include <stdlib.h>

char *CriaVetorTamPadrao(){
    char* vetor = (char*)malloc(TAM_PADRAO*sizeof(char*));
    for(int i = 0; i < TAM_PADRAO; i++){
        vetor[i] = '_';
    }
    vetor[TAM_PADRAO] = '\0';
    return vetor;
}

char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){
    vetor = realloc(vetor, (tamanhoantigo+TAM_PADRAO)*sizeof(char*));
    for(int i = (tamanhoantigo); i < (tamanhoantigo+TAM_PADRAO); i++){
        vetor[i] = '_';
    }
    vetor[tamanhoantigo+TAM_PADRAO] = '\0';
    return vetor;
}

char* LeVetor(char *vetor, int *tamanho){
    for(int i = 0; i < *tamanho; i++){
        scanf("%c", &vetor[i]);
        if(vetor[i] == '\n'){
            vetor[i] = '_';
            break;
        }
        if(i == *tamanho-1){
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }
    } 
    return vetor;
}

void ImprimeString(char *vetor){
    int i = 0;
    while(vetor[i] != '\0' && vetor[i] != '\n'){
        printf("%c", vetor[i]);
        i++;
    }
}

void LiberaVetor(char *vetor){
    free(vetor);
}