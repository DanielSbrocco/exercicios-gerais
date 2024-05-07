#include <stdio.h>
#include "data.h"
#include <stdlib.h>

tData CriaData(int dia, int mes, int ano){
    tData data;
    data.ano = ano;
    data.mes = mes;
    data.dia = dia;
    return data;
}

int VerificaDataValida(tData data){
    if(data.mes > 0 && data.mes < 13){
        if(data.dia > NumeroDiasMes(data)){
            return 0;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

void ImprimeMesExtenso(tData data){
    if(data.mes == 1){
        printf("Janeiro ");
    }
    if(data.mes == 2){
        printf("Fevereiro ");
    }
    if(data.mes == 3){
        printf("Marco ");
    }
    if(data.mes == 4){
        printf("Abril ");
    }
    if(data.mes == 5){
        printf("Maio ");
    }
    if(data.mes == 6){
        printf("Junho ");
    }
    if(data.mes == 7){
        printf("Julho ");
    }
    if(data.mes == 8){
        printf("Agosto ");
    }
    if(data.mes == 9){
        printf("Setembro ");
    }
    if(data.mes == 10){
        printf("Outubro ");
    }
    if(data.mes == 11){
        printf("Novembro ");
    }
    if(data.mes == 12){
        printf("Dezembro ");
    }
}

int NumeroDiasMes(tData data){
    if(data.mes < 8){
        if(data.mes%2 == 1){
            return 31;
        } else if(data.mes == 2) {
            return (28+VerificaBissexto(data));
        } else {
            return 30;
        }
    } else {
        if(data.mes%2 == 0){
            return 31;
        } else {
            return 30;
        }
    }
}

int ComparaData(tData data1, tData data2){
    if(data1.ano > data2.ano){
        return 1;
    } else if(data1.ano < data2.ano){
        return -1;
    } else {
        if(data1.mes > data2.mes){
            return 1;
        } else if(data1.mes < data2.mes){
            return -1;
        } else {
            if(data1.dia > data2.dia){
                return 1;
            } else if(data1.dia < data2.dia){
                return -1;
            } else {
                return 0;
            }
        }
    }
}

int CalculaDiasAteMes(tData data){
    int num = 0;
    for(int i = 1; i < data.mes; i++){
        if(i < 8){
            if(i%2 == 1){
                num += 31;
            } else if(i == 2) {
                num += (28+VerificaBissexto(data));
            } else {
                num += 30;
            }
        } else {
            if(i%2 == 0){
                num += 31;
            }
            if(i%2 == 1){
                num += 30;
            }
        }
    }
    return num;
}

int CalculaDiferencaDias(tData data1, tData data2){
    int diff = 0;
    tData data3;
    if(ComparaData(data1, data2) == 1){
        for(int i = data2.ano; i < data1.ano; i++){
            data3 = CriaData(data2.dia, data2.mes, i);
            diff += (365+VerificaBissexto(data3));
        } 
        diff -= CalculaDiasAteMes(data2);
        diff += CalculaDiasAteMes(data1);
        diff -= data2.dia;
        diff += data1.dia;
    } else if(ComparaData(data1, data2) == -1){
        for(int i = data1.ano; i < data2.ano; i++){
            data3 = CriaData(data1.dia, data1.mes, i);
            diff += (365+VerificaBissexto(data3));
        } 
        diff -= CalculaDiasAteMes(data1);
        diff += CalculaDiasAteMes(data2);
        diff -= data1.dia;
        diff += data2.dia;
    } else {
        return diff;
    }
    return diff;
}

int VerificaBissexto(tData data){
    if(data.ano%4 == 0){
        return 1;
    } else {
        return 0;
    }
}

void ImprimeDataExtenso(tData data){
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf("de %d\n", data.ano);
}