CFLAGS=-Wall -Wextra -Werror -Wpedantic
CC=clang $(CFLAGS)
all	: encode decode
encode:         encode.o  word.o io.o trie.o
	$(CC) -o encode encode.o  word.o io.o trie.o -lm -g
decode:			decode.o decode.o word.o io.o trie.o
	$(CC) -o decode decode.o word.o io.o trie.o -lm -g
test:		test.o word.o trie.o io.o
	$(CC) -o test test.o word.o trie.o io.o -lm -g
test.o:		test.c
	$(CC) -c test.c
decode.o:		decode.c
	$(CC) -c decode.c
encode.o:		encode.c
	$(CC) -c encode.c
word.o	:		word.c
	$(CC) -c word.c
trie.o	:		trie.c
	$(CC) -c trie.c
io.o	:		io.c
	$(CC) -c io.c
testen	:
		make; ./encode -i lorem.decode -o haha.txt -v; make clean
testde	:
		make; ./decode -i lorem.encode -o haha.txt -v; make clean
clean	:
	rm -rf encode decode test test.o decode.o encode.o word.o io.o trie.o infer-out
valen :
	make; valgrind ./encode -i encode.decode -o haha.txt -v; make clean
valde :
	make; valgrind ./decode -i encode.encode -o haha.txt -v; make clean
infer    :
	make clean; infer-capture -- make; infer-analyze -- make
