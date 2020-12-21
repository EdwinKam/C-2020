//
//  sequence.c
//  a4
//
//  Created by Edwin on 10/28/20.
//

#include "bv.h"
#include "sieve.h"
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTIONS ":spn:" // define options for switch

void print_prime(BitVector *v);
void fabonacci(uint32_t);
void lucas(uint32_t);
void mersenne(uint32_t);
void base(uint32_t, uint32_t);

int main(int argc, char **argv) {
  int c = 0;
  int bound = 1000; // default bound
  bool sin = false; // check if user input -p and -s
  bool pin = false;
  BitVector *v; // declare object
  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    switch (c) {
    case 's':
      sin = true; // we want to run the function after we get all arguement
      break;
    case 'p':
      pin = true;
      break;
    case 'n':
      bound = atoi(optarg); // set bound if user input
                            // fill out the bv with prime
      break;
    case ':': // if user didnt input a desire size
      break;
    default:
      printf("Invalid input\n"); // error message
      break;
    }
  }

  if (argc == 1) {
    puts("Error: no arguement supplied!"); // if no arguement
    return -1;
  }
  v = bv_create(bound); // create a bv
  sieve(v);
  if (sin) {
    print_prime(v); // call print prime()
  }
  if (pin) {
    // print palindrome
    printf("\nBase 2\n");
    printf("---- --\n");
    for (uint32_t i = 0; i < bv_get_len(v); i++) {
      if (bv_get_bit(v, i)) { // get in here only if its a prime
        base(2, i);           // will print out all palindrome
      }
    }
    printf("\nBase 9\n");
    printf("---- --\n");
    for (uint32_t i = 0; i < bv_get_len(v); i++) {
      if (bv_get_bit(v, i)) {
        base(9, i);
      }
    }
    printf("\nBase 10\n");
    printf("---- --\n");
    for (uint32_t i = 0; i < bv_get_len(v); i++) {
      if (bv_get_bit(v, i)) {
        base(10, i);
      }
    }
    printf("\nBase 21\n"); // last name K
    printf("---- --\n");
    for (uint32_t i = 0; i < bv_get_len(v); i++) {
      if (bv_get_bit(v, i)) {
        base(21, i);
      }
    }
  }

  bv_delete(v); // free bv memory
  return 0;
} // end main

// function
void print_prime(BitVector *v) {
  for (uint32_t i = 0; i < bv_get_len(v); i++) {
    if (bv_get_bit(v, i)) {
      printf("%d: prime", i);
      mersenne(i); // call each function
      lucas(i);
      fabonacci(i);
      printf("\n");
    }
  }
}

void fabonacci(uint32_t prime) {
  uint32_t prev = 1; // define first two term
  uint32_t cur = 1;  // previous and current
  while (cur <= prime) {
    if (cur == prime) {
      printf(", fibonacci"); // print out if this number is fibonacci and prime
    }
    uint32_t temp = cur;
    cur = cur + prev;
    prev = temp; // increment the term and add them to next sum
  }
}

void lucas(uint32_t prime) {
  if (prime == 2) {
    printf(
        ", lucas"); // since 2 is the first term, we will just skip the looping
    return;
  }
  uint32_t prev = 2; // declare first two term
  uint32_t cur = 1;
  while (cur <= prime) {
    if (cur == prime) {
      printf(", lucas");
    }
    uint32_t temp = cur;
    cur = cur + prev;
    prev = temp;
  }
}

void mersenne(uint32_t prime) {
  uint32_t num = 2 - 1;
  while (num <= prime) {
    if (num == prime) {
      printf(", mersenne");
    }
    num = (num + 1) * 2 - 1; // we calculate the next term each time
  }
}

void base(uint32_t base, uint32_t prime) {
  uint32_t save =
      prime; // since our prime will be modified, we need to save this prime
  uint32_t len = 10;  // len of the string
  uint32_t index = 0; // keep track on how many char we used in the string
  char *s = (char *)malloc(sizeof(char) * len);
  char *letter = "0123456789abcdefghijk"; // I only need up to K

  while (prime > 0) {
    s[index++] = letter[prime % base];
    if (index >= len - 1) {
      len *= 2;
      s = (char *)realloc(s, len * sizeof(char));
      // if we exceed the memory, we will need to reallocate
    }
    prime /= base;
  }
  s[index] = '\0'; // end the string
  bool pal = true;
  uint32_t left = 0, right = index - 1;
  while (pal && left < right) {
    pal =
        (s[left++] == s[right--]); // if s[left]==s[right], we continue the loop
  }
  if (pal) {
    printf("%d = %s\n", save, s); // if pal still = true, then this is
                                  // palindrome
  }
  free(s); // free memory
  return;
}
