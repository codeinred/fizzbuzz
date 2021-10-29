#!/bin/bash

cd "$(dirname "$0")"

mkdir -p build && cd build 
gcc -mavx2 -c ../fizzbuzz.S
ld -o fizzbuzz-asm fizzbuzz.o
