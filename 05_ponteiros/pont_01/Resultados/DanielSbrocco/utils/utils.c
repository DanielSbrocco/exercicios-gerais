#include "utils.h"

int TrocaInterios(int * n1, int * n2){
    int troca;
    if(*n1 <= *n2){
        return 0;
    } else {
        troca = *n1;
        *n1 = *n2;
        *n2 = troca;
        return 1;
    }
}