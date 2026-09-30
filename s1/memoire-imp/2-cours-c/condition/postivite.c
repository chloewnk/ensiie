#include <stdio.h>

int main(void){
    int x;
    printf("nb:");
    scanf("%d",&x);
    if (x<0){
        printf("Négatif");
    }
    if (x>=0){
        printf("Positif");
    }

}