#include "bf.h"
#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTIONS "Absqip:r:n:" // define options for switch

int main(void) {
  BloomFilter *b = bf_create(20);
  printf("before insert probe:%d  (should be 0)\n", bf_probe(b, "hihi"));
  bv_print_bits(b->filter);
  // printf("set all bit\n");
  // bv_set_all_bits(b->filter);
  // bv_print_bits(b->filter);
  bf_insert(b, "hihi");
  bf_insert(b, "what the hell");
  printf("after insert probe:%d   (should be 1)\n",
         bf_probe(b, "what the hell"));
  bv_print_bits(b->filter);
  bf_delete(b);
  return 0;
}
