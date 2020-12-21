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
  if (!b->vector) {
    return 0;
  }
  return b;
}

void bv_delete(BitVector *v) {
  free(v->vector);
  free(v);
  return;
}

uint32_t bv_get_len(BitVector *v) { return v->length; }

void bv_set_bit(BitVector *v, uint32_t i) {
  v->vector[i >> 3] |= (1 << (i & 7));
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
