#include <stdio.h>
#include "pessoa.h"

int main(){
    int numPessoa = 0;
    scanf("%d", &numPessoa);
    tPessoa pessoa[numPessoa];
    for(int i = 0; i < numPessoa; i++){
        pessoa[i] = CriaPessoa();
        LePessoa(&pessoa[i]);
    }
    AssociaFamiliasGruposPessoas(pessoa, numPessoa);
    for(int i = 0; i < numPessoa; i++){
        ImprimePessoa(&pessoa[i]);
    }
}