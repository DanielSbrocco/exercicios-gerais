#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

tLocadora* CriarLocadora (){
    tLocadora *loc = (tLocadora*)malloc(sizeof(tLocadora));
    loc->filme = NULL;
    loc->lucro = 0;
    loc->numFilmes = 0;
    return loc;
}

void DestruirLocadora (tLocadora* locadora){
    for(int i = 0; i < locadora->numFilmes; i++){
        DestruirFilme(locadora->filme[i]);
    }
    free(locadora->filme);
    free(locadora);
}

int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    for(int i = 0; i < locadora->numFilmes; i++){
        if(EhMesmoCodigoFilme(locadora->filme[i], codigo) == 1){
            return 1;
        }
    } 
    return 0;
}

void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    locadora->filme = (tFilme**)realloc(locadora->filme, (locadora->numFilmes + 1) * sizeof(tFilme*));
    locadora->filme[locadora->numFilmes] = CriarFilme();
    locadora->filme[locadora->numFilmes] = filme;
    locadora->numFilmes++;
}

void LerCadastroLocadora (tLocadora* Locadora){
    tFilme *filme = CriarFilme();
    int codigo;
    scanf("%d", &codigo);
    getchar();
    LeFilme(filme, codigo);
    CadastrarFilmeLocadora(Locadora, filme);
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    for(int i = 0; i < quantidadeCodigos; i++){
        for(int j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i]) == 1){
                AlugarFilme(locadora->filme[j]);
                break;
            }
        }
    }
}

void LerAluguelLocadora (tLocadora* locadora){
    int qtd = 0;
    int *codigo = NULL;
    int temp = 0;
    int flag = 0;
    while(flag == 0){
        if(scanf("%d", &temp)){
            flag = 0;
        } else {
            flag = 1;
        }
        codigo = (int*)realloc(codigo, (qtd+1)*sizeof(int));
        codigo[qtd] = temp;
        qtd++;
    }
    if (qtd > 0) {
        AlugarFilmesLocadora(locadora, codigo, (qtd+1));
    }    
    free(codigo);
}

void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    for(int i = 0; i < quantidadeCodigos; i++){
        for(int j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])){
                DevolverFilme(locadora->filme[j]);
            }
        }
    }
}

void LerDevolucaoLocadora (tLocadora* locadora){
    int *codigo = (int*)malloc(sizeof(int));
    int temp;
    int qtd = 0;
    scanf("%d", &temp);
    codigo[qtd] = temp;
    qtd++;
    while(scanf("%d", &temp) == 1){
        codigo = (int*)realloc(codigo, (qtd+1)*sizeof(int));
        codigo[qtd] = temp;
        qtd++;
    }
    DevolverFilmesLocadora(locadora, codigo, qtd);
    free(codigo);
}

void OrdenarFilmesLocadora (tLocadora* locadora){
    tFilme *filmeTroca = CriarFilme();
    for(int i = 0; i < (locadora->numFilmes-1); i++){
        for(int j = i+1; j < locadora->numFilmes; j++){
            if(strcmp(locadora->filme[i], locadora->filme[j]) == 1){
                filmeTroca = locadora->filme[i];
                locadora->filme[i] = locadora->filme[j];
                locadora->filme[j] = filmeTroca;
            }
        }
    }
    DestruirFilme(filmeTroca);
}

void ConsultarEstoqueLocadora (tLocadora* locadora){
    printf("%d", locadora->numFilmes);
}

void ConsultarLucroLocadora (tLocadora* locadora){
    printf("%d", locadora->lucro);
}