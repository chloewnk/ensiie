# SHELL SCRIPT

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

## conditions : 

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

ou utilisation du && :

```bash
date | grep -q 2016 && echo oui
```


case : 

```bash
case $n in ([0-9] | [0-9][0-9] | [0-9][0-9][0-9]
    good=1 ;; *)
    good=0 ;;
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

```bash
forv in str-list
do
    ...
    ...
    ...
done
```

exemple : 

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
