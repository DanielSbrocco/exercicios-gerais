#include <stdio.h>
#include "aluno.h"

int main(){
    int numAluno;
    scanf("%d", &numAluno);
    tAluno**aluno;
    for(int i = 0; i < numAluno; i++){
        aluno[i] = CriaAluno();
        LeAluno(aluno[i]);
    }
    for(int i = 0; i < numAluno; i++){
        
    }
}