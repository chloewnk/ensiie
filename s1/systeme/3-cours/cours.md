# Appel système et libc

Application -> Libc -> Noyau/Hardware \
Appels systèmes plus couteux que la libc

**Appels systèmes** : fonctions basiques sur le noyaux (peu nombreuses)
- syscall : read, write

notion de **wrapper** (appel système indirect)

**Libc** : module standalone, module interface (fread, fwrite) : peu couteux car utilisation d'un buffer\
+ driver quasi dircet (open, read)


Notion d'**espace virtuel**\
**MMU** : traduction de memoire virtuelle à memoire physique\

Gèrer les erreurs : 
```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

if (unAppelSysteme()==-1){
    fprintf (stderr, "%s:Fatal: unappelSysteme fails",%s\n, argv[0],stderr(errno));
return 1;
}
```

fonction perror\
Algorithme lecture / ecriture


## Les flux : 
- stdin, stdout, stderr

ouverture de flux pour lire un fichier
```c
open("f1", O_RDONLY);  /* --> return 2 */
```
```c
size_t read(int fd, void *buf, size_t count);
```
```c
size_t write(int fd, void *buf, size_t count);
```

Se positionner +10 ou -10 octets à la fin du fichier:
```c
pos = lseek(3,+10,SEEK_END);
pos = lseek(3,-10,SEEK_END);
```
mais on ne peut pas reculer de -10octets au début du fichier

Notion de **duplication de descripteurs**

Erreur noyau : -1\
en libc les erreurs sont souvent en null


EN LIBC:
```c
size_t fread(void* buf, size_t sze, size_t nbe, FILE *f);
size_t fwrite(void* buf, size_t sze, size_t nbe, FILE *f);
```

# SIGNAUX 

Un signal est un évenement que l'on peut envoyer à un processus 

**4 comportements :**
- ignorer
- se terminer
- se suspendre
- traitement spécifique

Une table indiquant pour chaque signal le traitement associé puis si il a été reçu ou non. \

- SIGHUP --> term
- SIGINT --> term
- SIGQUIT --> core 
- SIGILL --> core 
- SIGABRT --> core 
- SIGBUS --> core 
- SIGFPE --> core 
- SIGKILL --> term
- SIGSEGV --> core 
- SIGPIPE --> term
- SIGALRM --> term
- SIGTERM --> term
- SIGUSR1/2 --> term
- SIGCHLD --> ign
- SIGSTOP --> stop

SIGSTOP et SIGKILL ne peuvent pas etre ignorés\
**core** : fichier de log qui permet de tracer l'image du processus

```c
kill(getpid(),SIGKILL);
```

### Fixer le gestionnaire d'un signal :
```c
typedef void (*sighandler)(int);
sighandler_t signal (int sig, sighandler_t handler);
```
exemple : 
```c
signal(SIGQINT,SIG_IGN);
```
SIG_DFL : remet le gestionnaire par défaut

### Autres

```c
int pause(void);
unsigned int alarm (unsigned int durée);
useconds_t ualarm (useconds_t duree, );
```

### FIFO

Calculer la taille du pipe : le remplir et voir\
Difference entre pipe et pipe nommé

Pipe non nommé : communiquer des processus qui ont un lien de parenté \
```c
int pipe (int fd[2]);
/**
 * fd[0] : sortie de la FIFO : lecture
 * fd[1] : entrée de la FIFO : écriture
 */
```
Pipe nommé : aucun lien de parenté entre les processus 
```bash
sh > mkfifio path 
# ou
sh > mkfifo path p
```

Notion de socket : lier les extrémités d'un pipe\
Ouverture RO est bloquante si il n'y a pas d'écrivains\
Ouverture WO est bloquante si il n'y a pas de lecteurs


**Spécificité de lecture** 
```c
read(pipefd,buf,n);
```
- si renvoie une valeur postive et inférieure à n sans que l'on soit en fin de flux
- est bloquant si le pipe est vide et qu'il y a des écrivains potentiels
- renvoie ensemble vide si le pipe est vide et qu'il n'y a pas d'écrivains










