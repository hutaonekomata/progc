#!/bin/bash

cc -shared -fPIC -o liblist_rec.so list_rec.c
cc $1 -L . -l list_rec
a.out
