#include <stdio.h>
#include "utils.h"

void LeIntervalo(int * m, int * n){
    scanf("%d %d", &m, &n);
}


int EhPrimo(int n){
    int cont = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            cont++;
        }
    }
    if(cont > 2){
        return 0;
    } else {
        return 1;
    }
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    for(int i = m; i <= n; i++){
        if(EhPrimo(i) == 1){
            *menor = i;
            break;
        }
    }
    for(int i = n; i >= m; i--){
        if(EhPrimo(i) == 1){
            *maior = i;
            break;
        }
    }
}