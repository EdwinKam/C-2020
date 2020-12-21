#include "binary.h"

void Binary_Insertion_Sort(Array *arr) {
  for (uint32_t i = 0; i < arr->length; i++) {
    uint32_t value = arr->array[i];
    uint32_t left = 0;
    uint32_t right = i;
    while (left < right) {
      uint32_t mid =
          left + (right - left) / 2; // set up the mid pointer
                                     // the mid pointer change value everytime
      arr->compare++;
      if (value >= arr->array[mid]) {
        left = mid + 1; // if current value is larger than mid, then change the
                        // left pointer
      } else {
        right = mid; // otherwise, change the right pointer
      }
    }
    for (uint32_t j = i; j > left; j--) {
      swap(arr, j - 1, j); // bubble sort once at the end
      arr->move += 3;
    }
  }
}
