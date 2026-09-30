#include <stdio.h>
#include <string.h>

void chaine(char s[]){
    int n = strlen(s);
    for (int i = 0 ; i<n ; i++){
        printf("%c\n",s[i]);
    }
}

void autrechaine(char s[]){
    int i = 0;
    while(s[i]!='\0'){
       printf("%c\n",s[i]); 
       i++;
    }
}

int main(void){
    chaine("hello");
    chaine("world");
}