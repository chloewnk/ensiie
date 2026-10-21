#!/bin/sh

pidfile() {
    stat -c %U * | wc -l
    
}