#include <stdio.h>
#include <string.h>
#include "filme.h"

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme filme;
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;
    strcpy(filme.nome, nome);
    return filme;
}   

tFilme leFilme(int codigo){
    int qtdFitas, valor;
    char nome[MAX_CARACTERES];
    scanf("%[^,]", nome);
    getchar();
    scanf("%d,%d", &valor, &qtdFitas);
    tFilme filme = criarFilme(nome, codigo, valor, qtdFitas);
    return filme;
}

int obterCodigoFilme (tFilme filme){
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme){
    printf("%s", filme.nome);
}

int obterValorFilme (tFilme filme){
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme){
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo){
    if(filme.codigo == codigo){
        return 1;
    } else {
        return 0;
    }
}

tFilme alugarFilme (tFilme filme){
    filme.qtdEstoque--;
    filme.qtdAlugada++;
    return filme;
}

tFilme devolverFilme (tFilme filme){
    filme.qtdEstoque++;
    filme.qtdAlugada--;
    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2){
    return strcmp(filme1.nome, filme2.nome);
}