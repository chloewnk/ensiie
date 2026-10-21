#include <stdio.h>

int main(void) {
    char c;
    int n = 1;
    int debut = 1;

    while (fread(&c, 1, 1, stdin) == 1) {
        if (debut) {
            fprintf(stdout, "%d\t", n++);
            debut = 0;
        }
        fprintf(stdout, "%c", c);
        if (c == '\n')
            debut = 1;
    }

    return 0;
}