#include <stdio.h>
#include "vetor.h"

int Adicao(int num1, int num2) {
    return num1 + num2;
}

int Multiplicacao(int num1, int num2) {
    return num1 * num2;
}

int main() {
    Vetor vetor;
    int result = 0;
    LeVetor(&vetor);
    result = AplicarOperacaoVetor(&vetor, Adicao);
    printf("Soma: %d\n", result);
    result = AplicarOperacaoVetor(&vetor, Multiplicacao);
    printf("Produto: %d\n", result);
    return 0;
}