#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

typedef struct{
    int input_num;
    matrix inputs;
    int output_num;
    matrix outputs;
    int hidden_layers_num;
    int* hidden_nodes_num;
    matrix input_hidden_weights;
    matrix* hidden_hidden_weights;
    matrix hidden_output_weights;
    matrix* hidden_biases;
    matrix output_biases;
} neural_network;

void create_neural_network(neural_network* brain, int input_num, int output_num, int hidden_layers_num, int* hidden_nodes_num){
    brain->input_num = input_num;
    brain->output_num = output_num;
    brain->hidden_layers_num = hidden_layers_num;
    brain->hidden_nodes_num = (int*)malloc(hidden_layers_num * sizeof(int));
    for(int i = 0; i < hidden_layers_num; i++){
        brain->hidden_nodes_num[i] = hidden_nodes_num[i];
    }
    // Initializing weights
    brain->input_hidden_weights = create_matrix(hidden_nodes_num[0], input_num);
    brain->hidden_hidden_weights = (matrix*)malloc((hidden_layers_num - 1) * sizeof(matrix));
    for(int i = 0; i < hidden_layers_num - 1; i++){
        brain->hidden_hidden_weights[i] = create_matrix(hidden_nodes_num[i + 1], hidden_nodes_num[i]);
    }
    brain->hidden_output_weights = create_matrix(output_num, hidden_nodes_num[hidden_layers_num - 1]);
    // Initializing biases
    brain->hidden_biases = (matrix*)malloc(hidden_layers_num* sizeof(matrix));
    for(int i=0; i < hidden_layers_num; i++){
        brain->hidden_biases[i] = create_matrix(hidden_nodes_num[i],1);
    }
    brain->output_biases = create_matrix(output_num,1);
}