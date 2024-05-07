#include <stdio.h>
#include "locadora.h"
#include <string.h>

tLocadora criarLocadora (){
    tLocadora loc;
    loc.numFilmes = 0;
    loc.lucro = 0;
    return loc;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    for(int  i = 0; i < locadora.numFilmes; i++){
        if(ehMesmoCodigoFilme(locadora.filme[i], codigo)){
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    if(verificarFilmeCadastrado(locadora, filme.codigo) == 0){
        locadora.filme[locadora.numFilmes].codigo = filme.codigo;
        locadora.filme[locadora.numFilmes].qtdAlugada = filme.qtdAlugada;
        locadora.filme[locadora.numFilmes].qtdEstoque = filme.qtdEstoque;
        strcpy(locadora.filme[locadora.numFilmes].nome, filme.nome); 
        locadora.numFilmes++;    
    }
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora){
    int codigo;
    while(scanf("%d", &codigo) == 1){
        locadora = cadastrarFilmeLocadora(locadora, leFilme(codigo));
    }
    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    for(int i = 0; i < quantidadeCodigos; i++){
        if(verificarFilmeCadastrado(locadora, codigos[i]) == 1){
            for(int j = 0; j < locadora.numFilmes; j++){
                if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) == 1){
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                }
            }
        }
    }
    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora){
    int codigo[locadora.numFilmes], numcodigo = 1;
    for(int i = 0; i < numcodigo; i++){
        if(scanf("%d", &codigo[i]) == 1){
            numcodigo++;
        }
    }
    locadora = alugarFilmesLocadora(locadora, codigo, numcodigo);
    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    for(int i = 0; i < quantidadeCodigos; i++){
        if(verificarFilmeCadastrado(locadora, codigos[i]) == 1){
            for(int j = 0; j < locadora.numFilmes; j++){
                if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i]) == 1){
                    locadora.filme[j] = devolverFilme(locadora.filme[j]);
                }
            }
        }
    }
    return locadora;
}

tLocadora lerDevolucaoLocadora (tLocadora locadora){
    int codigo[locadora.numFilmes], numcodigo = 1;
    for(int i = 0; i < numcodigo; i++){
        if(scanf("%d", &codigo[i]) == 1){
            numcodigo++;
        }
    }
    locadora = devolverFilmesLocadora(locadora, codigo, numcodigo);
    return locadora;
}

tLocadora ordenarFilmesLocadora (tLocadora locadora){
    
}