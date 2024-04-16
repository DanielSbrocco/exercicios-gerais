#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;

    tabuleiro.pecaVazio = '-';
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }
    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(i == y && j == x){
                if(peca == PECA_1){
                    tabuleiro.posicoes[i][j] = tabuleiro.peca1;
                }
                if(peca == PECA_2){
                    tabuleiro.posicoes[i][j] = tabuleiro.peca2;
                }
            }
        }
    }
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca == PECA_1){
        if(tabuleiro.posicoes[y][x] == tabuleiro.peca1){
            return 1;
        }
    }
    if(peca == PECA_2){
        if(tabuleiro.posicoes[y][x] ==  tabuleiro.peca2){
            return 1;
        }
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio){
        return 1;
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if((x >= TAM_TABULEIRO || y >= TAM_TABULEIRO) || (x < 0 || y < 0)){
        return 0;
    } else {
        return 1;
    }
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for(j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}