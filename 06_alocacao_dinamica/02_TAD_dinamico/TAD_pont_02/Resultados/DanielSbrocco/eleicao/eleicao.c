#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"


tEleicao* InicializaEleicao(){
    int total = 0;
    tCandidato *candGen = CriaCandidato();
    tEleicao *eleicao = (tEleicao*)malloc(sizeof(tEleicao));
    scanf("%d", &total);
    eleicao->governadores = (tCandidato*)malloc(total*sizeof(tEleicao));
    eleicao->presidentes = (tCandidato*)malloc(total*sizeof(tEleicao));
    eleicao->eleitores = NULL;
    eleicao->totalEleitores = 0;
    eleicao->totalGovernadores = 0;
    eleicao->totalPresidentes = 0;
    eleicao->votosBrancosGovernador = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosGovernador = 0;
    eleicao->votosNulosPresidente = 0;
    for(int i = 0; i < total; i++){
        LeCandidato(candGen);
        if(candGen->cargo == 'P'){
            eleicao->presidentes[eleicao->totalPresidentes] = CriaCandidato();
            eleicao->presidentes[eleicao->totalPresidentes] = candGen;
            ImprimeCandidato(eleicao->presidentes[eleicao->totalPresidentes], 40.0);
            eleicao->totalPresidentes++;
        }
        if(candGen->cargo == 'G'){
            eleicao->governadores[eleicao->totalGovernadores] = CriaCandidato();
            eleicao->governadores[eleicao->totalGovernadores] = candGen;
            eleicao->totalGovernadores++;
        }
    }
    ApagaCandidato(candGen);
    return eleicao;
}

void ApagaEleicao(tEleicao* eleicao){
    for(int i = 0; i < eleicao->totalGovernadores; i++){
        ApagaCandidato(eleicao->governadores[i]);
    }
    for(int i = 0; i < eleicao->totalPresidentes; i++){
        ApagaCandidato(eleicao->presidentes[i]);

    }
    for(int i = 0; i < eleicao->totalEleitores; i++){
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->eleitores);
    free(eleicao->governadores);
    free(eleicao->presidentes);
    free(eleicao);
}

void RealizaEleicao(tEleicao* eleicao){
    scanf("%d", &eleicao->totalEleitores);
    eleicao->eleitores = (tEleitor*)malloc(eleicao->totalEleitores*sizeof(tEleitor));
    for(int i = 0; i < eleicao->totalEleitores; i++){
        eleicao->eleitores[i] = CriaEleitor();
        LeEleitor(eleicao->eleitores[i]);
    }
}

void ImprimeResultadoEleicao(tEleicao* eleicao){

}