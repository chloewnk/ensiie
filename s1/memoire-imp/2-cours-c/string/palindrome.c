#include <stdio.h>
#include <string.h>

/*
dans le calcul de strlen le \0 ne compte pas 
mais il s'affichera quand on essaiera d'acceder à la case
*/

int palindrome(char p[0]){
    int taille = strlen(p);
    int count = 0;
    printf("%d\n",taille);
    for (int i = 0 ; i<taille ; i++){
        printf("%c",p[i]);
        printf("%c\n",p[taille-i-1]);
        if(p[i]==p[taille-i-1]){ 
            count ++;
        }
    }
    if (count==taille){
        printf("c'est un palindrome\n\n");
        return 1;
    }
    return 0;
}

void chaines (char s[], char p[]){
    int taille = strlen(s);
    for (int i = 0 ; i<=taille; i++){
        p[i]=s[i];
    }
    for (int i = 0 ; i<=taille ; i++){
        p[i+taille]=s[taille-1-i];
    }
    printf("%s",p);
    palindrome(p);
}

int main (void){
    palindrome("kayak");
    char p[100];
    chaines("bisous",p);
}