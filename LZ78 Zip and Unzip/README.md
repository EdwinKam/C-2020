# Encode Decode
- pipeline passed
- I compared my outfile and encode.encode and there is only one byte off in the header. 
- However, I am able to compress a file and decompress it to get the original file back
- This program can compress a file to smaller smaller size by using the LZ78 method.
- Encoode.c will compress the file and deocde.c willde compress the file
- For encode.c/decode.c, we can use argc to indicate the infile and outfile
- if no file is inputed in opt, we wil take input from stdin

# Makefile
- make or make all will compile both enocde.c and decode.c, the exec files will be named the same as the mc files
- make clean will clear all .o and exec files
- make infer are also supported
- make valen/valde can run valgrind for encode and decode
- removed -std C99

# infer
- two resource leaks error message saying I did not call close() after I called open(), however, I did call close() at the end of my program
- instead, I have a delete function for both so there so no memory leaks

# valgrind
- no memory leaks

# Design
- Since my design.txt is too large, I seprated them into two pdfs

