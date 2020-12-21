CFLAGS=-Wall -Wextra -Werror -Wpedantic -std=c99
CC=clang $(CFLAGS)
all	: hatterspeak
hatterspeak:         hatterspeak.o bf.o ll.o speck.o parser.o bv.o hash.o
	$(CC) -o hatterspeak hatterspeak.o bf.o ll.o speck.o parser.o bv.o hash.o -lm -g
hatterspeak.o:	hatterspeak.c
	$(CC) -c hatterspeak.c
bf.o	:         bf.c
	$(CC) -c bf.c
ll.o	:         ll.c
	$(CC) -c ll.c
speck.o	:         speck.c
	$(CC) -c speck.c
parser.o :         parser.c
	$(CC) -c parser.c
bv.o :         bv.c
	$(CC) -c bv.c
hash.o :         hash.c
	$(CC) -c hash.c
bftest.o :         bftest.c
	$(CC) -c bftest.c
hstest.o :         hstest.c
	$(CC) -c hstest.c
read.o :         read.c
	$(CC) -c read.c
hstest	: hstest.o ll.o hash.o speck.o
	$(CC) -o hstest hstest.o ll.o hash.o speck.o -lm -g
read	: read.o ll.o hash.o speck.o parser.o bv.o bf.o
	$(CC) -o read read.o ll.o hash.o speck.o parser.o bv.o bf.o -lm -g
	
bftest	: bftest.o bf.o bv.o speck.o
	$(CC) -o bftest bftest.o bf.o bv.o speck.o -lm -g
clean	:
	rm -rf hatterspeak hatterspeak.o bf.o ll.o speck.o parser.o bv.o hash.o bftest bftest.o hstest hstest.o read read.o infer-out
valgrind :
	make; valgrind ./hatterspeak -s ;make clean
infer    :
	make clean; infer-capture -- make; infer-analyze -- make
