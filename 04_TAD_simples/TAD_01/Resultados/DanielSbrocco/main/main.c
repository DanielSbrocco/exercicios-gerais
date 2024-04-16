#include <stdio.h>
#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"

int main(){
    tJogo jogo;
    int continua = 1;
    jogo = CriaJogo();
    while(continua == 1){
        ComecaJogo(jogo);
        continua = ContinuaJogo();
    }
    return 0;
}