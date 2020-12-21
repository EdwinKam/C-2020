#ifndef __HASH_H__
#define __HASH_H__

#ifndef NIL
#define NIL (void *)
#endif

#include "ll.h"
#include "speck.h"
#include <inttypes.h>

typedef struct HashTable {
  uint64_t salt[2];
  uint32_t length;
  ListNode **heads;
  float ll_seek;
  float ht_seek;
  float total_word;
  float ht_occupied;
} HashTable;

// Constructor
HashTable *ht_create(uint32_t length);

// destructor
void ht_delete(HashTable *ht);

// return number of entries in hash table
uint32_t ht_count(HashTable *h);

// searches a hashtable for a key
// return the ListNode if if found and returns Null otherwise
// this should call the ll_lookup function
ListNode *ht_lookup(HashTable *ht, char *key);

// Crate a new listnode from hatterspeak
// insert the new node to the hash table
// This should call the ll_insert function

// ht: hashtable
// the hatterspeak struct (oldspeak, hatterspeak) add to the hash table

void ht_insert(HashTable *ht, HatterSpeak *gs);

// self test, print hs
void ht_print(HashTable *ht);

#endif
