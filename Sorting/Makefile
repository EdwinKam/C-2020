CFLAGS=-Wall -Wextra -Werror -Wpedantic -std=c99
CC=clang $(CFLAGS)
all	: sorting
sorting:         sorting.o bubble.o quick.o shell.o binary.o array.o
	$(CC) -o sorting sorting.o bubble.o quick.o shell.o binary.o array.o -lm
sorting.o:	sorting.c
	$(CC) -c sorting.c
bubble.o	:         bubble.c
	$(CC) -c bubble.c
quick.o	:         quick.c
	$(CC) -c quick.c
shell.o	:         shell.c
	$(CC) -c shell.c
binary.o :         binary.c
	$(CC) -c binary.c
array.o :         array.c
	$(CC) -c array.c
clean	:
	rm -rf sorting sorting.o bubble.o quick.o shell.o binary.o array.o infer-out
valgrind :
	make; valgrind ./sorting -A ;make clean
infer    :
	make clean; infer-capture -- make; infer-analyze -- make
