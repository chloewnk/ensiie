## Organisation 
- materiel
- moniteur --> dans la ROM pour charger le systeme d'exploitation
- noyau
- systeme --> shell : interpréteur de commandes
- app

## Système
UID : id utilisateur
GID : id groupe
```bash
$id
```
Notion de droits d'accès

5: w
4 : r
1 : x


~ ❯❯❯ 
sudo ls /                                                                                                                                                            via 🌙 v5.5.1 
bin  boot  dev	etc  home  lib	lib64  lost+found  mnt	opt  proc  root  run  sbin  srv  sys  tmp  usr	var
~ ❯❯❯     

## Type de fichiers

- repertoire
- régulier
- spéciaux : /dev/sda, FIFO, /dev/tty0, /dev/null
- lien

chemin absolu : à partir de la racine
<br>
chemin relatif : à partir du répertoire courant

## Processus

PID : entité d'execution
Organisés en arbre,, groupés en session avec un groupe (+leader)
Code, données, pile
Tableau de chaines de caractères
Variable d'environnement : LANG, HOME, PATH
Flux d'entrée / sortie
Statut 

## SHELL
- Shell interactif
- Shell script
 
$ sh
& --> en arrière plan

### Shell interactif

() -> lance les commandes dans un autre shell
{} -> réunit des commandes

Expressions régulières 

export [...] : définir une variable d'environnement local

Principales expensions : $vname $$ $? !n !str $[ expr ] $(( expr )) ' '