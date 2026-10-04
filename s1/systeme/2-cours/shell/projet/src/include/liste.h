// fichier: liste.h
// auteur:  Marcel dupont

Typedef struct _Tcxl {
    int x,y;
    char data[100];
    struct _Tcxl* next;
} Tcxl;
