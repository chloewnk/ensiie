~/D/c/e/s/s/tp1 ❯❯❯ mkdir bin
~/D/c/e/s/s/tp1 ❯❯❯ cp -v /bin/ls ~/bin/myls
'/bin/ls' -> '/home/chloe/bin/myls'
cp: cannot create regular file '/home/chloe/bin/myls': No such file or directory
~/D/c/e/s/s/tp1 ❯❯❯ cp -v /bin/ls bin/myls                   ✘ 1 
'/bin/ls' -> 'bin/myls'
~/D/c/e/s/s/tp1 ❯❯❯ cp -v /bin/cat bin/mycat
'/bin/cat' -> 'bin/mycat'


~/D/c/e/s/sy
Manage pages
Previous
Next
Zoom Out
Zoom In
Comment
Add signature
Highlight
Text
Draw
Add or edit images
Print
Save
Tools
Le symbole ! permet ici d’inverser la sélection, et donc d’appliquer l’action d à toutes les lignes
ne contenant pas le mot Alice.
Une solution alternative pour la question précédente est d’utiliser la commande
sh$ sed -n -e /Alice/p /pub/FISE_OSSE11/shell/select.dat
où l’action p signifie print, et où on a utilisé l’option -n de sed pour ne pas afficher les lignes
qui n’ont pas été sélectionnées (cf man).
g. Affichez le contenu du fichier
/pub/FISE_OSSE11/shell/select.dat, mais en remplaçant Alice par Anne.
sh$ sed -e 's/Alice/Anne/g' /pub/FISE_OSSE11/shell/select.dat
Ici, l’action de sed est s pour substitute. Sa syntaxe est
s/motif1/motif2/options
et elle a pour but de remplacer le motif motif1 par motif2.
Par défaut, seule la première occurrence de motif1 de chaque ligne est remplacée. Nous avons
donc utilisé l’option g (global) pour remplacer toutes les occurrences de chaque ligne.
h. Affichez le contenu du fichier /pub/FISE_OSSE11/shell/select.dat, mais en remplaçant la
date du 01/08/2001 par 03/08/2001.
sh$ sed -e 's,01/08/2001,03/08/2001,' /pub/FISE_OSSE11/shell/select.dat
Comme nos motifs contiennent le symbole /, nous avons utilisé le symbole , comme séparateur
entre les différents éléments de syntaxe pour s. On peut en fait utiliser le caractère que l’on
veut comme séparateur, les choix les plus courants étant /, , et |.
i. Affichez la première colonne de /pub/FISE_OSSE11/shell/select.dat.
sh$ sed -e 's/\t.*//' /pub/FISE_OSSE11/shell/select.dat
Les motifs peuvent contenir des caractères spéciaux. Ici, \t désigne le symbole de tabulation,
le . est un joker pour désigner n’importe quel caractère (sauf un saut de ligne), et * signifie de
répéter le motif associé (ici .) un nombre quelconque (potentiellement nul) de fois. Ainsi, .*
nous permet de désigner une suite quelconque de caractères.
On notera que sed va toujours considérer le motif le plus grand possible. Ici, le \t considéré
sera le premier d’une ligne, de sorte que le motif complet couvrira les deux dernières colonnes.
j. Affichez la troisième colonne de /pub/FISE_OSSE11/shell/select.dat.
sh$ sed -e 's/[^\t]*\t[^\t]*\t\([^\t]*\)/\1/'
/pub/FISE_OSSE11/shell/select.dat
Ici, [^\t] correspond à tout caractère sauf le symbole de tabulation (et un saut de ligne). Le
contenu d’un colonne est donc désigné par [^\t]*.
L’utilisation de \( et \) permet d’affecter un indice i au contenu entre parenthèses. Il est
possible d’utiliser ce contenu pour le motif cible via \i.
k. Affichez la première et la troisième colonne du fichier /pub/FISE_OSSE11/shell/select.dat.
sh$ sed -e 's/\([^\t]*\)\t[^\t]*\t\([^\t]*\)/\1\t\2/'
/pub/FISE_OSSE11/shell/select.dat
l. Échangez la première et la troisième colonne du fichier.
sh$ sed -e 's/\([^\t]*\)\t[^\t]*\t\([^\t]*\)/\2\t\1/'
/pub/FISE_OSSE11/shell/select.dat
m. La commande sed est un outil très utile en pratique. Les personnes curieuses pourront consulter
le site https://www.grymoire.com/Unix/Sed.html , qui présente de nombreux autres usages
de cette commande.
5. À vous de jouer :
10
a. Donnez la première ligne du fichier /pub/FISE_OSSE11/shell/select.dat qui contient le mot
Alice en utilisant grep et head.
b. Donnez la première ligne du fichier /pub/FISE_OSSE11/shell/select.dat qui contient le mot
Alice en utilisant sed et éventuellement head.
note : L’action q (pour quit) de sed permet d’arrêter le traitement en cours.
c. Donnez la destination de la première ligne qui contient Alice en utilisant grep, head et cut.
d. Donnez la destination de la première ligne qui contient Alice en utilisant sed et head.
e. Donnez la destination de la dernière ligne qui contient Alice.
11
Exercice 9 - wc, stat
L’objectif de cet exercice est de mettre dans la variable sz la taille du fichier
/pub/FISE_OSSE11/shell/gen-projet.sh. Nous proposons ici deux approches différentes.
1. Utilisation de l’option -c de la commande wc :
a. Donnez la taille en octet de /pub/FISE_OSSE11/shell/gen-projet.sh.
sh$ wc -c /pub/FISE_OSSE11/shell/gen-projet.sh
La commande écrit le nom du fichier, ce qui oblige à le supprimer avec une autre commande
(sed ou cut).
b. Donnez uniquement la taille en octet du fichier /pub/FISE_OSSE11/shell/gen-projet.sh.
sh$ wc -c < /pub/FISE_OSSE11/shell/gen-projet.sh
c. Définissez la variable sz avec la bonne valeur.
sh$ sz=$(wc -c < /pub/FISE_OSSE11/shell/gen-projet.sh)
sh$ echo "sz = $sz"
Cette approche a un inconvénient majeur. La commande wc va lire et compter les caractères du
fichier un par un. Sur un fichier de grande taille, le surcoût engendré n’est tout simplement pas
acceptable.
2. Utilisation de la commande stat :
a. Une approche plus efficace est de récupérer directement les informations relative à notre fichier à
l’aide de la commande stat. On peut préciser le format de sortie grâce à l’option -c <format>.
Comme seule la taille nous intéresse ici, on va utiliser %s comme format.
sh$ sz=$(stat -c '%s' /pub/FISE_OSSE11/shell/gen-projet.sh)
sh$ echo "sz = $sz"
b. Consultez le man de stat et inspirez vous de ce qui précède pour obtenir la taille réellement
utilisée sur le disque.
aide :
— Ouvrir le man avec sh$ man stat
— Tapez /size<ENTER> (la touche / étant le raccourci pour passer en mode recherche).
— La touche n permesteme ❯❯❯ echo $(( $(cat tp1/expr-arith.dat) )) 
100
~/D/c/e/s/systeme ❯❯❯ echo "( $(cat tp1/expr-arith.dat) ) * $(cat tp1/expr-arith.dat) )" > tp1/tmp/expr1
~/D/c/e/s/systeme ❯❯❯ echo $(( $(cat tp1/tmp/expr1) )) 
zsh: bad math expression: unexpected ')'
~/D/c/e/s/systeme ❯❯❯ echo $(( $(cat tp1/tmp/expr1) ))               ✘ 1 
10000
~/D/c/e/s/systeme ❯❯❯ 



