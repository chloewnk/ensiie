#!/bin/sh
#
#usage: punition1.sh n word

if [ $# -ne 3 ] ; then
    echo >&2 "usage: $0 <int> <int> <str>"
    exit 1
fi

#n lignes de m fois le mot work séparé par un espace

n="$1"
m="$2"
word="$3"


i=0
while [ $i -lt "$n" ] ; do
    j=0
    while [ $j -lt "$m" ] ; do 
        echo -n "$word "
        j=$((j+1))
    done
    echo ""
    i=$((i+1))
done

