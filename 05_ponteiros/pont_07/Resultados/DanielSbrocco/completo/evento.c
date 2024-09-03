#include <stdio.h>
#include "evento.h"
#include "string.h"

void cadastrarEvento(Evento* eventos, int* numEventos){
    if(*numEventos < MAX_EVENTOS){
        scanf("%s", eventos[*numEventos].nome);
        scanf("%d %d %d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
        printf("Evento cadastrado com sucesso!\n");
        *numEventos += 1;
    } else {
        printf("Limite de eventos atingido!\n");
    }
}

void exibirEventos(Evento* eventos, int* numEventos){
    for(int i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }   
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int num;
    scanf("%d", &num);
    if(num < *numEventos){
        scanf("%d %d %d", &eventos[num].dia, &eventos[num].mes, &eventos[num].ano);
        printf("Data modificada com sucesso!\n");
    } else {
        printf("Nao data modificada\n");
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    Evento troca;
    if(*indiceA < *numEventos && *indiceB < *numEventos){
        strcpy(troca.nome, eventos[*indiceA].nome);
        troca.dia = eventos[*indiceA].dia;
        troca.mes = eventos[*indiceA].mes;
        troca.ano = eventos[*indiceA].ano;

        strcpy(eventos[*indiceA].nome, eventos[*indiceB].nome);
        eventos[*indiceA].dia = eventos[*indiceB].dia;
        eventos[*indiceA].mes = eventos[*indiceB].mes;
        eventos[*indiceA].ano = eventos[*indiceB].ano;

        strcpy(eventos[*indiceB].nome, eventos[*indiceA].nome);
        eventos[*indiceB].dia = troca.dia;
        eventos[*indiceB].mes = troca.mes;
        eventos[*indiceB].ano = troca.ano;

        printf("Eventos trocados com sucesso!\n");        
    } else {
        printf("Indices invalidos!\n");
    }
}