#include "shell.h"

void Shell_Sort(Array *arr) {
  uint32_t length = arr->length;
  uint32_t *gap_num = (uint32_t *)calloc(
      length, sizeof(uint32_t) * length); // dynamically allocate memory
  int count = 0;                          // this count keep track on gap[]
  gap(gap_num, length);
  if (!gap_num) {
    return; // if gap[] is not properly memory allocated
  }
  for (uint32_t step = gap_num[count]; step > 0;
       count++, step = gap_num[count]) { // for the gap size in the gap[]
    for (uint32_t i = step; i < length;
         i++) { // for element from step to arr_length
      for (uint32_t j = i; j >= step; j -= step) { // from i to step
        arr->compare++;
        if (arr->array[j] < arr->array[j - step]) { // compare the element that
                                                    // is one gap away from
                                                    // current
          swap(arr, j - step, j);
          arr->move += 3; // swap them if needed
        }
      }
    }
  }
  free(gap_num);
}
void gap(uint32_t *step, uint32_t n) {
  uint32_t count = 0;
  while (n > 1) {
    if (n <= 2) {
      n = 1;
      step[count++] = n;
    } else {
      n = 5 * n / 11;
      step[count++] = n; // store all the gap size into the passed array
    }
  }
}
