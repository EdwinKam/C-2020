#include "array.h"
#include "binary.h"
#include "bubble.h"
#include "quick.h"
#include "shell.h"
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTIONS "Absqip:r:n:" // define options for switch

void result(Array *, uint32_t, uint32_t); // function for display format

int main(int argc, char **argv) {
  int input = 0;
  uint32_t range = 100;        // default number for element we will print
  unsigned int seed = 8222022; // default random seed
  uint32_t size = 100;         // default array size
  bool bin = false;            // check if user input -b
  bool sin = false;            // check if user input -s
  bool qin = false;            // check if user input -q
  bool iin = false;            // check if user input -i

  while ((input = getopt(argc, argv, OPTIONS)) != -1) {
    switch (input) {
    case 'A':
      bin = true; // if user input -A(all), set all flag to true
      sin = true;
      qin = true;
      iin = true;
      break;
    case 'b':
      bin = true; // set flag b
      break;
    case 's':
      sin = true; // set flag s
      break;
    case 'q':
      qin = true; // set flag q
      break;
    case 'i':
      iin = true; // set flag i
      break;
    case 'p':
      range = atoi(optarg); // take user input for -p, display range
      break;
    case 'r':
      seed = atoi(optarg); // set bound if user input
                           // fill out the bv with prime
      break;
    case 'n':
      size = atoi(optarg); // set bound if user input
                           // fill out the bv with prime
      break;
    case ':': // if user didnt input a desire size
      break;
    default:
      printf("Invalid input\n"); // error message
      break;
    }
  }
  if (iin) {
    // binary insertion
    printf("Binary Insertion Sort\n"); // header
    Array *arr = arr_create(
        size, seed); // create a filled in array with given size and random
    Binary_Insertion_Sort(arr); // sort the array
    result(arr, range, size);   // print result
    arr_delete(arr);            // deallocate memory
  }
  if (qin) {
    printf("Quick Sort\n");
    Array *arr = arr_create(size, seed);
    Quick_Sort(arr, 0, arr->length - 1);
    result(arr, range, size); // print result
    arr_delete(arr);
  }
  if (sin) {
    // shell sort
    printf("Shell Sort\n");
    Array *arr = arr_create(size, seed);
    Shell_Sort(arr);
    result(arr, range, size); // print result
    arr_delete(arr);
  }
  if (bin) {
    printf("Bubble Sort\n");
    Array *arr = arr_create(size, seed); // create array
    Bubble_Sort(arr);                    // sort array
    result(arr, range, size);            // print result
    arr_delete(arr);
  }
  return 0;
}
void result(Array *arr, uint32_t range, uint32_t size) {
  printf("%d elements, %d moves, %d compares\n", size, arr->move,
         arr->compare); // print move and compare
  for (uint32_t i = 0; i < range; i++) {
    printf("%13d", arr->array[i]); // for range, print array element
  }
  printf("\n");
}
