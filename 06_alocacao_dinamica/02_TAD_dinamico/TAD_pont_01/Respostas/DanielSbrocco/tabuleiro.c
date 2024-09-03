#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"


tTabuleiro* CriaTabuleiro(){
    tTabuleiro *tab = malloc(sizeof(tTabuleiro));
    tab->posicoes = malloc(3*sizeof(char*));
    for(int i = 0; i < TAM_TABULEIRO; i++){
        tab->posicoes[i] = malloc(3*sizeof(char));
    }
    tab->peca1 = 'X';
    tab->peca2 = '0';
    tab->pecaVazio = '-';
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            tab->posicoes[i][j] = tab->pecaVazio;
        }
    }
    return tab;
}

void DestroiTabuleiro(tTabuleiro* tabuleiro){
    for(int i = 0; i < 3; i++){
        free(tabuleiro->posicoes[i]);
    }
    free(tabuleiro->posicoes);
    free(tabuleiro);
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    char marcaPeca;
    if(peca == PECA_1){
        marcaPeca = tabuleiro->peca1;
    }
    if(peca == PECA_2){
        marcaPeca = tabuleiro->peca2;
    }
    if(TemPosicaoLivreTabuleiro(tabuleiro)){
        if(EhPosicaoValidaTabuleiro(x, y)){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
                tabuleiro->posicoes[y][x] = marcaPeca;
            }
        }
    }
}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    if(peca == PECA_1){
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca1){
            return 1;
        }
    }
    if(peca == PECA_2){
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca2){
            return 1;
        }
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio){
        return 1;
    } else {
        return 0;
    }
    printf("Posicao nao Livre\n");
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x >= 0 && x <= 2){
        if(y >= 0 && y <= 2){
            return 1;
        }
    }
    return 0;
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for(int j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}