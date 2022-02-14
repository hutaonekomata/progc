#!/bin/bash

gcc -shared -fPIC -o libtree.so tree.c
gcc $1 -L . -l tree
a.out
