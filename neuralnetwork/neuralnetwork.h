#include "matrix.h"
typedef struct{
    int input_num;
    matrix inputs;
    int output_num;
    matrix outputs;
    int hidden_layers_num;
    int* hidden_nodes_num;
    float learning_rate;
    matrix input_hidden_weights;
    matrix* hidden_hidden_weights;
    matrix hidden_output_weights;
    matrix* hidden_biases;
    matrix output_biases;
} neural_network;

void create_neural_network(neural_network* brain, int input_num, int output_num, int hidden_layers_num, int* hidden_nodes_num, float learning_rate);
void feedforword (neural_network* brain , matrix* input, matrix* output);