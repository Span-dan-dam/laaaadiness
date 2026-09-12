typedef struct{
    int row;
    int col;
    float **data;
} matrix;
 
void seed_randomizer();
void create_matrix (int n ,int m ,matrix* matrix);
void free_matrix(matrix* matrix);
void print_matrix(matrix* matrix);
void add_matrix(matrix* A, matrix* B, matrix* C);
void substract_matrix(matrix* A, matrix* B, matrix* C);
void multiply_matrix_const(matrix* A, float k,matrix* C);
void multiply_matrix_matrix(matrix* A,matrix* B , matrix* C);
void transpose_matrix(matrix* A,matrix* B);
void randomize_matrix(matrix* A);
void acctivation_function(matrix* A, float* Acti_func(float), matrix* B);