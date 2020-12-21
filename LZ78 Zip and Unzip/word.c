#include "word.h"
#include "code.h"

Word *word_create(uint8_t *syms, uint32_t len) {
  Word *w = (Word *)malloc(sizeof(Word));
  if (w) { // if we succesfully allocate memory for w
    w->syms = syms;
    w->len = len;
    return w;
  }
  printf("error iun word create");
  exit(1);
  return NULL;
}

Word *word_append_sym(Word *w, uint8_t sym) {
  uint8_t *copy = (uint8_t *)malloc(sizeof(uint8_t) * 1000);
  if (copy) {
    for (uint8_t i = 0; i < w->len; i++) {
      copy[i] = w->syms[i];
    }
    Word *nw = word_create(copy, w->len + 1); // copy this word

    if (nw && nw->syms) {
      nw->syms[nw->len - 1] = sym; // add to the last index
      return nw;
    }
  } else {
    exit(1);
  }
  return NULL;
}

void word_delete(Word *w) {
  if (w) {
    free(w->syms);
    free(w);
  }
}

WordTable *wt_create(void) {
  WordTable *wt = (WordTable *)malloc(sizeof(Word) * MAX_CODE);
  if (wt) {
    for (uint16_t i = 0; i < MAX_CODE; i++) {
      wt[i] = NULL; // initialize wt, calloc in unix gives seg fault
    }
    uint8_t *syms = (uint8_t *)malloc(sizeof(uint8_t) * 1000);
    wt[EMPTY_CODE] = word_create(syms, 0);
    return wt;
  }
  return NULL;
}

void wt_reset(WordTable *wt) {
  for (int i = EMPTY_CODE + 1; i < MAX_CODE; i++) {
    if (wt[i]) {
      word_delete(wt[i]);
    }
  }
}

void wt_delete(WordTable *wt) {
  for (int i = 0; i < MAX_CODE; i++) {
    if (wt[i]) {
      word_delete(wt[i]);
    }
  }
  if (wt) {
    free(wt);
  }
}

void wt_print(WordTable *wt) {
  for (int i = 0; i < MAX_CODE; i++) {
    if (wt[i] != NULL) {
      printf("word %d: ", i);
      word_print(wt[i]);
      printf("\n");
    }
  }
}

void word_print(Word *w) {
  for (uint32_t i = 0; i < w->len; i++) {
    printf("%d ", w->syms[i]);
  }
}
