#include <stdio.h>
#include "jogador.h"
#include "jogada.h"

tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jog;
    int completo = 0;
    while(completo == 0){
        printf("Jogador %d\n", jogador.id);
        jog = LeJogada();
        if(EhPosicaoValidaTabuleiro(ObtemJogadaX(jog), ObtemJogadaY(jog))){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jog), ObtemJogadaY(jog))){
                printf("Jogada [%d,%d]!\n", ObtemJogadaX(jog), ObtemJogadaY(jog));
                tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jog), ObtemJogadaY(jog));
                completo = 1;
            } else {
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jog), ObtemJogadaY(jog));
            }
        } else {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jog), ObtemJogadaY(jog));
        }
    }
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    int i, j, hor = 0, vert = 0, diagd = 0, diage = 0;
    for(i = 0; i < TAM_TABULEIRO; i++){
        hor = 0;
        vert = 0;
        diagd = 0;
        diage = 0;
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id)){
                hor++;
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador.id)){
                vert++;
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, j, jogador.id)){
                diagd++;
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, (2-j), j, jogador.id)){
                diage++;
            }
        }
        if(diage == 3 || diagd == 3 || hor == 3 || vert == 3){
            return 1;
        }

    }
    return 0;
}