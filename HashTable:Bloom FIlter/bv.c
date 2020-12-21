//
//  bv.c
//  a4
//
//  Created by Edwin on 10/28/20.
//

#include "bv.h"
#include <stdlib.h>
BitVector *bv_create(uint32_t bit_len) {

  BitVector *b = (BitVector *)malloc(sizeof(BitVector));
  if (!b) {
    return 0;
  }
  if (bit_len < 1) {
    b->length = 1;
  }
  b->length = bit_len;
  b->vector = (uint8_t *)malloc(bit_len / 8 + 1);
  b->occupied = 0;
  if (!b->vector) {
    return 0;
  }
  bv_clr_all_bits(b);
  return b;
}

void bv_delete(BitVector *v) {
  free(v->vector);
  free(v);
  return;
}

uint32_t bv_get_len(BitVector *v) { return v->length; }

void bv_set_bit(BitVector *v, uint32_t i) {
  uint8_t save = v->vector[i >> 3];
  v->vector[i >> 3] |= (1 << (i & 7));
  if (save != v->vector[i >> 3]) { // if the value of this index changes, it
                                   // means one more bit was set
    v->occupied++;
  }
  // i&7 to get how many we need to shift
  // since we shift 1
  // then we will be shifting something like 000010000
}

void bv_clr_bit(BitVector *v, uint32_t i) {
  v->vector[i >> 3] &= (~(1 << (i & 7))); // i&7 to get how many we need to
                                          // shift
  // use not operator get get something like 111011111
}

uint8_t bv_get_bit(BitVector *v, uint32_t i) {
  return v->vector[i >> 3] & (1 << (i & 7));
}

void bv_set_all_bits(BitVector *v) {
  for (uint32_t i = 0; i < v->length / 8 + 1; i++) {
    v->vector[i] |= 255; // binary 11111111
  }
}

void bv_clr_all_bits(BitVector *v) {
  for (uint32_t i = 0; i < v->length / 8 + 1; i++) {
    v->vector[i] &= 0; // binary 00000000
  }
}

void bv_print_bits(BitVector *v) {
  printf("row 0: ");
  for (uint32_t i = 0; i < v->length; i++) {
    if (bv_get_bit(v, i)) {
      printf("1");
    } else {
      printf("0");
    }
    if ((i + 1) % 8 == 0) {
      printf("|\nrow %d: ", i / 8 + 1);
    }
  }
  printf("\n");
}
