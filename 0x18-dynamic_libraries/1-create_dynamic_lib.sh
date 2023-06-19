#!/bin/bash
gcc -wall -waxtra -werror -pedantic -c -fpic *.c
gcc -shared -o liball *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
