#include <stdio.h>
#include <math.h> 
double calc(int m1, int m2, int d){
    double g = 6.67*pow(10,-1);
    double res = g*m1*m2/pow(d,2);
    return res;
}

int main (void){
    double res = calc(4,7,8);
    printf("%lf", res);
}