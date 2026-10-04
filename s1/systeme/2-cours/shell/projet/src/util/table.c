// fichier: table.c
// auteur:  Pierre Durant

#include "../include/table.h"

int tcx_cmpbonjour(Tcx * t, int i)
{
    return strcmp("bonjour",t[i].datat);
}
