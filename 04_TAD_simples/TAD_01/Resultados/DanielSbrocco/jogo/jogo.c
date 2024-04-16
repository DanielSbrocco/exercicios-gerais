#include <stdio.h>
#include "jogo.h"

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(1);
    jogo.jogador2 = CriaJogador(2);
    return jogo;
}

void ComecaJogo(tJogo jogo){
    int cont = 0;
    while(!AcabouJogo(jogo)){
        if(cont%2 == 0){
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        } else {
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        }
        ImprimeTabuleiro(jogo.tabuleiro);
        cont++;
    }
}

int AcabouJogo(tJogo jogo){
    if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)){
        printf("JOGADOR 1 Venceu!\n");
        return 1;
    } else if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
        printf("JOGADOR 2 Venceu!\n");
        return 1;       
    } else if(!TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        printf("Sem vencedor!\n");
        return 1;
    }
    return 0;
} 

int ContinuaJogo(){
    char resp = 0;
    printf("Jogar novamente? (s,n)\n");
    while(resp != 's' && resp != 'n'){
        scanf("%c", &resp);
    }
    if(resp == 's'){
        return 1;
    } else if(resp == 'n'){
        return 0;
    }
}