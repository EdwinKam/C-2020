#include "bf.h"
#include "speck.h"

//
//
//
//
//
BloomFilter *bf_create(uint32_t size) {
  BloomFilter *bf = (BloomFilter *)malloc(sizeof(BloomFilter));
  if (bf) {
    bf->primary[0] = 0xfc28ca6885711cf7;
    bf->primary[1] = 0x2841af568222f773;
    bf->secondary[0] = 0x85ae998311115ae3;
    bf->secondary[1] = 0xb6fac2ae33a40089;
    bf->tertiary[0] = 0xd37b01df0ae8f8d0;
    bf->tertiary[1] = 0x911d454886ca7cf7;
    bf->filter = bv_create(size);
    bf->bf_size = size;
    return bf;
  }
  return (BloomFilter *)NIL;
}

void bf_delete(BloomFilter *bf) {
  bv_delete(bf->filter);
  free(bf);
}

void bf_insert(BloomFilter *bf, char *key) {

  if (bf_probe(bf, key)) {
    return; // check if this key is properly inserted
  }
  uint32_t index1 = hash(bf->primary, key) % bf->bf_size;
  uint32_t index2 = hash(bf->secondary, key) % bf->bf_size;
  uint32_t index3 =
      hash(bf->tertiary, key) % bf->bf_size; // find the hash value first

  bv_set_bit(bf->filter, index1);
  bv_set_bit(bf->filter, index2);
  bv_set_bit(bf->filter, index3);
}

bool bf_probe(BloomFilter *bf, char *key) {
  // find the hash value first
  uint32_t index1 = hash(bf->primary, key) % bf->bf_size;
  uint32_t index2 = hash(bf->secondary, key) % bf->bf_size;
  uint32_t index3 = hash(bf->tertiary, key) % bf->bf_size;

  if (!bv_get_bit(bf->filter, index1)) { // return false if this bit is not set
    return false;
  }
  if (!bv_get_bit(bf->filter, index2)) {
    return false;
  }
  if (!bv_get_bit(bf->filter, index3)) {
    return false;
  }
  return true; // return true if all 3 bits are set
}

void bf_print(BloomFilter *bf) {
  printf("Bloom filter--------------\n");
  bv_print_bits(bf->filter);
  printf("Bloom filter ends--------------\n");
}
