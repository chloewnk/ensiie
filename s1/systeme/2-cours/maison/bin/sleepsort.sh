#!/bin/bash

sleepsort() {
    for arg in $@ ; do
        $k = $#
        for i in $arg ; do 
            { sleep $i ; echo $i ; }
        done
        for i in k ; do 
            wait
        done
    done
}