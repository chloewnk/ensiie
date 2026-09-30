#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void){
    double x, y;
    x = 340282346638528859811704183484516925440.0 - 1;
    y = 340282346638528859811704183484516925440.0 - 10;
    if (x==y){
        printf("egaux");
    } else {
        printf("pas egaux");
    }

    double x1 , y2 ;
        x1 = 1/34028234.0;
        y2 = ((1/34028234.0) + 3) - 3;

        if (x1==y2){
            printf("Egaux");
        } else {
            printf("pas égaux");
        } 

}