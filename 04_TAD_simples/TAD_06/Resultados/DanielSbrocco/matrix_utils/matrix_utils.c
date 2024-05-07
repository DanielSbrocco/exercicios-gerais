#include <stdio.h>
#include "matrix_utils.h"

tMatrix MatrixCreate(int rows, int cols){
    tMatrix matrix;
    matrix.cols = cols;
    matrix.rows = rows;
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.cols; j++){
            matrix.data[i][j] = 0;
        }
    }
    return matrix;
}

tMatrix MatrixRead(tMatrix matrix){
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.cols; j++){
            scanf("%d", &matrix.data[i][j]);
        }
    }
    return matrix;
}

void MatrixPrint(tMatrix matrix){
    for(int i = 0; i < matrix.rows; i++){
        printf("|");
        for(int j = 0; j < matrix.cols; j++){
            printf("%d", matrix.data[i][j]);
            if(j < matrix.cols-1){
                printf(" ");
            }

        }
        printf("|\n");
    } 
    printf("\n");
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    if((matrix1.cols == matrix2.cols) && (matrix1.rows == matrix2.rows)){
        return 1;
    } else {
        return 0;
    }
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    if((matrix1.cols == matrix2.cols) && (matrix1.rows == matrix2.rows)){
        return 1;
    } else {
        return 0;
    } 
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.cols){
        return 1;
    } else {
        return 0;
    }
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    for(int i = 0; i < matrix1.rows; i++){
        for(int j = 0; j < matrix2.cols; j++){
            matrix1.data[i][j] += matrix2.data[i][j];
        }
    }
    return matrix1;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    for(int i = 0; i < matrix1.rows; i++){
        for(int j = 0; j < matrix2.cols; j++){
            matrix1.data[i][j] -= matrix2.data[i][j];
        }
    }
    return matrix1;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    tMatrix multmatrix;
    int sum = 0, l = 0;
    multmatrix = MatrixCreate(matrix1.rows, matrix2.cols);
    for(int i = 0; i < matrix1.rows; i++){
        for(int j = 0; j < matrix2.rows; j++){
            sum = 0;
            for(int k = 0; k < matrix1.cols; k++){
                sum += matrix1.data[i][k]*matrix2.data[k][j];
            }
            multmatrix.data[i][j] = sum;
        }
    }
    return multmatrix;
}

tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix transpmatrix;
    transpmatrix = MatrixCreate(matrix.cols, matrix.rows);
    for(int i = 0; i < transpmatrix.rows; i++){
        for(int j = 0; j < transpmatrix.cols; j++){
            transpmatrix.data[i][j] = matrix.data[j][i];
        }
    }
    return transpmatrix;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.cols; j++){
            matrix.data[i][j] = matrix.data[i][j]*scalar;
        }
    }
    return matrix;
}