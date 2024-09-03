#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

tJogada* CriaJogada(){
    tJogada *jogada = malloc(3*sizeof(int*));
    return jogada;
}

void DestroiJogada(tJogada* jogada){
    free(jogada);
}

void LeJogada(tJogada* jogada){
    printf("Digite uma posicao (x e y):\n");
    scanf("%d %d", &jogada->x, &jogada->y);
    jogada->sucesso = 1;
}

int ObtemJogadaX(tJogada* jogada){
    return jogada->x;
}

int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada* jogada){
    return jogada->sucesso;
}