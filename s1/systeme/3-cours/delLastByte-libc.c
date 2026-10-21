#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main (int argc, char*argv[]){
    int i;
    if (argc!=2){
        fprintf(stderr, "%s : Fatal %d mauvais nombres d'args ( 1 attendu)", argv[0], argc);
    return 1;
    }
    
    int fsrc = fopen(argv[1], O_RDONLY);
    if ((fsrc)==-1){
        fprintf (stderr, "%s: Fatal: pb ouverture %s en lecture : %s\n",
            argv[0], argv[1], strerror(errno));
    return 1;
    }

    int size = lseek (fsrc,0, SEEK_END);
    char* tab = malloc((size-1)*sizeof(char));
    lseek(fsrc,0,SEEK_SET);
    read(fsrc,tab,size);
    close(fsrc);

    if ((fsrc=open(argv[2],O_RDWR|O_TRUNC))==-1){
        fprintf (stderr, "%s: Fatal: pb ouverture %s en lecture : %s\n",
            argv[0], argv[1], strerror(errno));
    return 1;
    }
    
    write(fsrc,tab,size-1);

    if (close(fsrc)==-1){
        fprintf (stderr, "%s: Fatal: pb fermeture %s en lecture : %s\n",
            argv[0], argv[1], strerror(errno));
        free(tab);
    return 1;
    } 

    free(tab);
    return 0;
}  
