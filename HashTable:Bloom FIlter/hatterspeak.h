#ifndef __HATTERSPEAK_H__
#define __HATTERSPEAK_H__
#include <stdbool.h>
#include <stdlib.h>

typedef struct HatterSpeak {
  char *oldspeak;
  char *hatterspeak;
} HatterSpeak;

HatterSpeak *hs_create(char *old, char *hatter);
void hs_delete(HatterSpeak *h);
#endif
