#!/bin/sh

s3s() {

    if [ $# -lt 3 ] ; then
        echo "Usage str1 str2 str3"
        return 1
    fi

    printf '%s\n' "$@"  | sort

}


s3e() {

    if [ $# -lt 3 ] ; then
        echo "Usage str1 str2 str3"
        return 1
    fi

    printf '%s\n' "$@"  | sort -n

}

s3f (){

    if [ $# -lt 3 ] ; then
        echo "Usage str1 str2 str3"
        return 1
    fi

    if [ $(test -f $@) -eq 1 ] ; then 
        echo "doit etre un fichier"
    fi



}

