#include <stdio.h>
#include "matrix_utils.h"

int main(){
    tMatrix matrix1, matrix2;
    int rows1, cols1, rows2, cols2;
    scanf("%d %d", &rows1, &cols1);
    matrix1 = MatrixCreate(rows1, cols1);
    matrix1 = MatrixRead(matrix1);
    scanf("%d %d", &rows2, &cols2);
    matrix2 = MatrixCreate(rows2, cols2);
    matrix2 = MatrixRead(matrix2);
    int opcao = -1, scalar, num;
    while(opcao != 6){
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");
        scanf("%d", &opcao);
        if(opcao == 1){
            if(PossibleMatrixSum(matrix1, matrix2)){
                MatrixPrint(MatrixAdd(matrix1, matrix2));
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        if(opcao == 2){
            if(PossibleMatrixSub(matrix1, matrix2)){
                MatrixPrint(MatrixSub(matrix1, matrix2));
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        if(opcao == 3){
            if(PossibleMatrixMultiply(matrix1, matrix2)){
                MatrixPrint(MatrixMultiply(matrix1, matrix2));
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }
        if(opcao == 4){
            scanf("%d %d", &scalar, &num);
            if(num == 1){
                matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                MatrixPrint(matrix1);
            } else if(num == 2){
                matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                MatrixPrint(matrix2);
            }
        }
        if(opcao == 5){
            MatrixPrint(TransposeMatrix(matrix1));
            MatrixPrint(TransposeMatrix(matrix2));

        }
        if(opcao == 6){
            break;
        }
    }
}