#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;
    tabuleiro.pecaVazio = "-";
    tabuleiro.peca1 = "X";
    tabuleiro.peca2 = "0";
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
            if(i == x && j == y){
                if(peca == PECA_1){
                    tabuleiro.posicoes[i][j] = tabuleiro.peca1;
                }
                if(peca == PECA_2){
                    tabuleiro.posicoes[i][j] = tabuleiro.peca2;
                }
            }
        }
    }
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
    if(tabuleiro.posicoes[x][y] == peca){
        return 1;
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio){
        return 1;
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if((x > TAM_TABULEIRO || y > TAM_TABULEIRO) || (x < 0 || y < 0)){
        return 0;
    } else {
        return 1;
    }
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        printf("%s", tabuleiro.posicoes[i]);
        printf("\n");
    }
}