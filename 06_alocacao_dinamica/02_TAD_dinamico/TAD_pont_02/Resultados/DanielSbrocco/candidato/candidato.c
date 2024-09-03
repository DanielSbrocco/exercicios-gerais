#include <stdio.h>
#include <stdlib.h>
#include "candidato.h"

tCandidato* CriaCandidato(){
    tCandidato *cand = malloc(sizeof(tCandidato));
    cand->nome = malloc(100*sizeof(char));
    cand->partido = malloc(100*sizeof(char));
    cand->id = -1;
    cand->votos = -1;
    return cand;
}

void ApagaCandidato(tCandidato* candidato){
    free(candidato->nome);
    free(candidato->partido);
    free(candidato);
}

void LeCandidato(tCandidato *candidato){
    scanf("\n%[^,], %[^,], %c, %d", candidato->nome, candidato->partido, &candidato->cargo, &candidato->id);
    candidato->votos = 0;
}

int VerificaIdCandidato(tCandidato *candidato, int id){
    if(id == candidato->id){
        return 1;
    }
    return 0;
}

int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2){
    if(candidato1->id == candidato2->id){
        return 1;
    } 
    return 0;
}

char ObtemCargo(tCandidato* candidato){
    return candidato->cargo;
}

void IncrementaVotoCandidato(tCandidato* candidato){
    candidato->votos++;
}

int ObtemVotos(tCandidato* candidato){
    return candidato->votos;
}

float CalculaPercentualVotos(tCandidato* candidato, int totalVotos){
    float percent;
    percent = (((float)candidato->votos/(float)totalVotos)*100.0);
    return percent;
}

void ImprimeCandidato (tCandidato* candidato, float percentualVotos){
    printf("%s ", candidato->nome);
    printf("(%s), ", candidato->partido);
    printf("%d voto(s), ", candidato->votos);
    printf("%.2f%%", percentualVotos);
    printf("\n");
}
