// fichier: liste.c
// auteur:  Marcel dupont

#include "../include/liste.h"

Tcxl* tcxl_next(Tcxl * t)
{
    int z = atoi(t->data);
    return t->next;
}
