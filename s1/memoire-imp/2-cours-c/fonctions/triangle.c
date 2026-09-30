#include <stdio.h>
void affiche(int n){
    for(int i=0; i<n*2 ; i++){
        printf("*");
    }
    printf("\n");
    for (int i = n; i>0 ; i-=2){
        printf ("*");
        for (int j = 0 ; j<i; j++){
            printf(" ");
        }
        printf("*\n");
    }
    printf("*");
}

int main (void){
    affiche(4);
}