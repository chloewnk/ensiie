// fichier: data-in.c
// auteur:  Patrice Burger

#include "../include/table.h"
#include "../include/data.h"

Tdata* dt_create(char *name)
{
    if ( strcmp("bonjour",name) == 0 )
        return dt_create_bonj();
    if ( strcmp("hello",name) == 0 )
        return dt_create_hello();
    return 0;
}
