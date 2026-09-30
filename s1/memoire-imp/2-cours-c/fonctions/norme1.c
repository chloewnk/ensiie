#include <stdio.h>

void affiche(int n){
    int res=n*2+1;
    for (int j = 0 ; j<=res ; j+=2 ){
        for (int i = 1 ; i<j ; i++ ){
            printf("*");
        }
        printf("\n");
    }
    for (int j = res ; j<=0 ; j-=2 ){
        for (int i = 1 ; i<j ; i++ ){
            printf("*");
        }
        printf("\n");
    }
    
    
}

int main (void){
    affiche(3);
}
