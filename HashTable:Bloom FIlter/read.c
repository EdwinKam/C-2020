#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "hash.h"
#include "parser.h"

int main(void) {

  regex_t word_regex;
  if (regcomp(&word_regex, "[a-zA-Z0-9_]+(('|-)[a-zA-Z0-9_]*)*",
              REG_EXTENDED)) {
    printf("expr was wrong");
    return 0;
  }
  ListNode *banned = NULL;
  ListNode *translate = NULL;
  char *myword = NULL;
  do {
    myword = next_word(stdin, &word_regex);
    if (myword != NULL) { // if valid input
      ll_insert(&banned, hs_create(myword, NULL));
      ll_insert(&translate, hs_create(myword, NULL));
    }

  } while (myword != NULL); // end input while loop
  regfree(&word_regex);
  //  char *myword = NULL;
  //  do {
  //    myword = next_word(stdin, &word_regex);
  //    char *searchword = NULL;
  //    if (myword != NULL) { // if valid input
  //
  //      searchword = strdup(myword);
  //      if (bf_probe(bf, searchword)) {
  //        ListNode *copynode = ht_lookup(ht, searchword);
  //        if (copynode) {
  //          printf("found in hashtable\n");
  //          if (copynode->gs->hatterspeak == NULL) {
  //            ll_insert(&banned, ht_lookup(ht, searchword)->gs);
  //          } else {
  //            ll_insert(&translate, ht_lookup(ht, searchword)->gs);
  //          }
  //        } else {
  //          printf("cant found '%s' in hash table\n", searchword);
  //        }
  //      } else {
  //        printf("filtered by bf\n");
  //      }
  //    }
  //  } while (myword != NULL); // end input while loop

  // ll_output(&banned);

  return 0;
}

HatterSpeak *hs_create(char *old, char *hatter) {
  HatterSpeak *h = (HatterSpeak *)malloc(sizeof(HatterSpeak));
  if (!h) {
    return 0;
  }
  h->hatterspeak = hatter;
  h->oldspeak = old;
  return h;
}
void hs_delete(HatterSpeak *h) {
  // called in ll_node_delete
  free(h->oldspeak);
  free(h->hatterspeak);
  free(h);
}
