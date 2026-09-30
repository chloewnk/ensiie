#include <stdio.h>

int main(void){
    int x1 = 1;
    int x2 = 2;
    int y1 = 4;
    int y2 = 6;
    printf("Point p1 : %d, %d\n",x1,y1 );
    printf("Point p2 : %d, %d\n",x2,y2);
    double milX = (double)(x1+x2)/2;
    double milY = (double)(y1+y2)/2;
    printf("Milieu de p1 et p2 : %lf, %lf\n",milX, milY);
}