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
<<<<<<< HEAD
        if(vetor[i] == '\n'){
            vetor[i] = '_';
            break;
        }
=======
>>>>>>> refs/remotes/origin/main
    }
}

void ImprimeString(char *vetor, int tamanho){
<<<<<<< HEAD
    for(int i = 0; i < tamanho; i++){
        printf("%c", vetor[i]);
    }
    printf("\n");
=======
    printf("\n");
    for(int i = 0; i < tamanho; i++){
        printf("%c", vetor[i]);
    }
>>>>>>> refs/remotes/origin/main
}

void LiberaVetor(char *vetor){
    free(vetor);
}