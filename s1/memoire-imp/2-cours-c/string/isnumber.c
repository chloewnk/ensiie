#include <stdio.h>
#include <string.h>
#include <ctype.h>


void check (char s[]){
    printf("%c",s[0]);
    if(isdigit(s[0])){
        printf("c'est un nb\n");
    } else {
        printf("c'est pas un nb");
    }
}


int main(void){
    check("13");
    check("caca");
}