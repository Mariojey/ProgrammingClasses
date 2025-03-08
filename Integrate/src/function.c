#include <stdio.h>
#include "function.h"
#include <math.h>

//x^2 +3x+2
double f1(double x){
    return (x*x) + (3*x) + 2;
}

//sin(x)
double f2(double x){
    return sin(x);
}

//e^x
double f3(double x){
    double euler = exp(1.0);
    double result = pow(euler, x);
    return result;
}

//1/(x+1)
double f4(double x){
    if(x != -1){
      return (1 / (x + 1));
    }else{
      return 0;
    }
}