//
//  tower.c
//  A3
//
//  Created by Edwin on 10/28/20.
//

#include "stack.h"
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define OPTIONS ":rsn:" // define options for switch

int recursion(int move, int size, char from, char to, char stop);
int stacks(int move, int size, Stack *A, Stack *B, Stack *C);

int main(int argc, char **argv) {
  int c = 0;
  int stacknum = 5; // default disks aomunt
  bool rin = false; // check if user input -r and -s
  bool sin = false;
  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    switch (c) {
    case 'r':
      rin = true; // we want to run the function after we get all arguement
      break;
    case 's':
      sin = true;
      break;
    case 'n':
      stacknum = atoi(optarg);
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
  // Stack *s2=stack_create(stacknum, 'b');
  if (sin) {
    printf("================================\n");
    printf("----------   STACKS   ----------\n");
    printf("================================\n");
    Stack *A = stack_create(stacknum, 'A'); // define 3 pegs
    Stack *B = stack_create(stacknum, 'B');
    Stack *C = stack_create(stacknum, 'C');
    for (int i = 0; i < stacknum; i++) {
      stack_push(A, stacknum - i); // fill in the first peg
    }
    int move =
        stacks(0, stacknum, A, B, C); // call the stacks implementation function
    printf("\nNumber of moves: %d\n", move); // display result
    stack_delete(A);
    stack_delete(B);
    stack_delete(C);
  }
  if (rin) {
    printf("================================\n");
    printf("--------   RECURSION   ---------\n");
    printf("================================\n");
    int move = recursion(0, stacknum, 'A', 'B', 'C');
    printf("\nNumber of moves: %d\n", move);
  }

  return 0;
} // end main

int stacks(int move, int size, Stack *from, Stack *to, Stack *stop) {
  while (to->top < size) { // stop if the destination peg is full
    if (size % 2 == 0) {   // for even
      if ((stack_peek(from) != -1 && stack_peek(from) < stack_peek(stop)) ||
          stack_peek(stop) ==
              -1) { // if the top disk on peg From is legal to move to peg stop
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(from),
               from->name, stop->name);
        stack_push(stop, stack_pop(from));
        move++;
      } else { // otherwise
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(stop),
               stop->name, from->name);
        stack_push(from, stack_pop(stop));
        move++;
      }                      // donef<->s
      if (to->top == size) { // if we done then exit the loop
        break;
      }
      if ((stack_peek(from) != -1 && stack_peek(from) < stack_peek(to)) ||
          stack_peek(to) == -1) {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(from),
               from->name, to->name);
        stack_push(to, stack_pop(from));
        move++;
      } else {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(to), to->name,
               from->name);
        stack_push(from, stack_pop(to));
        move++;
      } // donef<->t
      if (to->top == size) {
        break;
      }
      if ((stack_peek(stop) != -1 && stack_peek(stop) < stack_peek(to)) ||
          stack_peek(to) == -1) {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(stop),
               stop->name, to->name);
        stack_push(to, stack_pop(stop));
        move++;
      } else {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(to), to->name,
               stop->name);
        stack_push(stop, stack_pop(to));
        move++;
      } // done s<->t

    } else {
      if ((stack_peek(from) != -1 && stack_peek(from) < stack_peek(to)) ||
          stack_peek(to) == -1) {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(from),
               from->name, to->name);
        stack_push(to, stack_pop(from));
        move++;
      } else {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(to), to->name,
               from->name);
        stack_push(from, stack_pop(to));
        move++;
      } // donef<->t
      if (to->top == size) {
        break;
      }
      if ((stack_peek(from) != -1 && stack_peek(from) < stack_peek(stop)) ||
          stack_peek(stop) == -1) {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(from),
               from->name, stop->name);
        stack_push(stop, stack_pop(from));
        move++;
      } else {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(stop),
               stop->name, from->name);
        stack_push(from, stack_pop(stop));
        move++;
      } // donef<->t
      if (to->top == size) {
        break;
      }
      if ((stack_peek(to) != -1 && stack_peek(to) < stack_peek(stop)) ||
          stack_peek(stop) == -1) {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(to), to->name,
               stop->name);
        stack_push(stop, stack_pop(to));
        move++;
      } else {
        printf("Move disk %d from peg %c to peg %c\n", stack_peek(stop),
               stop->name, to->name);
        stack_push(to, stack_pop(stop));
        move++;
      } // done s<->t
    }
  }
  return move;
}

int recursion(int move, int size, char from, char to, char stop) {
  if (size == 1) {
    printf("Move disk %d from peg %c to peg %c\n", size, from, to);
    move++;
    return move; // return a value if only one disk
  } else {
    move = recursion(move, size - 1, from, stop,
                     to); // call recursion function if one than one disk
    printf("Move disk %d from peg %c to peg %c\n", size, from, to);
    move++;
    move = recursion(move, size - 1, stop, to, from);
    return move;
  }
  return 0; // shouldn't go into here
}
