# Left Right Center Game
The program passed both minimun and functional test

## DESIGN.pdf
* Includes flow chart and psuedocode
## Makefile
- used the code provided from the lab
- edit it and add the target all
- command make will compile the program
- command make clean will clean all files that the complier generates
## lrc.c
### main
- Ask for random seed and numbers of players
- if entered invalid numebrs of players(Ex. 1<=x,x>10)
- The system will prompt again for valid input
- copied enums from the lab
- I also make sure the output of the program is exactly the same from the lab
### functions
- The program will ask for user's random seed and number of players
- copied left() and right() from the lab
- created endgame() to determine if the game is end
- created winner() to determine who is the winner
- for players has more than $3, I used min(bank,3) to make sure we only roll the dice 3 times max
### variables
- bank[] to keep track on every player's money
- pot- money in the pot

