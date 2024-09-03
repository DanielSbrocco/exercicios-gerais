#include <stdio.h>
#include "tDepartamento.h"
#include <string.h>

tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3,
                               char *nome, int m1, int m2, int m3, char *diretor)
{
    tDepartamento departamento;
    strcpy(departamento.curso1, curso1);
    strcpy(departamento.curso2, curso2);
    strcpy(departamento.curso3, curso3);
    strcpy(departamento.nome, nome);
    strcpy(departamento.diretor, diretor);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    return departamento;
}

void ImprimeAtributosDepartamento(tDepartamento depto){
    printf("\nDepartamento: %s\n", depto.nome);
    printf("\tDiretor: %s\n", depto.diretor);
    printf("\t1o curso: %s\n", depto.curso1);
    printf("\tMedia do 1o curso: %d\n", depto.m1);
    printf("\t2o curso: %s\n", depto.curso2);
    printf("\tMedia do 2o curso: %d\n", depto.m2);
    printf("\t3o curso: %s\n", depto.curso3);
    printf("\tMedia do 3o curso: %d\n", depto.m3);
    printf("\tMedia dos cursos: %.2f", ((depto.m1+depto.m2+depto.m3)/3.0));
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    float maior = -1;
    int posMenor = 0, temMaior = 0;
    tDepartamento troca;
    for(int i = 0; i < num_deptos; i++){
        maior = -1;
        posMenor = i;
        temMaior = 0;
        for(int j = 0; j < num_deptos; j++){
            if((((vetor_deptos[j].m1+vetor_deptos[j].m2+vetor_deptos[j].m3)/3.0) > maior) && (j >= i)){
                maior = ((vetor_deptos[j].m1+vetor_deptos[j].m2+vetor_deptos[j].m3)/3.0);
                posMenor = j;
                temMaior = 1;
            }
        }
        if(temMaior == 1){
            troca = CriaDepartamento(vetor_deptos[i].curso1, vetor_deptos[i].curso2, vetor_deptos[i].curso3, 
                                 vetor_deptos[i].nome, vetor_deptos[i].m1, vetor_deptos[i].m2, vetor_deptos[i].m3,
                                 vetor_deptos[i].diretor);
            vetor_deptos[i] = CriaDepartamento(vetor_deptos[posMenor].curso1, vetor_deptos[posMenor].curso2, vetor_deptos[posMenor].curso3, 
                                           vetor_deptos[posMenor].nome, vetor_deptos[posMenor].m1, vetor_deptos[posMenor].m2, vetor_deptos[posMenor].m3,
                                           vetor_deptos[posMenor].diretor);
            vetor_deptos[posMenor] = CriaDepartamento(troca.curso1, troca.curso2, troca.curso3, troca.nome, troca.m1, troca.m2, troca.m3, troca.diretor);
        }

    }
}