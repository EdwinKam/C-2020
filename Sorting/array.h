#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <inttypes.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
typedef struct Array {
  uint32_t *array;
  uint32_t length;
  uint32_t move;
  uint32_t compare;
} Array;

Array *arr_create(uint32_t arr_length, unsigned int seed);

void arr_delete(Array *arr);

void swap(Array *arr, int a, int b);

#endif
