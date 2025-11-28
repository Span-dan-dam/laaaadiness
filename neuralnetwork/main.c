#include <stdio.h>
#include "matrix.h"

void main(){
    matrix matrix1, matrix2, matrix;
    matrix1= create_matrix(2,2);
    matrix2= create_matrix(2,2);
    matrix= multiply_matrix_matrix(matrix1,matrix2);
    print_matrix(matrix);
    free_matrix(matrix);
    free_matrix(matrix1);
    free_matrix(matrix2);
}