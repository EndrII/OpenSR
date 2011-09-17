#!/bin/bash

# apply coding style to all c, cpp and header files in and below the current directory 

OPTS="--style=allman -w -p -U -H --mode=c"
astyle ${OPTS} $(find . -regex ".*\.\(c\|cpp\|h\)$")
