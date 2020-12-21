#ifndef NIL
#define NIL (void *)0
#endif

#ifndef __BF_H__
#define __BF_H__
// 2020 Darrell Long 1

#include "bv.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BloomFilter {
  uint64_t primary[2];
  uint64_t secondary[2];
  uint64_t tertiary[2];
  BitVector *filter;
  uint32_t bf_size;
} BloomFilter;

BloomFilter *bf_create(uint32_t size);

void bf_delete(BloomFilter *bf);
// destructor ofbloom filter

void bf_insert(BloomFilter *bf, char *key);
// inset the new key

bool bf_probe(BloomFilter *bf, char *key);
// determine whether this key is in the bloom filter

void bf_print(BloomFilter *bf);

#endif
