#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"


tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    getchar();
    scanf("%99[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->pai != NULL || pessoa->mae != NULL){
        return 1;
    } else {
        return 0;
    }
}

void ImprimePessoa(tPessoa *pessoa){
    if(VerificaSeTemPaisPessoa(pessoa) == 1){
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        if(pessoa->pai == NULL){
            printf("PAI: NAO INFORMADO\n");
        } else {
            printf("PAI: %s\n", pessoa->pai->nome); 
        }

        if(pessoa->mae == NULL){
            printf("MAE: NAO INFORMADO\n");
        } else {
            printf("MAE: %s\n", pessoa->mae->nome);
        }
        
        printf("\n");
    }    
}


void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int numTotal = 0, numPai = 0, numMae = 0, numFilho = 0;
    scanf("%d\n", &numTotal);
    for(int i = 0; i < numTotal; i++){
        scanf("mae: %d, pai: %d, filho: %d\n", &numMae, &numPai, &numFilho);
        if(numMae != -1){
            pessoas[numFilho].mae = &pessoas[numMae];

        }
        if(numPai != -1){
            pessoas[numFilho].pai = &pessoas[numPai];
        }
    }
}