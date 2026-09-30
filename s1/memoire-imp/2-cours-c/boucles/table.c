#include <stdio.h>
int main(void){
    int m;
    printf("table : ");
    scanf("%d",&m);
    for (int i = 0 ; i <= 10 ; i++){
        int res = i*m;
        printf ("%d\n", res);
    }
}