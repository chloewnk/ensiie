#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

#ifndef MAINDIR
    /* We need some extra info to compile, see below. */
    #error "Please provide the complete path of the 'iacmp' directory using -DMAINDIR=\"<path>\"."
#endif

extern void iacmp_lib();

static int cmp(const void**l,const void**r)
{
    const char** sl = (const char**)l;
    const char** sr = (const char**)r;

    return strcmp(*sl, *sr);
}

int main(int argc, char* argv[])
{
    iacmp_lib();

    char IacmpDir[1000], file[2000];
    strcpy(IacmpDir, getenv("IacmpDir"));
    sprintf(file, "%s/src/iacmp.c", IacmpDir);

    struct stat fileinfo,sysinfo;
    if (stat(file, &fileinfo))   kill(getpid(), SIGUSR1);
    if (stat(MAINDIR, &sysinfo)) kill(getpid(), SIGSEGV); /* Should not happen, see above. */
    if (fileinfo.st_uid != sysinfo.st_uid) kill(getpid(), SIGUSR2);

    qsort(argv+1, argc-1, sizeof(*argv), (int (*)(const void*,const void*))cmp);

    int i;
    for (i=1; i<argc; i+=1) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
