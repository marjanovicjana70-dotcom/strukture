#!/bin/bash
make
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/strukture
gcc -Iinc nesto.c -L. -lstruct -Wall -o nesto

