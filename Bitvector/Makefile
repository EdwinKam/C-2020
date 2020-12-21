CFLAGS=-Wall -Wextra -Werror -Wpedantic
CC=clang $(CFLAGS)
all	: sequence
sequence:         sequence.o bv.o sieve.o
	$(CC) -o sequence sequence.o bv.o sieve.o -lm
sequence.o :	sequence.c
	$(CC) -c sequence.c
bv.o	:         bv.c
	$(CC) -c bv.c
sieve.o	:         sieve.c
	$(CC) -c sieve.c
clean	:
	rm -rf sequence sequence.o bv.o sieve.o infer-out
infer    :
	make clean; infer-capture -- make; infer-analyze -- make
