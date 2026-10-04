// fichier: main-util.h
// auteur:  Patrice Burger

typedef struct _Targs {
    int x,y;
    char data[100];
} Targs;

Targs* main_cmdline(int argc,char*argv[]);

