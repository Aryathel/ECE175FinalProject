#include <stdio.h>
#include "types.h"

void effects_of_bet(int vars, int bet, int *coins){
  if (vars == 1){
    *coins += bet;
    printf("You WIN and now you have %d coins.\n\n", *coins);
  }
  else {
    *coins = *coins - bet;
    printf("You LOSE and now you have %d coins.\n\n", *coins);
  }
}

int place_bet(int *coins){
  int i, bet = -1;

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
