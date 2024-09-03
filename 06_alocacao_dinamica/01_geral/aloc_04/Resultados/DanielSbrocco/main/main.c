#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

int main(){
    char *vetor;
    int tamVet;
    tamVet = TAM_PADRAO;
    vetor = CriaVetorTamPadrao();
    vetor = LeVetor(vetor, &tamVet);
    ImprimeString(vetor);
    LiberaVetor(vetor);
}