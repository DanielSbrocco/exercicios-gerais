#include <stdio.h>
#include <stdlib.h>
#include "tDepartamento.h"

int main(){
    int numDepto, m1, m2, m3;
    tDepartamento depto[3];
    char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX], nome[STRING_MAX], diretor[STRING_MAX];
    scanf("%d", &numDepto);
    for(int i = 0; i < numDepto; i++){
        scanf("%s", nome);
        scanf("%s", diretor);
        scanf("%s", curso1);
        scanf("%s", curso2);
        scanf("%s", curso3);
        scanf("%d %d %d", &m1, &m2, &m3);
        if(m1 < 0 || m2 < 0 || m3 < 0){
            i--;
            printf("\nDigite um departamento com médias válidas");
        } else {
            depto[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
        }
    }

    OrdenaDepartamentosPorMedia(depto, numDepto);
    
    for(int i = 0; i < numDepto; i++){
        ImprimeAtributosDepartamento(depto[i]);
    }
}