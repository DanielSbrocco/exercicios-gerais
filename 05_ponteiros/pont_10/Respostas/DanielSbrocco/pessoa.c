#include <stdio.h>
#include "pessoa.h"

tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.irmao = NULL;
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

        if(pessoa->irmao == NULL){
            printf("IRMAO: NAO INFORMADO\n");     
        } else {
            printf("IRMAO: %s\n", pessoa->irmao->nome);
        }
        
        printf("\n");
    }
    
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if((pessoa1->mae == pessoa2->mae) && (pessoa1->pai == pessoa2->pai)){
        return 1;
    } else {
        return 0;
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
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
    
    for(int i = 0; i < numPessoas; i++){
        for(int j = 0; j < numPessoas; j++){
            if(VerificaSeTemPaisPessoa(&pessoas[i]) == 1 && VerificaSeTemPaisPessoa(&pessoas[j]) == 1){
                if((VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]) == 1) && (i != j)){
                    pessoas[i].irmao = &pessoas[j];
                }
            }
        }
    }
}