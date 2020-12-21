#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//#include "code.h"
//#include "trie.h"
#include "io.h"
#include "word.h"

#define OPTIONS "i:o:v" // define options for switch

uint8_t bit_len(uint16_t);

int main(int argc, char **argv) {

  int input = 0;
  bool vin = false;
  //  bool iin = false;
  //  bool oin = false;
  inbyte = 0;
  outbyte = 0;
  int infile = STDIN_FILENO;
  int outfile = STDOUT_FILENO;
  //  int infile = open("haha.txt", O_RDONLY, 0600);
  //  int outfile = open("baba.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
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
    default:
      printf("Invalid input\n"); // error message
      break;
    }
  }
  FileHeader h = {0, 0};
  read_header(infile, &h);
  if (h.magic != 0x8badbeef) {
    printf("no match magic");
    exit(1);
  }
  fchmod(outfile, h.protection);
  WordTable *table = wt_create();
  uint8_t cur_sym = 0;
  uint16_t cur_code = 0;
  uint16_t next_code = START_CODE;

  while (read_pair(infile, &cur_code, &cur_sym, bit_len(next_code))) {
    table[next_code] = word_append_sym(table[cur_code], cur_sym);
    buffer_word(outfile, table[next_code]);
    next_code = next_code + 1;
    if (next_code == MAX_CODE) {
      wt_reset(table);
      next_code = START_CODE;
    }
  }
  flush_words(outfile);
  wt_delete(table);

  if (vin) { // if -v was entered
    printf("Compressed file size: %d bytes\n", inbyte);
    printf("Uncompressed file size: %d bytes\n", outbyte);
    double x = inbyte;
    double y = outbyte;
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
