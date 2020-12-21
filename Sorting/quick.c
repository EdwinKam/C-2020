#include "quick.h"
#include <stdio.h>
uint32_t partition(Array *arr, int left, int right) {
  uint32_t pivot = arr->array[left]; // set left value to the pivot
  uint32_t lo = left + 1;            // set lo pointer
  uint32_t hi = right;               // set hi pointer

  while (lo <= hi) { // while lo is less than or equal to hi
    while (lo <= hi && arr->array[hi] >= pivot) {
      arr->compare++;
      hi--;
    }
    if (lo <= hi) {
      arr->compare++; // the last comparision won't get into the while loop, so
                      // we have to do it outside
    }
    while (lo <= hi && arr->array[lo] <= pivot) {
      arr->compare++;
      lo++;
    }
    if (lo <= hi) {
      arr->compare++;
    }
    if (lo < hi) {
      swap(arr, lo, hi); // swap lo and hi to get them to the right side
      arr->move += 3;
    } else { // if they are equal
      break;
    }
  }
  swap(arr, left, hi);
  arr->move += 3;
  return hi;
}
void Quick_Sort(Array *arr, int left, int right) {
  if (left < right) {
    uint32_t index = partition(
        arr, left, right); // this index is placed in its final position
    Quick_Sort(arr, index + 1, right); // recursion to solve the left part
    Quick_Sort(arr, left, index - 1);
  }
  return;
}
