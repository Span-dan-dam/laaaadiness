#include <stdio.h>
#include "matrix.h"

void main(){
    matrix  matrix1,matrix2;
    matrix1= create_matrix(3,3);
    matrix2= randomize_matrix(matrix1);
   // matrix= multiply_matrix_matrix(matrix1,matrix2);
    print_matrix(matrix1);
    print_matrix(matrix2);
}