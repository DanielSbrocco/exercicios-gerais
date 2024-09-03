#include <stdio.h>
#include "utils_char.h"
#include <stdlib.h>

int main(){
    int numChar;
    scanf("%d\n", &numChar);
    char *vetor = CriaVetor(numChar);
    ImprimeString(vetor, numChar);
    LeVetor(vetor, numChar);
    ImprimeString(vetor, numChar);
    LiberaVetor(vetor);
}