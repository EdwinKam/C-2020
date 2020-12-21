#include "ll.h"
#include <string.h>

ListNode *ll_node_create(HatterSpeak *gs) {
  ListNode *ll = (ListNode *)malloc(sizeof(ListNode));
  if (ll) {
    ll->next = NULL;
    ll->gs = gs;
    return ll;
  }
  return (ListNode *)NIL;
}

void ll_node_delete(ListNode *n) {
  hs_delete(n->gs);
  free(n);
}

void ll_delete(ListNode *head) {
  ListNode *current = head;
  while (current != NULL) {
    ListNode *temp = current->next;
    ll_node_delete(current);
    current = temp;
  }
}

void ll_del(ListNode *head) {
  ListNode *current = head;
  while (current != NULL) {
    ListNode *temp = current->next;
    free(current);
    current = temp;
  }
}

ListNode *ll_insert(ListNode **head, HatterSpeak *gs) {
  if (ll_lookup(head, gs->oldspeak)) {
    // if (!ref_del) {
    hs_delete(gs);
    //}
    return *head; // return the NULL if this node exist
                  // in this list already
  }               // otherwise, we insert a new node
  ListNode *new_node = ll_node_create(gs);
  ht_total++;
  if (*head == NULL) {
    *head = new_node; // if the head of the linked list is empty, we assgn this
                      // new node as the head
  } else {
    // if insert from tail
    //    ListNode *current = *head;      // otherwise, the look up for the tail
    //    while (current->next != NULL) { // stop until current->next is NULL
    //      current = current->next;
    //    }
    //    current->next = new_node; // point the current tail to the new node
    if (new_node) {
      new_node->next = *head; // point to original head
    }
    head = &new_node; // assign address of new node to head
  }
  return *head;
}

ListNode *ll_lookup(ListNode **head, char *key) {
  ht_seek++;
  if (*head == NULL) {
    return NULL;
  } else {
    ListNode *current = *head; // otherwise, the look up for the tail
    ListNode *prev = NULL;
    while (strcmp(current->gs->oldspeak, key) !=
           0) { // stop until current->next is NULL
      ll_seek++;
      prev = current;
      current = current->next;
      if (current == NULL) { // if next node is NULL, that means we reach the
                             // tail of the list
        return NULL;
      }
    }
    if (move_to_front) {
      if (!prev) {
        return current; // if current is already the first node of the list
      }
      ListNode *temp = *head;
      *head = current;
      prev->next = current->next;
      current->next = temp;
    }
    return current; // point the current tail to the new node
  }
}

void ll_print(ListNode **head) {
  ListNode *current = *head;
  while (current != NULL) {
    printf("o:%s, h:%s | ", current->gs->oldspeak, current->gs->hatterspeak);
    current = current->next;
  }
  return;
}

void ll_output(ListNode **head) {
  ListNode *current = *head;
  while (current != NULL) {
    printf("%s", current->gs->oldspeak);
    if (current->gs->hatterspeak != NULL) {
      printf(" -> %s\n", current->gs->hatterspeak);
    } else {
      printf("\n");
    }

    current = current->next;
  }
  return;
}
