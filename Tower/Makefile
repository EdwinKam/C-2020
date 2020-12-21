CFLAGS=-Wall -Wextra -Werror -Wpedantic
CC=clang $(CFLAGS)
all	: tower
tower	:         tower.o stack.o
	$(CC) -o tower tower.o stack.o
tower.o :	tower.c
	$(CC) -c tower.c
stack.o	:         stack.c
	$(CC) -c stack.c
clean	:
	rm -rf tower tower.o stack.o infer-out
infer    :
	make clean; infer-capture -- make; infer-analyze -- make
