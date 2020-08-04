# cross=~/opt/gcc/riscv64-linux/7.1.1/bin/riscv64-unknown-linux-gnu-gcc
# cross=~/opt/gcc/riscv64-elf/7.1.1/bin/riscv64-unknown-elf-gcc

ifdef cross
	CPP=cross
else
	CPP=gcc
endif

FLAG=-O3 -static

all: matrix

matrix: matrix_trans.o
	$(CPP) -o bin/matrix obj/matrix_trans.o 

matrix_trans.o: matrix_trans.c
	$(CPP) -c $(FLAG) matrix_trans.c -o obj/matrix_trans.o

clean:; rm -f *.o *~matrix

run:; ./matrix 0
recur_run:; ./matrix 1
block_run:; ./matrix 2
