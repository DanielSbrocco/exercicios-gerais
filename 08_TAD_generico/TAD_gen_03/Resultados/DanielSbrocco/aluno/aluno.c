#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define TAM_NOME 51

typedef struct Aluno{
    char *nome;
    float nota;
    char genero;
}tAluno;

tAluno *CriaAluno(){
    tAluno* aluno = (tAluno*)calloc(1, sizeof(tAluno));
    aluno->nome = (char*)malloc(TAM_NOME*sizeof(char));
    
    return aluno;
}

void DestroiAluno(data_type aluno){
    tAluno *temp = (tAluno*)aluno;

    free(temp->nome);
    free(temp);
}

void LeAluno(tAluno *aluno){
    scanf("%[^;]", aluno->nome);
    getchar();
    scanf("%c", &aluno->genero);
    getchar();
    scanf("%f", &aluno->nota);
    getchar();
}

char GetGeneroAluno(tAluno *aluno){
    return aluno->genero;
}

float GetNotaAluno(tAluno *aluno){
    return aluno->nota;
}