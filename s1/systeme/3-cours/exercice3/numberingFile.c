#include <stdio.h>

int main(int argc, char* argv[]) {
    char c;
    int n = 1;
    int debut = 1;

    FILE* in = fopen(argv[1],"r");
    if(in==NULL){
        fprintf(stderr, "impossible d'ouvrir\n");
        fclose(in);
    }

    FILE* out = fopen("result.txt","w");
    if(out==NULL){
        fprintf(stderr, "impossible d'ouvrir\n");
        fclose(out);
    }

    while (fread(&c, 1, 1, in) == 1) {
        if (debut) {
            fprintf(out, "%d\t", n++);
            debut = 0;
        }
        fprintf(out, "%c", c);
        if (c == '\n')
            debut = 1;
    }

    fclose(in);
    fclose(out);

    return 0;
}