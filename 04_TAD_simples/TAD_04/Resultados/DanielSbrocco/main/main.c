#include <stdio.h>
#include "aluno.h"

int main(){
    int numalunos;
    scanf("%d", &numalunos);
    tAluno aluno[numalunos];
    int cont[numalunos];
    for(int i = 0; i < numalunos; i++){
        aluno[i] = LeAluno();
        cont[i] = 0;
    }
    for(int i = 0; i < numalunos; i++){
        for(int j = 0; j < numalunos; j++){
            if(ComparaMatricula(aluno[i], aluno[j]) == 1){
                cont[i]++;
            }
        }
    }
    for(int i = 0; i < numalunos; i++){
        for(int j = 0; j < numalunos; j++){
            if(cont[j] == i){
                if(VerificaAprovacao(aluno[j]) == 1){
                    ImprimeAluno(aluno[j]);
                }
            }
        }
    }
    return 0;
}