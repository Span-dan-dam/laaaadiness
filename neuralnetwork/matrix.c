#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int row;
    int col;
    float **data;
} matrix;
 
matrix create_matrix (int n ,int m){
    matrix matrix;
    matrix.row= n;
    matrix.col= m;
    matrix.data= (float **)malloc(matrix.row * sizeof(float *));
    for(int i=0;i<n;i++){
        matrix.data[i]= (float *)malloc(matrix.col * sizeof(float));
    }
    if (!matrix.data) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
            matrix.data[i][j]= 3 ;
        } 
    }
    return matrix;
}

void free_matrix(matrix matrix){
    for(int i=0;i < matrix.row;i++){
        free(matrix.data[i]);
    }
    free(matrix.data);
}

void print_matrix(matrix matrix){
    for(int i=0;i < matrix.row;i++){
       for(int j=0;j < matrix.col;j++){
            printf("%f  ",matrix.data[i][j]);
        }
        printf("\n");
    }
}

matrix add_matrix(matrix A, matrix B){
    if(A.row != B.row || A.col != B.col){
        printf("Error: Matrices dimensions do not match for addition.\n");
        exit(EXIT_FAILURE);
    }
    matrix C = create_matrix(A.row, A.col);
    for(int i=0;i < A.row;i++){
       for(int j=0;j < A.col;j++){
            C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
    return C;
}

matrix substract_matrix(matrix A, matrix B){
    if(A.row != B.row || A.col != B.col){
        printf("Error: Matrices dimensions do not match for subtraction.\n");
        exit(EXIT_FAILURE);
    }
    matrix C = create_matrix(A.row, A.col);
    for(int i=0;i < A.row;i++){
       for(int j=0;j < A.col;j++){
            C.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }
    return C;
}

matrix multiply_matrix_const(matrix A, float k){
    matrix C = create_matrix(A.row, A.col);
    for(int i=0;i < A.row;i++){
       for(int j=0;j < A.col;j++){
            C.data[i][j] = A.data[i][j] * k;
        }
    }
    return C;
}

matrix multiply_matrix_matrix(matrix A,matrix B){
    if(A.col != B.row ){
        printf("Error:Matrices dimentions do not match for matrix multiplaction");
        exit(EXIT_FAILURE);
    }
    matrix C = create_matrix(A.row,B.col);
    for(int i=0;i < A.row;i++){
        for(int j=0;j < B.col; j++){
            C.data[i][j]= 0;
            for(int k=0;k < A.col;k++){
                C.data[i][j] += (A.data[i][k] * B.data[k][j]);
            }
        }
    }
    return C;
}
