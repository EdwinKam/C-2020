#include "bubble.h"

void Bubble_Sort(Array *arr) {
  for (uint32_t i = 0; i < arr->length - 1; i++) {
    uint32_t j = arr->length - 1;
    while (j > i) {
      arr->compare++;                          // inc compare
      if (arr->array[j] < arr->array[j - 1]) { // if j < j-1, which is smaller
                                               // than the element before it
        swap(arr, j, j - 1);
        arr->move += 3;
      }
      j--; // dec j
    }
  }
}
