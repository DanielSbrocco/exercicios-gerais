#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadgen.h"

int main(){
    int tipo, num;
    Type t;

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:");

    scanf("%d %d", &tipo, &num);
    t = tipo;

    tGeneric *generic = CriaGenerico(t, num);

    LeGenerico(generic);

    ImprimeGenerico(generic);

    DestroiGenerico(generic);

    return 0;
}