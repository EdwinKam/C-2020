#include "array.h"
Array *arr_create(uint32_t arr_length, unsigned int seed) {
  Array *a = (Array *)calloc(1, sizeof(Array)); // malloc space of object
  if (!a) {
    return 0; // if the a is not created
  }
  if (arr_length < 1) {
    a->length = 1; // if length is negative input
  }
  a->length = arr_length; // assign input value to object value
  a->compare = 0;
  a->move = 0;
  a->array = (uint32_t *)calloc(
      arr_length, sizeof(uint32_t) * arr_length); // malloc space for array
  srand(seed);
  if (!a->array) {
    return 0; // if the a is not created
  }           // input seed
  for (uint32_t i = 0; i < arr_length; i++) {
    // a->array[i] = rand()>>2;
    a->array[i] =
        rand() & 0x3FFFFFFF; // bit mask rand() to make sure the value is 30 bit
  }
  return a;
}

void arr_delete(Array *arr) {
  free(arr->array); // free the array
  free(arr);        // free the object
}

void swap(Array *arr, int a, int b) {
  uint32_t temp = arr->array[a];
  arr->array[a] = arr->array[b];
  arr->array[b] = temp;
}
