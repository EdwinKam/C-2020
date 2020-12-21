#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include "code.h"
#include "io.h"
#include "trie.h"

#define OPTIONS "i:o:v" // define options for switch

uint8_t bit_len(uint16_t);

int main(int argc, char **argv) {
  int input = 0;
  bool vin = false;
  //  bool iin = false;
  // bool oin = false;
  inbyte = 0;
  outbyte = 0;
  int infile = STDIN_FILENO;
  int outfile = STDOUT_FILENO;

  while ((input = getopt(argc, argv, OPTIONS)) != -1) {
    switch (input) {
    case 'v':
      vin = true; // if -v input vin=true, print stat later
      break;
    case 'i':
      infile = open(optarg, O_RDONLY);
      break;
    case 'o':
      outfile = open(optarg, O_WRONLY | O_CREAT | O_TRUNC, 0600);
      break;
    case ':': // if user didnt input a desire size
      break;
    default:
      printf("Invalid input\n"); // error message
      break;
    }
  }
  FileHeader h = {0, 0};
  h.magic = 0x8badbeef;
  struct stat header_p;
  fstat(infile, &header_p);
  h.protection = header_p.st_mode;
  fchmod(outfile, h.protection);
  write_header(outfile, &h);

  // encoding
  TrieNode *root = trie_create();
  TrieNode *cur_node = root;
  TrieNode *prev_node = NULL;
  uint8_t cur_sym = 0;
  uint8_t prev_sym = 0;
  uint16_t next_code = START_CODE;
  // int symcount=0;
  //    printf("try bulen: %d\n",bit_len(5000));
  while (read_sym(infile, &cur_sym)) { // read one sym at a time, but first
                                       // timee call this function it will load
                                       // the whole block
    // in bytebuf
    TrieNode *next_node = trie_step(cur_node, cur_sym);
    // printf("encode.c symcount: %d\n",symcount++);
    if (next_node != NULL) {
      prev_node = cur_node;
      cur_node = next_node;
    } else {
      //      printf("passed in next code: %d cur_code->code: %d",
      //      next_code,cur_node->code);
      buffer_pair(outfile, cur_node->code, cur_sym,
                  bit_len(next_code)); // write the current sym in buf pair
      cur_node->children[cur_sym] = trie_node_create(next_code);
      cur_node = root;
      next_code = next_code + 1;
    }
    if (next_code == MAX_CODE) {
      trie_reset(root);
      cur_node = root;
      next_code = START_CODE;
    }
    prev_sym = cur_sym;
  }
  // print_buffer();
  if (cur_node != root) {
    buffer_pair(outfile, prev_node->code, prev_sym, bit_len(next_code));
    next_code = (next_code + 1) % MAX_CODE;
  }
  buffer_pair(outfile, STOP_CODE, 0, bit_len(next_code));
  flush_pairs(outfile);
  trie_delete(root);
  if (vin) {
    printf("Compressed file size: %d bytes\n", outbyte);
    printf("Uncompressed file size: %d bytes\n", inbyte);
    double y = inbyte;
    double x = outbyte;
    printf("Compression ratio: %.2f%%\n", 100 * (1 - x / y));
  }
  close(infile);
  close(outfile);
  return 0;
}

uint8_t bit_len(uint16_t num) {
  uint8_t len = 0;
  for (int i = 15; i >= 0; i--) {
    if ((num & (1 << i)) == 0) {
      len++;
    } else {
      return 16 - len;
    }
  }
  return 16 - len;
}