~/D/c/e/s/systeme ❯❯❯ x="($(cat tp1/expr-arith.dat))" 
~/D/c/e/s/systeme ❯❯❯ echo $x \* $x \* $x > tp1/tmp/expr2            ✘ 1 
~/D/c/e/s/systeme ❯❯❯ echo $(( $(cat tp1/tmp/expr2) ))    
1000000
~/D/c/e/s/systeme ❯❯❯ 


~/D/c/e/s/systeme ❯❯❯ sed -e "$((nb-1)),\$d" tp1/select.dat 
Joe 10/12/1990  Strasbourg
Alice   05/03/1998  Nantes
Joe 10/12/1990  Strasbourg
~/D/c/e/s/systeme ❯❯❯ sed -e '/Alice/!d' tp1/select.dat
Alice   05/03/1998  Nantes
Alice   05/03/1998  Nantes
Alice   05/03/1998  Nantes%                                               ~/D/c/e/s/systeme ❯❯❯ sed -e '/Alice/d' tp1/select.dat 
Joe 10/12/1990  Strasbourg
Joe 10/12/1990  Strasbourg
Joe 10/12/1990  Strasbourg
~/D/c/e/s/systeme ❯❯❯ 

~/D/c/e/s/systeme ❯❯❯ sed -e 's,05/03/1998,20/04/1999,' tp1/select.dat
Joe 10/12/1990  Strasbourg
Alice   20/04/1999  Nantes
Joe 10/12/1990  Strasbourg
Alice   20/04/1999  Nantes
Joe 10/12/1990  Strasbourg
Alice   20/04/1999  Nantes%                                               ~/D/c/e/s/systeme ❯❯❯ 


~/D/c/e/s/systeme ❯❯❯ sort tp1/unsort.dat | uniq               
aaa 02 il fait chaud
eee 04 il fait trop beau
mmm 03 il fait trop chaud
mmm 05 il fait trop chaud
zzz 01 il fait beau


rm -d
find /dossier/ -type f -user christophe.mouilleron -exec du -ch + | tail -n 1




