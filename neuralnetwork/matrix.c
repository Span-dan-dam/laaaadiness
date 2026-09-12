#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int row;
    int col;
    float **data;
} matrix;
void seed_randomizer(){
    srand(time(NULL));
}
void create_matrix (int n ,int m ,matrix* Matrix){
    Matrix->row= n;
    Matrix->col= m;
    Matrix->data= (float **)malloc(Matrix->row * sizeof(float *));
    for(int i=0;i<n;i++){
        Matrix->data[i]= (float *)malloc(Matrix->col * sizeof(float));
    }
    if (!Matrix->data) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    } 
}

void free_matrix(matrix* matrix){
    for(int i=0;i < matrix->row;i++){
        free(matrix->data[i]);
    }
    free(matrix->data);
}

void print_matrix(matrix* matrix){
    printf("\n__________________________________\n");
    for(int i=0;i < matrix->row;i++){
       for(int j=0;j < matrix->col;j++){
            printf("%f|",matrix->data[i][j]);
        }
        printf("\n__________________________________\n");
    }
}

void add_matrix(matrix* A, matrix* B, matrix* C){
    if(A->row != B->row || A->col != B->col){
        printf("Error: Matrices dimensions do not match for addition.\n");
        exit(EXIT_FAILURE);
    }
    create_matrix(A->row, A->col,C);
    for(int i=0;i < A->row;i++){
       for(int j=0;j < A->col;j++){
            C->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }
}

void substract_matrix(matrix* A, matrix* B ,matrix* C){
    if(A->row != B->row || A->col != B->col){
        printf("Error: Matrices dimensions do not match for subtraction.\n");
        exit(EXIT_FAILURE);
    }
    create_matrix(A->row, A->col,C);
    for(int i=0;i < A->row;i++){
       for(int j=0;j < A->col;j++){
            C->data[i][j] = A->data[i][j] - B->data[i][j];
        }
    }
}

void multiply_matrix_const(matrix* A, float k , matrix* C){
    create_matrix(A->row, A->col,C);
    for(int i=0;i < A->row;i++){
       for(int j=0;j < A->col;j++){
            C->data[i][j] = A->data[i][j] * k;
        }
    }
}

void multiply_matrix_matrix(matrix* A,matrix* B , matrix* C){
    if(A->col != B->row ){
        printf("Error:Matrices dimentions do not match for matrix multiplaction");
        exit(EXIT_FAILURE);
    }
    create_matrix(A->row,B->col,C);
    for(int i=0;i < A->row;i++){
        for(int j=0;j < B->col; j++){
            C->data[i][j]= 0;
            for(int k=0;k < A->col;k++){
                C->data[i][j] += (A->data[i][k] * B->data[k][j]);
            }
        }
    }
}
void transpose_matrix (matrix* A, matrix* B){
    create_matrix(A->col,A->row,B);
    for(int i = 0; i < A->row ; i++){
        for(int j = 0; j < A->row ; j++){
            B->data[j][i]= A->data[i][j];
        }
    }
}

void randomize_matrix(matrix* M){
    int data,k=0;
    for(int i = 0; i < M-> row ; i++){
        for(int j = 0; j < M-> col ; j++){
            data = 51 + k + i + j;
            data = data<<3;
            data = data<<15;
            data = data<<7;
            data = (data/30000);
            M-> data[i][j]=((float)data/100000.0);
            k+=2;
        }
    }
}
void acctivation_function(matrix* A, float* Acti_func(float), matrix* B){
       for(int i = 0; i < A-> row ; i++){
            for(int j = 0; j < A-> col ; j++){
            B->data[i][j] = acti_func(A->data[i][j]);
         }
    }
}    