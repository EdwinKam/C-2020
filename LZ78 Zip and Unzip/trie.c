#include "trie.h"
#include "code.h"
#include "stdio.h"

TrieNode *trie_node_create(uint16_t index) {
  TrieNode *tn = (TrieNode *)malloc(sizeof(TrieNode));
  //*tn->children = (TrieNode *)malloc(sizeof(TrieNode)*ALPHABET);
  if (tn) {
    for (int i = 0; i < ALPHABET; i++) {
      tn->children[i] = 0;
    }
    tn->code = index;
    return tn;
  }
  return NULL;
}

void trie_node_delete(TrieNode *n) { free(n); }

TrieNode *trie_create(void) {
  TrieNode *tn = (TrieNode *)malloc(sizeof(TrieNode));
  // tn->children= (TrieNode *)calloc(ALPHABET,sizeof(TrieNode)*ALPHABET);
  if (tn) {
    for (int i = 0; i < ALPHABET; i++) {
      tn->children[i] = NULL;
    }
    tn->code = EMPTY_CODE;
    return tn;
  }
  exit(1);
  return NULL;
}

void trie_reset(TrieNode *root) {
  for (int i = 0; i < ALPHABET; i++) {
    if (root->children[i] != NULL) {
      trie_delete(
          root->children[i]); // if childen[i] !=NULL, we delete that node too
    }
  }
  free(root->children);
}

void trie_delete(TrieNode *n) {
  for (int i = 0; i < ALPHABET; i++) {
    if (n->children[i] != NULL) {
      trie_delete(
          n->children[i]); // if childen[i] !=NULL, we delete that node too
    }
  }
  trie_node_delete(n); // delete the current node
}

TrieNode *trie_step(TrieNode *n, uint8_t sym) { return n->children[sym]; }

void trie_print(TrieNode *n) {
  if (n != NULL)
    printf("trie node: %d\n", n->code);
  //  for (int i = 0; i < ALPHABET; i++) {
  //    if (n->children[i] != NULL) {
  //      printf("index: %d, code: %d | ", i, n->children[i]->code);
  //    }
  //  }
  //  printf("\n");
}
