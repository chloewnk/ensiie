## cd
Retourne au dossier précédent : 
```shell
cd -
```
Exécute dans un sous-shell
```shell
(cd ; ls)
```
## xterm
Ouvre un nouveau terminal
```shell
xterm -name A &
```

## tar
-c : créer\
-x : extraire\
-t : lister\
-f : nom de l'archive\
-C dir : change vers le dossier destination

```shell
tar -cvf /tmp/projet.tar projet
tar -tf /tmp/projet.tar
tar -C /tmp -xf /tmp/projet.tar 
```

## echo
-n pas de saut de ligne

## cut
Extraire des colonnes / champs de chaque ligne\
-f N,M : selectionne les champs N,M\
-d 'c' : définit le délimiteur\

```shell
cut -f 3 file.dat
cut -f 1,3 file.dat
cut -d ':' -f 4 /etc/passwd
```

## head / tail
Affiche le début ou la fin d'un fichier\
-n N : spécifie le nomre N de lignes
```shell
head -n 2 file.dat
tail -n 2 file.dat
```

## wc
Compte les lignes, mots ou octets\
-l : nombre de lignes\
-c : nomre d'octets
```shell
wc -l file.txt
```

## sort
Trie les lignes de texte\
-u : supprime aussi les doublons\
-k N : trie selon la colonne N

## uniq 
Filtre les lignes adjacentes identiques
```shell
sort file | uniq
```

## grep
-e motif\
-w : mot entier\
-l : affiche uniquement le nom des fichiers\
-n : affiche le numéro de ligne\
-q : mode silencieux
```shell
grep -e "Alice" file.dat
grep -w -l -e "strcmp" *.c
grep -n -e "main" main.c
```

## sed
Editeur de flux de texte\
avec -e :
- 1,3 : supprimer les lignes 1 à 3
- /motif/d : supprime les lignes avec motif
- /motif/!d : ne garde que les lignes avec motif
- s/m1/m2/g : substitue m1 par m2\
-i : modification directe "in place" dans le fichier\
-n + p : n'imprime que les lignes selectionnées
```shell
sed -e '1,3d' file ##(supprime L1-3)
sed -e 's/Alice/Anne/g' file
sed -i -e 's/dupont/Dupont/g' file
sed -e 's/ .*//' file ##(garde col 1)
```


## find 
-type f / d : fichier régulier / dossier\
-name '*.c' : motif sur le nom\
-iname\
-size +10k / -100c : taille>10ko / <100octets\
-exec cmd{} \; : execute cmd sur chaque résultat
```shell
find . -type f -name '*.c'
find . -type f -size +10k
find . -type f -exec grep -l "foo" {} \;
```

## stat
Affiche les métadonnées d'un fichier / fs\
-c '%s' : taille exacte en cotets\
-c '%U' : nom du propriétaire\

## stty
Configuration des paramètres du terminal\
erase key : change la touche d'effacement\
eof key : change la touche EOF\
-echo/ echo : désactive/ active l'affichage clavier\
```shell
stty erase m
stty -echo
```

