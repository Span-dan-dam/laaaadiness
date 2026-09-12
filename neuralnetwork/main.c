#include <stdio.h>
//#include "matrix.h"
#include "neuralnetwork.h"

void main(){
    matrix input , output ;
    neural_network brain;
    int hidden_node [2]={2,1};
    create_matrix(2,1,&input);
    input.data[0][0]= 1.0;
    input.data[1][0]= 0.5;
    //input.data={}
    create_neural_network(&brain,2,1,2,hidden_node);
    feedforword(&brain,&input,&output);
    print_matrix(&input);
}