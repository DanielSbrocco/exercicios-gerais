#include <stdio.h>
#include <string.h>
#include "aluno.h"

tAluno* CriaAluno(){
    tAluno *aluno = (tAluno*)malloc(sizeof(tAluno));
    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;
    return aluno;
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno){
    char* temp = (char*)malloc(100*sizeof(char));
    scanf("%s\n", temp);
    aluno->nome = (char*)malloc((strlen(temp)+1)*sizeof(char));
    strcpy(aluno->nome, temp);
    scanf("%d\n", &aluno->matricula);
    scanf("%d %d %d\n", &aluno->n1, &aluno->n2, &aluno->n3);
    free(temp);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula > aluno2->matricula){
        return 1;
    } else if(aluno1->matricula < aluno2) {
        return -1;
    } else {
        return 0;
    }
}

int CalculaMediaAluno(tAluno* aluno){
    return ((aluno->n1+aluno->n2+aluno->n3)/3);
}

int VerificaAprovacao(tAluno* aluno){
    if(CalculaMediaAluno(aluno) >= 7){
        return 1;
    } else {
        return 0;
    }
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}