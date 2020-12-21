//
//  sieve.c
//  a4
//
//  Created by Edwin on 10/28/20.
//

#include "sieve.h"
#include "math.h"
#include "stdint.h"
#include "stdio.h"
void sieve(BitVector *v) {
  bv_set_all_bits(v);
  bv_clr_bit(v, 0);
  bv_clr_bit(v, 1);
  bv_set_bit(v, 2);
  for (uint32_t i = 2; i < sqrtl(bv_get_len(v)); i += 1) {
    // prime means bit is set
    if (bv_get_bit(v, i)) {
      for (uint32_t k = 0; (k + i) * i <= bv_get_len(v); k += 1) {
        // printf("%d not prime k%d i%d\n",(k+1)*i,k,i);
        bv_clr_bit(v, (k + i) * i);
      }
    }
  }
  return;
}
