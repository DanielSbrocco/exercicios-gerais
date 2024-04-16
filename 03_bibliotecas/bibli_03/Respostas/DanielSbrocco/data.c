#include <stdio.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano){
    if(ano > 0){
        if(mes > 0 && mes <= 12){
            if(dia <= numeroDiasMes(mes, ano) && dia > 0){
                return 1;
            }
        }
    }
}

void imprimeMesExtenso(int mes){
    if(mes == 1){
        printf("Janeiro ");
    }
    if(mes == 2){
        printf("Fevereiro ");
    }
    if(mes == 3){
        printf("Marco ");
    }
    if(mes == 4){
        printf("Abril ");
    }
    if(mes == 5){
        printf("Maio ");
    }
    if(mes == 6){
        printf("Junho ");
    }
    if(mes == 7){
        printf("Julho ");
    }
    if(mes == 8){
        printf("Agosto ");
    }
    if(mes == 9){
        printf("Setembro ");
    }
    if(mes == 10){
        printf("Outubro ");
    }
    if(mes == 11){
        printf("Novembro ");
    }
    if(mes == 12){
        printf("Dezembro ");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%d de ");
    imprimeMesExtenso(mes);
    printf("%d", ano);
}

int verificaBissexto(int ano){
    if(ano%4 == 0){
        return 1;
    } else {
        return 0;
    }
}

int numeroDiasMes(int mes, int ano){
    if((mes%2 == 1 && mes < 8) || (mes%2 == 0 && mes > 7)){
        return 31;
    } else if(mes == 2){
        if(verificaBissexto(ano) == 1){
            return 29;
        } else {
            return 28;
        }
    } else if((mes%2 == 0 && mes < 8) || (mes%2 == 1 && mes > 7)) {
        return 30;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2){
        return 1;
    } else if(ano1 < ano2){
        return -1;
    } else if(ano1 == ano2){
        if(mes1 > mes2){
            return 1;
        } else if(mes1 < mes2){
            return -1;
        } else if(mes1 == mes2){
            if(dia1 > dia2){
                return 1;
            } else if(dia1 < dia2){
                return -1;
            } else if(dia1 == dia2){
                return 0;
            }
        }
    }
}

int calculaDiasAteMes(int mes, int ano){
    int i, soma = 0;
    for(i = 0; i < mes; i++){
        soma += numeroDiasMes(mes, ano);
    }
    return soma;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int diff, i;
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1){
        
    }
}