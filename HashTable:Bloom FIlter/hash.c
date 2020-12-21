#include "hash.h"

HashTable *ht_create(uint32_t length) {
  HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
  if (ht) {
    ht->salt[0] = 0x85ae998311115ae3;
    ht->salt[1] = 0xb6fac2ae33a40089;
    ht->length = length;
    ht->heads = (ListNode **)calloc(length, sizeof(ListNode *));
    ht->ll_seek = 0;
    ht->ht_seek = 0;
    ht->ht_occupied = 0;
    return ht;
  }
  return NULL;
}

void ht_delete(HashTable *ht) {
  for (uint32_t i = 0; i < ht->length; i++) {
    ll_delete(ht->heads[i]);
  }
  free(ht->heads);
  free(ht);
  return;
}
uint32_t ht_count(HashTable *h) {
  uint32_t count = 0;
  for (uint32_t i = 0; i < h->length; i++) {
    if (h->heads[i]) {
      count++;
    }
  }
  return count;
}

ListNode *ht_lookup(HashTable *ht, char *key) {

  uint32_t index = hash(ht->salt, key) % ht->length;
  // printf("ht_lookup found the word. index: %d\n", index);
  return ll_lookup(&ht->heads[index], key);
}

void ht_insert(HashTable *ht, HatterSpeak *gs) {
  uint32_t index = hash(ht->salt, gs->oldspeak) % ht->length; // hash index
  if (ht->heads[index] == NULL) {
    ht->ht_occupied++; // for stat
  }
  ht->heads[index] = ll_insert(&ht->heads[index], gs); // head becomes new node
  return;
}

void ht_print(HashTable *ht) {
  printf("HashTable Print--------------\n");
  for (uint32_t i = 0; i < ht->length; i++) {
    printf("%d row: ", i);
    ll_print(&ht->heads[i]);
    printf("\n");
  }
  printf("HashTable end--------------\n");
}
