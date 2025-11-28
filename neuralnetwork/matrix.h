typedef struct{
    int row;
    int col;
    float **data;
} matrix;

matrix create_matrix (int n ,int m);
void free_matrix(matrix matrix);
void print_matrix(matrix matrix);
matrix add_matrix(matrix A, matrix B);
matrix substract_matrix(matrix A, matrix B);
matrix multiply_matrix_const(matrix A, float k);
matrix multiply_matrix_matrix(matrix A,matrix B);
