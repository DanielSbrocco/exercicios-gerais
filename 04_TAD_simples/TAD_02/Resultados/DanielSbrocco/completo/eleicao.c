#include <stdio.h>
#include <string.h>
#include "eleicao.h"


tEleicao InicializaEleicao(){
    tEleicao eleicao;
    eleicao.totalGovernadores = 0;
    eleicao.totalPresidentes = 0;
    eleicao.totalEleitores = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;
    tCandidato cand;
    int totalCand;
    scanf("%d", &totalCand);
    for(int i = 0; i < totalCand; i++){
        cand = LeCandidato();
        if(ObtemCargo(cand) == 'P'){
            eleicao.presidentes[eleicao.totalPresidentes] = CriaCandidato(cand.nome, cand.partido, cand.cargo, cand.id);
            eleicao.totalPresidentes++;
            for(int j = 0; j < (eleicao.totalPresidentes-1); j++){
                if(EhMesmoCandidato(eleicao.presidentes[eleicao.totalPresidentes-1], eleicao.presidentes[j])){
                    printf("ELEICAO ANULADA");
                    exit(1);
                }
            }
        }
        if(ObtemCargo(cand) == 'G'){
            eleicao.governadores[eleicao.totalGovernadores] = CriaCandidato(cand.nome, cand.partido, cand.cargo, cand.id);
            eleicao.totalGovernadores++;
            for(int j = 0; j < (eleicao.totalGovernadores-1); j++){
                if(EhMesmoCandidato(eleicao.governadores[eleicao.totalGovernadores-1], eleicao.governadores[j])){
                    printf("ELEICAO ANULADA");
                    exit(1);
                }
            }
        }
    }
    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    scanf("%d", &eleicao.totalEleitores);
    if(eleicao.totalEleitores > 10){
        printf("ELEICAO ANULADA");
        exit(1);
    }
    for(int i = 0; i < eleicao.totalEleitores; i++){
        eleicao.eleitores[i] = LeEleitor();
        for(int j = 0; j < i; j++){
            if(EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])){
                printf("ELEICAO ANULADA");
                exit(1);
            }
        }
    }
    int totalG = 0, totalP = 0;
    for(int i = 0; i < eleicao.totalEleitores; i++){
        for(int j = 0; j < eleicao.totalGovernadores; j++){
            if(VerificaIdCandidato(eleicao.governadores[j], ObtemVotoGovernador(eleicao.eleitores[i]))){
                eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                totalG++;
            }
        }
        for(int j = 0; j < eleicao.totalPresidentes; j++){
            if(VerificaIdCandidato(eleicao.presidentes[j], ObtemVotoPresidente(eleicao.eleitores[i]))){
                eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                totalP++;
            }
        }
        if(eleicao.eleitores[i].votoG == 0){
            eleicao.votosBrancosGovernador++;
            totalG++;
        }
        if(eleicao.eleitores[i].votoP == 0){
            eleicao.votosBrancosPresidente++;
            totalP++;
        }
    }
    if(eleicao.totalEleitores - totalG > 0){
        eleicao.votosNulosGovernador = eleicao.totalEleitores - totalG;
    }
    if(eleicao.totalEleitores - totalP > 0){
        eleicao.votosNulosPresidente = eleicao.totalEleitores - totalP;
    }
    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao){
    int maisVotos = 0, flag = 0;
    printf("- PRESIDENTE ELEITO: ");
    for(int i = 0; i < eleicao.totalPresidentes; i++){
        if(ObtemVotos(eleicao.presidentes[i]) > maisVotos){
            maisVotos = ObtemVotos(eleicao.presidentes[i]);
            flag = i;
        }
    }
    for(int i = 0; i < eleicao.totalPresidentes; i++){
        if((ObtemVotos(eleicao.presidentes[i]) == maisVotos) && (i != flag)){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            flag = -1;
        }
    }
    if(flag != -1){
        if((eleicao.votosNulosPresidente+eleicao.votosBrancosPresidente) > maisVotos){
            printf("SEM DECISAO\n");
        } else {
            ImprimeCandidato(eleicao.presidentes[flag], CalculaPercentualVotos(eleicao.presidentes[flag], eleicao.totalEleitores));
        }
    }

    maisVotos = 0;
    flag = 0;
    printf("- GOVERNADOR ELEITO: ");
    for(int i = 0; i < eleicao.totalGovernadores; i++){
        if(ObtemVotos(eleicao.governadores[i]) > maisVotos){
            maisVotos = ObtemVotos(eleicao.governadores[i]);
            flag = i;
        }
    }
    for(int i = 0; i < eleicao.totalGovernadores; i++){
        if((ObtemVotos(eleicao.governadores[i]) == maisVotos) && (i != flag)){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            flag = -1;
        }
    }
    if(flag != -1){
        if((eleicao.votosNulosGovernador+eleicao.votosBrancosGovernador) > maisVotos){
            printf("SEM DECISAO\n");
        } else {
            ImprimeCandidato(eleicao.governadores[flag], CalculaPercentualVotos(eleicao.governadores[flag], eleicao.totalEleitores));
        }
    }
    printf("- NULOS E BRANCOS: %d, %d\n", (eleicao.votosNulosGovernador+eleicao.votosNulosPresidente), (eleicao.votosBrancosGovernador+eleicao.votosBrancosPresidente));

}