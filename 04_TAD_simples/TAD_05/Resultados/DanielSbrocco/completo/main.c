#include <stdio.h>
#include "conta.h"

int main(){
    int numcontas;
    scanf("%d", &numcontas);
    tConta conta[numcontas];
    tUsuario user;
    int operacao = -1, num, cont = 0;
    float valor;
    while(operacao != 0){
        scanf("%d", &operacao);
        if(operacao == 0){
            break;
        }
        if(operacao == 1){
            scanf("%d %f", &num, &valor);
            for(int i = 0; i < numcontas; i++){
                if(VerificaConta(conta[i], num) == 1){
                    conta[i] = SaqueConta(conta[i], valor);
                }
            }
        }
        if(operacao == 2){
            scanf("%d %f", &num, &valor);
            for(int i = 0; i < numcontas; i++){
                if(VerificaConta(conta[i], num) == 1){
                    conta[i] = DepositoConta(conta[i], valor);
                }
            }
        }
        if(operacao == 3){
            scanf("%s ", user.nome);
            scanf("%s", user.cpf);
            scanf("%d", &num);
            conta[cont] = CriaConta(num, user);
            cont++;
        }
        if(operacao == 4){
            printf("===| Imprimindo Relatorio |===\n");
            for(int i = 0; i < numcontas; i++){
                ImprimeConta(conta[i]);
            }
        }
    }
    return 0;
}