#include <stdio.h>
#include "types.h"

//Puts the effects of the bet into play (changes the number of coins the player has.)
void effects_of_bet(int win_lose, int bet, int *coins){
  if (win_lose == 1){
    *coins += bet;
    printf("You WIN and now you have %d coins.\n\n", *coins);
  }
  else {
    *coins = *coins - bet;
    printf("You LOSE and now you have %d coins.\n\n", *coins);
  }
}

//Gets the bet for the given round from the player.
int place_bet(int *coins){
  int i, bet = -1;

  //Loop until valid bet is given.
  while (bet <= 0 || bet > *coins){
    printf("Place your bet (1-%d): ", *coins);
    scanf("%d", &bet);
    if (bet >= 1 && bet <= *coins){
      break;
    }
  }

  printf("\nYou bet %d coins, and you have %d coins left.\n\n", bet, *coins - bet);

  return bet;
}
