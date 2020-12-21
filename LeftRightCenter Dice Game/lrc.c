//
//  lrc.c
//  lrc
//
//  Created by Edwin Kam  on 10/10/20.
//

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare function/
uint32_t left(uint32_t pos,
              uint32_t players); // return to current player's left position
uint32_t right(uint32_t pos,
               uint32_t players); // return to current player's right position
bool endgame(uint32_t, uint32_t[]);
uint32_t winner(uint32_t, uint32_t[]);
uint32_t min(uint32_t, uint32_t);

int main(void) {
  // time_t seed=time(0);//generate a random number of seed
  typedef enum faciem {
    LEFT,
    RIGHT,
    CENTER,
    PASS
  } faces; // declare an enum of the dice face
  faces die[] = {LEFT, RIGHT, CENTER,
                 PASS, PASS,  PASS}; // assign an enum to each side of the dice
  const char *names[] = {
      "Happy",      "Sleepy",      "Sneezy", "Dopey",
      "Bashful",    "Grumpy",      "Doc",    "Mirror Mirror",
      "Snow White", "Wicked Queen"}; //assign 10 names to 10 players

  // start display
  unsigned int seed;
  printf("Random seed: ");
  scanf("%u", &seed);
  unsigned int players;
  printf("How many players? ");
  scanf("%u", &players);
  while (players < 2 || players > 10) {
    printf("How many players? (1-10)"); // validation
    scanf("%u", &players);
  }
  srand(seed);            // use the seed
  uint32_t bank[players]; // each player has his own bank
  uint32_t current = 0;   // current position of players
  uint32_t pot = 0;       // money in center
  for (uint32_t i = 0; i < players; i++) {
    bank[i] = 3; // give 3 dollors to each player
  }

  // start game
  while (!endgame(players, bank)) {
    if (bank[current] > 0) { // they roll only if they have more than $1
      printf("%s rolls...", names[current]);
    }
    uint32_t currentbank = bank[current];
    for (uint32_t i = 0; i < min(currentbank, 3); i++) {
      switch (die[rand() % 6]) {
      case LEFT:
        printf(" gives $1 to %s", names[left(current, players)]);
        bank[current]--;
        bank[left(current, players)]++;
        break;
      case RIGHT:
        printf(" gives $1 to %s", names[right(current, players)]);
        bank[current]--;
        bank[right(current, players)]++;
        break;
      case CENTER:
        printf(" puts $1 in the pot");
        bank[current]--;
        pot++;
        break;
      case PASS:
        printf(" gets a pass");
        break;
      }
    }
    if (currentbank > 0) { // they roll only if they have more than $1
      printf("\n");
    }

    // printf("|pot: %d. %s: %d",pot,names[current],bank[current]);
    // printf("\n");
    current = right(current, players);
  }
  current = winner(players, bank); // set the winner pos to current index
  printf("%s wins the $%d pot with $%d left in the bank!\n", names[current],
         pot, bank[current]);

  return 0;
}
uint32_t left(uint32_t pos, uint32_t players) {
  return (pos + players - 1) % players;
}
uint32_t right(uint32_t pos, uint32_t players) {
  return (pos + players + 1) % players;
}
bool endgame(uint32_t players, uint32_t bank[]) {
  uint32_t total = 0;
  for (uint32_t i = 0; i < players; i++) {
    if (bank[i] > 0) {
      total += 1; // see if there is at most one person has >1
    }
  }
  return (total <= 1);
}
uint32_t winner(uint32_t players, uint32_t bank[]) {
  for (uint32_t i = 0; i < players; i++) {
    if (bank[i] > 0) {
      return i; // find who is the one has money left
    }
  }
  return -1; // no body wins, error
}
uint32_t min(uint32_t a, uint32_t b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
