#include <stdio.h>
#include <string.h>
#include "candidato.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;
    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;
    return candidato;
}

tCandidato LeCandidato(){
    char nome[50], partido[50], cargo;
    int id;
    scanf(" %49[^,]", nome);
    getchar();
    scanf(" %49[^,]", partido);
    getchar();
    scanf(" %c", &cargo);
    getchar();
    scanf("%d", &id);
    tCandidato candidato = CriaCandidato(nome, partido, cargo, id);
    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id){
    if(candidato.id == id){
        return 1;
    } else {
        return 0;
    } 
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    //talvez tenha q verificar se o mesmo cargo
    if(candidato1.id == candidato2.id){
        return 1;
    } else{
        return 0;
    } 
}

char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    if(totalVotos > 0){
        return (candidato.votos/(totalVotos*1.0) * 100.0);
    } else {
        return 0;
    }
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}