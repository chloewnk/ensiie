#!/bin/sh

if [ $# -eq 0 ] ; then   
    n=10
    m=3
    w='Je ne bavarde pas en cours!'
elif [ $# -eq 1 ] ; then 
    n=10
    m=3
    w="$3"
elif [ $# -eq 3 ] ; then
  n="$1"
  m="$2"
  w="$3"
fi

sh punition3.sh "$n" "$m" "$w"

