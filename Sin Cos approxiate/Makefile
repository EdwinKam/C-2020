CFLAGS=-Wall -Wextra -Werror -Wpedantic
CC=clang $(CFLAGS)
all	: math
math	:         math.o
	$(CC) -o math math.o -lm
Math.o	:         math.c
	$(CC) -c math.c
clean	:
	rm -f math math.o
infer    :
	make clean; infer-capture -- make; infer-analyze -- make
