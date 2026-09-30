#include <stdio.h>

int main(void){
    int h;
    printf("h : ");
    scanf("%d",&h);
    for (int i = 0 ; i < h ; i++){
        printf ("*");
    }
    printf ("\n");
    for (int i = 0 ; i< h-2; i++){
        printf("*");
        for (int j = 0 ; j<h ; j++){
            printf(" ");
        }
        printf("*\n");
    }
    for (int i = 0 ; i < h ; i++){
        printf ("*");
    }
}