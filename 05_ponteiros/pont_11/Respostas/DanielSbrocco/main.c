#include <stdio.h>
#include "calculadora.h"

float Adicao(float num1, float num2){
    return num1+num2;
}

float Subtracao(float num1, float num2){
    return num1-num2;
}

float Multiplicacao(float num1, float num2){
    return num1*num2;
}

float Divisao(float num1, float num2){
    return num1/num2;
}

int main(){
    char op = 0;
    float num1 = 0, num2 = 0;
    while(op != 'f'){
        scanf("%c\n", &op);
        scanf("%f %f", &num1, &num2);
        if(op == 'a'){
            printf("%.2f + %.2f = %.2f\n", num1, num2, Calcular(num1, num2, Adicao));
        }

        if(op == 's'){
            printf("%.2f - %.2f = %.2f\n", num1, num2, Calcular(num1, num2, Subtracao));
        }

        if(op == 'm'){
            printf("%.2f x %.2f = %.2f\n", num1, num2, Calcular(num1, num2, Multiplicacao));
        }

        if(op == 'd'){
            printf("%.2f / %.2f = %.2f\n", num1, num2, Calcular(num1, num2, Divisao));
        }
    }
}