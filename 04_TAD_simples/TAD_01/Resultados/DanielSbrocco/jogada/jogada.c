#include <stdio.h>
#include "jogada.h"


tJogada LeJogada(){
    tJogada jog;
    jog.x = -100;
    jog.y = -100;
    printf("Digite uma posicao (x e y): \n");
    if(scanf("%d %d", &jog.x, &jog.y) == 2){
        jog.sucesso = 1;
    } else {
        jog.sucesso = 0;
    }
    return jog;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}