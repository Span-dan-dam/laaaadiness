#include <stdio.h>
//#include "matrix.h"
#include "neuralnetwork.h"

void main(){
    matrix input , output ;
    neural_network brain;
    int input_num = 2;
    int output_num = 1;
    int hidden_layers_num = 2;
    float learning_rate = 0.1;
    int hidden_node_num [2]={2,1};
    create_matrix(2,1,&input);
    input.data[0][0]= 1.0;
    input.data[1][0]= 0.5;
    //input.data={}
    create_neural_network(&brain,input_num,output_num,hidden_layers_num,hidden_node_num,learning_rate);
    feedforword(&brain,&input,&output);
    print_matrix(&input);
}