#!/bin/bash

for ((i=0 ; i<10 ; i++)) do
	echo $i
done


./matrix 2 16384 16384 9 64
./matrix 2 16384 16384 9 128
./matrix 2 16384 16384 9 256
./matrix 2 16384 16384 9 512
./matrix 2 16384 16384 9 1024
./matrix 2 16384 16384 9 2048
./matrix 2 16384 16384 9 4096
