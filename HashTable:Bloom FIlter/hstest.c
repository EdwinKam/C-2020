#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

#define OPTIONS "Absqip:r:n:" // define options for switch

int main(void) {
  HashTable *ht = ht_create(1);
  move_to_front = false;
  ht_insert(ht, hs_create("first", NULL));
  ht_insert(ht, hs_create("second", "hahaha"));
  ht_insert(ht, hs_create("first", NULL));

  //  ht_insert(ht, hs_create("third", "wa"));
  //    ht_insert(ht, hs_create("first", NULL));
  //  ht_insert(ht, hs_create("four", "ff"));
  //  ht_insert(ht, hs_create("fifth", "yy"));
  ht_print(ht);
  //  if (ht_lookup(ht, "third")) {
  //    printf("found 1\n");
  //  } else {
  //    printf("not found0\n");
  //  }
  //  printf("ht count: %d\n",ht_count(ht));
  //  ht_print(ht);
  printf("llseek %f\n", ll_seek);
  ht_delete(ht);
  return 0;
}
HatterSpeak *hs_create(char *old, char *hatter) {
  HatterSpeak *h = (HatterSpeak *)malloc(sizeof(HatterSpeak));
  if (!h) {
    return 0;
  }
  h->oldspeak = old;
  h->hatterspeak = hatter;
  return h;
}
void hs_delete(HatterSpeak *h) { free(h); }
