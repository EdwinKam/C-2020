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

#define OPTIONS ":h:f:mbs" // define options for switch

int main(int argc, char **argv) {
  int input = 0;

  bool sin = false; // check if user input -s
  bool min = false;
  bool bin = false;
  uint32_t hash_size = 10000; // check fo type
  uint32_t filter_size = pow(2, 20);
  move_to_front = false; // default
  ll_seek = 0;           // initialize ll_seek
  ht_seek = 0;           // initialize ht_seek
  ht_total = 0;          // initial ht_total

  while ((input = getopt(argc, argv, OPTIONS)) != -1) {
    switch (input) {
    case 's':
      sin = true; // if -s input, set s flag
      break;
    case 'h':
      hash_size = atoi(optarg);
      break;
    case 'f':
      filter_size = atoi(optarg);
      break;
    case 'm':
      min = true;
      if (bin) {
        printf("-m -b can't use at the same time\n");
        exit(0);
      }
      move_to_front = true; // set the external bool to true
      break;
    case 'b':
      bin = true;
      if (min) {
        printf("-m -b can't use at the same time\n");
        exit(0);
      }
      move_to_front = false; // set the external bool to false
      break;
    case ':': // if user didnt input a desire size
      break;
    default:
      printf("Invalid input\n"); // error message
      break;
    }
  }

  BloomFilter *bf = bf_create(filter_size); // create bloom filter
  HashTable *ht = ht_create(hash_size);     // creat hash table

  // add txt to bloom filter to and hashtable
  char old[4096];                       // store string from txt
  FILE *oldfile;                        // open file
  oldfile = fopen("oldspeak.txt", "r"); // open oldspeak for reading
  while (fscanf(oldfile, "%s\n", old) != EOF) {

    char *oldcopy = (char *)calloc(1, sizeof(char *) * 4096);
    if (oldcopy) {
      strcpy(oldcopy, old);
      bf_insert(bf, oldcopy);
      ht_insert(ht, hs_create(oldcopy, NULL));
    }
  }
  fclose(oldfile);

  // put hatterspeak.txt into bloom filter and hashtable
  char hatter[4096];
  FILE *hatterfile;
  hatterfile = fopen("kkk.txt", "r"); // open oldspeak for reading
  while (fscanf(hatterfile, "%s %s\n", old, hatter) != EOF) {

    char *oldcopy = (char *)calloc(1, sizeof(char *) * 4096);
    char *hattercopy = (char *)calloc(1, sizeof(char *) * 4096);
    if (oldcopy) {
      strcpy(oldcopy, old);
      strcpy(hattercopy, hatter);
      bf_insert(bf, oldcopy);
      ht_insert(ht, hs_create(oldcopy, hattercopy));
    }
  }
  fclose(hatterfile);

  // after storing txt in bloomfilter and hashtable

  // ask for user input
  regex_t word_regex;
  // ref_del = true;
  if (regcomp(&word_regex, "[a-zA-Z0-9_]+(('|-)[a-zA-Z0-9_]*)*",
              REG_EXTENDED)) {
    printf("expr was wrong");
    return 0;
  }
  // LinkedList to store user bad word and translate word
  ListNode *banned = NULL;    // store forbindden word
  ListNode *translate = NULL; // store words that have translation
  char *myword = NULL;
  do {

    myword = next_word(stdin, &word_regex);
    // char *searchword = NULL;
    if (myword != NULL) { // if valid input
      char *searchword = (char *)calloc(1, sizeof(char *) * 4096);
      strcpy(searchword, myword); // copymyword to searchword
      if (bf_probe(bf, searchword)) {
        // try to find search word in bloom filter
        ListNode *foundword = ht_lookup(ht, searchword);
        // if found, get the ListNode
        if (foundword) { // if ListNode!=Null, which means found that listnode
          if (foundword->gs->hatterspeak == NULL) {
            // determine whether this searchword has a translation
            // no hatterspeak string in the linkedlist
            // no translation
            // then store string in banned
            banned = ll_insert(&banned, hs_create(searchword, NULL));
            // if no translation,
            // put the word into
            // banned linked list
          } else {
            // if there is translation
            // then store string in translate
            char *hatter = (char *)calloc(1, sizeof(char *) * 4096);
            strcpy(hatter, foundword->gs->hatterspeak);
            translate = ll_insert(&translate, hs_create(searchword, hatter));
            // if there is
            // translation, put
            // it into translate
            // link list
          }
        } else {
          // printf("cant found '%s' in hash table\n", searchword);
        }
      } else {
        // printf("filtered by bf\n");
      }
    }
  } while (myword != NULL); // end input while loop
  regfree(&word_regex);     // deallocate regex memory
  bool is_dungoen =
      false;    // bool var to determine whether is banned word is entered
  if (banned) { // if there are words in banned linked list
    is_dungoen = true; // set to true, if this set to true, it wont print the
                       // other message
    printf("Dear Wonderlanders,\n\n");
    printf("Your have chosen to use words that the queen has decreed "
           "oldspeak.\n");
    printf("Due to your infraction you will be sent to the dungoen where you "
           "will be taught hatterspeak.\n\n");
    printf("Your errors:\n\n");
    ll_output(&banned); // print banned linked list
    ll_delete(banned);  // deallocate this linked list memory
  }
  if (translate) {
    if (!is_dungoen) { // check whether a banned word was entered, if not then
                       // print message
      printf("Dear Wonderlander,\n\n");
      printf("The decree for hatterspeak finds your message lacking. Some of "
             "the words that you used are not hatterspeak.\n");
      printf("The list shows how to turn the oldspeak words into "
             "hatterspeak.\n\n");
    } else {
      printf("\nAppropraite hatterspeak translation.\n\n");
    }
    ll_output(&translate); // print translate message
    ll_delete(translate);  // deallocate this linked list memory
  }

  if (sin) { // if user wants stat
    printf("Seeks: %.0f\n", ht_seek);
    printf("Average seek length: %f\n", ll_seek / ht_seek);
    printf("Average Linked List length: %f\n", ht_total / hash_size);
    printf("Hash table load: %f%%\n", ht->ht_occupied * 100 / hash_size);
    printf("Bloom filter load: %f%%\n",
           bf->filter->occupied * 100 / filter_size);
  }
  bf_delete(bf); // deallocate memory
  ht_delete(ht);
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
