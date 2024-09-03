#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"


tJogador* CriaJogador(int idJogador){
    tJogador *jogador = malloc(sizeof(tJogador));
    jogador->id = idJogador;
    return jogador;
}

void DestroiJogador(tJogador* jogador){
    free(jogador);
}

void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    
}