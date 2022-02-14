#!/bin/bash

cc -shared -fPIC -o libtree.so tree.c
cc $1 -L . -l tree
a.out
