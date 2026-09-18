#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "activation_function.h"

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

void create_neural_network(neural_network* brain, int input_num, int output_num, int hidden_layers_num, int* hidden_nodes_num,float learning_rate){
    brain->input_num = input_num;
    brain->output_num = output_num;
    brain->learning_rate = learning_rate;
    brain->hidden_layers_num = hidden_layers_num;
    brain->hidden_nodes_num = (int*)malloc(hidden_layers_num * sizeof(int));
    for(int i = 0; i < brain->hidden_layers_num; i++){
        brain->hidden_nodes_num[i] = hidden_nodes_num[i];
    }
    // Initializing weights;
    // making the input to hidden weights matrix;
    create_matrix(hidden_nodes_num[0], input_num, &brain->input_hidden_weights);
    randomize_matrix( &brain->input_hidden_weights);
    // print_matrix(&brain->input_hidden_weights);

    //making the hidden to hidden weights matrix;
    brain->hidden_hidden_weights = (matrix*)malloc((hidden_layers_num - 1) * sizeof(matrix));
    for(int i = 0; i < brain->hidden_layers_num - 1; i++){
        create_matrix(hidden_nodes_num[i + 1], hidden_nodes_num[i],&brain->hidden_hidden_weights[i]);
        randomize_matrix( &brain->hidden_hidden_weights[i]);
        // print_matrix(&brain->hidden_hidden_weights[i]);
    }

    //making the hidden to output weights matrix;
    create_matrix(output_num, hidden_nodes_num[hidden_layers_num - 1],&brain->hidden_output_weights);
    randomize_matrix( &brain->hidden_output_weights);
    // print_matrix(&brain->hidden_output_weights);

    // Initializing biases

    //making the hidden biases matrix;
    brain->hidden_biases = (matrix*)malloc(hidden_layers_num* sizeof(matrix));
    for(int i=0; i < brain->hidden_layers_num; i++){
        create_matrix(hidden_nodes_num[i],1,&brain->hidden_biases[i]);
        randomize_matrix(&brain->hidden_biases[i]);
        //print_matrix(&brain->hidden_biases[i]);
    }

    //making the output biases matrix;
    create_matrix(output_num,1,&brain->output_biases);
    randomize_matrix(&brain->output_biases);
    //print_matrix(&brain->output_biases);
}


void feedforword (neural_network* brain , matrix* input, matrix* output){
    //print_matrix(input);
    matrix hidden_layer1,hidden_layer2; //i am using the layers alternatingly;

    // input layer to hidden layer0;

    //mulitiplayaing the input layer with the input to hidden weights;
    multiply_matrix_matrix(&brain->input_hidden_weights,input,&hidden_layer1); 
    //print_matrix(&hidden_layer1);

    //adding the hidden layer0 bias;
    add_matrix(&hidden_layer1,&brain->hidden_biases[0],&hidden_layer2);
    //print_matrix(&hidden_layer2);

    //applying the activation function tanh;
    activation_function(&hidden_layer2, &hyperbolic_tan, &hidden_layer1);
    //print_matrix(&hidden_layer1);
    
    //hidden layer[n-1] to hidden layer[n];
    for(int i=0 ; i< brain->hidden_layers_num-1 ;i++){

        //multiplying the hidden layer[i] with hidden layer[i] to hidden layer [i+1] weights;
        multiply_matrix_matrix(&brain->hidden_hidden_weights[i],&hidden_layer1,&hidden_layer2);
        //print_matrix(&hhidden_layer2);

        //adding the hidden layer[i+1] bias;
        add_matrix(&hidden_layer2,&brain->hidden_biases[i+1],&hidden_layer1);
        //print_matrix(&hidden_layer1);

        //applying the activation function tanh;
        activation_function(&hidden_layer1,&hyperbolic_tan,&hidden_layer2);
        //print matrix(&hidden_layer2);
    }

}
