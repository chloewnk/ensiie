#include <stdio.h>
#include <string.h>


void change(char s[], char c[], char t[]) {
    int sizeS = strlen(s);
    int sizeC = strlen(c);
    int sizeT = strlen(t);

    for (int i = 0; i<sizeS ; i++) {
        c[sizeC + i] = s[i];
    }

    int tailleSC = sizeS + sizeC;

    for (int i = 0; i<sizeT ; i++) {
        c[tailleSC + i] = t[i];
    }

    c[tailleSC + sizeT] = '\0';
}


void multiply(char s[], char c[], int n){
    for (int i = 0; i<n ; i++){
        change(s,c,"");
    }
    
}


int main(void) {
    char c[100] = "hello";

    change("world", c, "test");
    printf("%s\n", c);

    char c1[100] = "hahahha";
    multiply("world",c1,4);
    printf("%s\n",c1);
    return 0;
}