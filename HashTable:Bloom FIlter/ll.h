#ifndef __LL_H__
#define __LL_H__

#ifndef NIL
#define NIL (void *)0
#endif

#include "hatterspeak.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// if the flag is set, listNodes tht are queried are moved to the front
bool move_to_front;
float ll_seek;
float ht_seek;
float ht_total;
// bool ref_del;

typedef struct ListNode ListNode;

// struct defination of ListNode
// gs: hatterseak struct containing oldspeak and its hattterspeak translation

struct ListNode {
  HatterSpeak *gs;
  ListNode *next;
};

// constructor for a listnode
// gs: hatterspeak struct containing oldspeak and is hatterpeak transltion
ListNode *ll_node_create(HatterSpeak *gs);

// destructor for a listnodes
// n: the listnode to free
void ll_node_delete(ListNode *n);

// destructor for a linked list of listnodes
// head: the head of the linked list
void ll_delete(ListNode *head);

void ll_del(ListNode *head);

// creates and inserts a listnode into a linked list
// head: the head of the linked list to insert in
// gs: hatterspeak struct
ListNode *ll_insert(ListNode **head, HatterSpeak *gs);

// searches for a specific key in a linked list
// returns the listnode if found and null otherwise

// head: the head of the linked list to search in
// key: the key to search for.
ListNode *ll_lookup(ListNode **head, char *key);

// self test,print ll
void ll_print(ListNode **head);

void ll_output(ListNode **head);

#endif
