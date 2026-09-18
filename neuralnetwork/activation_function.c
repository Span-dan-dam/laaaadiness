#include<stdio.h>
#include<stdlib.h>
#include<math.h>


float hyperbolic_tan(float x){
    return tanhf(x);
}

float reLU(float x){
    if(x>0){
        return x;
    }
    else{
        return 0;
    }
}

float leaky_relu(float x){
    float leak_rate = 0.01;
    if (x>0){
        return x;
    }
    else{
        return leak_rate *x;
    }
}

