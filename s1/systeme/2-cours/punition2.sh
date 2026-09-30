#!/bin/sh
#
#usage: punition1.sh n word

if [ $# -ne 3 ] ; then
    echo >&2 "usage: $0 <int> <int> <str>"
    exit 1
fi

n="$1"
word="$3"
m = "$2"

i=0
while [ $i -lt "$n" ] ; do
    while [$j -lt "$m"] ; do
        echo -n "$word"
    done
    echo "$word"
    i=$((i+1))
done
