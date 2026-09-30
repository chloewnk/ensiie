#include <stdio.h>
double fabs (double a){
    if (a<0) a=a*(-1);
    return a;
}
int main(void){
    double x1 , y2 ;
    x1 = 1/34028234.0;
    y2 = ((1/34028234.0) + 3) - 3;

    if ((fabs(x1)-fabs(y2))<=0.001){
        printf("Egaux");
    } else {
        printf("pas égaux");
    } 

}