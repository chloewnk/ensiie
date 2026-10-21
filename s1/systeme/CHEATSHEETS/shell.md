# SHELL SCRIPT

# PREMIERS PAS

```shell
#!/bin/bash
echo -n " " Hello
echo World
```

## executer :

```bash
chmod +x hello.sh 
bash hello.sh
./hello.sh
```

## sourcer un script


# INSTRUCTION
## conditions : 
### if
```bash
if cmd-cond
then
    ...
else 
    ...
fi
```

exemple : 

```bash
if grep -q main file ; then
    echo main dans file
else
    echo pas de main dans file
fi
```

```bash
if grep -q main file 2> /dev/null ; then
    echo main dans file
else
    echo pas de main dans file
    echo ou file non accessible
fi
```

**ou utilisation du && :**

```bash
date | grep -q 2016 && echo oui
```


### case
```bash
case $n in ([0-9] | [0-9][0-9] | [0-9][0-9][0-9]
    good=1 ;; *)
    good=0 ;;
esac
```
elif : 

```bash
if cmd ; then 
...
elif cmd2 ; then
...
elif cmd3 ; then
...
fi
```

## boucles 
### while
```bash
while true ; do 
    sleep
    ping -c 1 192.168.1.10 > /dev/null 2>&1 || echo -e -n "\b\b\b\b"
done
```
### for
```bash
for in str-list
do
    ...
    ...
    ...
done
```

exemple : 

```bash
for i in {1..10} ; do
    for j in {19...15} ; do
        echo -n silence " "
    done
    echo
done
```

```bash
for bn in (cd $dir ; ls); do 
    echo -n "$bn(" $(wc -l < $dir/$bn 2> /dev/null) ")"
done 
echo
```
## comparateurs :

## test sur les fichiers :
```bash
if test -f $f -a -r $f -a -w $f -a ! -x $f ; then
  echo ok
fi
```

### Les arguments : 
**sur un str** :
- -n str : str est non vide
- -z str : est vide

**sur un fichier** :
- -e file : le fichier existe et n'est pas un lien mort
- -f file : fichier existe et est régulier
- -d file : fichier existe et est un repertoir
- -h file : fichier existe et est un lien symobolique
- -r file : fichier existe et peut etre lu
- -w file : fichier existe et peut etre écrit
- -x file : fichier existe et peut etre exécuté



## commande exec & exit :

## commande read : 

## arguments: 

$# nbr d'agument \
$0 le nom de la commande \
$1 le premier argument \
$2 le second argument \
$* liste des arguments séparés par un espace \

exemple : 
```bash
first = 1
for n in $* ; do
  test $first = 0 && echo -n +
  echo -n $n
  first = 0;
done
```

## commande shift : 
--> décale les arguments vers la gauche \
```bash
n=$1
shift
i=0
while test $i -lt $n ; do
  echo $*
  i=$[i+1]
done
```


## commande set
```bash
test $# = 1 && set -- 5 "$1"
i=0
while test $i -lt $1 ; do
    echo $2
    i=$[i+1]
done
```
