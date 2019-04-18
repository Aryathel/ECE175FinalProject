#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Functions/deck_functions.c"
#include "./Functions/types.h"
#include "./Functions/start_game.c"
#include "./Functions/check_winners.c"
#include "./Functions/betting.c"

void main(void) {
  //Seed random number functions
  srand(time(0));

  card *head = NULL, *tail = NULL, *player = NULL, *computer = NULL, *temp;
  int i, j, disc[5] = {0,0,0,0,0}, coins = 100, current_bet, win_lose = 0, score;
  char user_name[40];

  start_game(user_name);

  head = create_deck();
  tail = get_tail(head);

  shuffle_deck(head);

  for (i = 0; i < 5; i++) {
    player = deal_card(head, player);
    temp = head;
    head = head->next;
    free(temp);

    computer = deal_card(head, computer);
    temp = head;
    head = head->next;
    free(temp);
  }

  printf("Computer's Hand:\n");
  print_computer_hidden(computer);
  printf("%s's Hand:\n", user_name);
  print_cards(player);

  current_bet = place_bet(&coins);

  while (i != -1){
    printf("Pick cards (between 1-5) to hold. Enter the same number to deselect a card (-1 to stop): ");
    scanf("%d", &i);
    if (i >= 1 && i <= 5) {
      if (disc[i-1] == 1) {
        disc[i-1] = 0;
        printf("Card %d Will Be Discarded\n", i);
      } else {
        disc[i-1] = 1;
        printf("Card %d Will Be Kept\n", i);
      }
    } else if (i != -1) {
      printf("Please select a number 1-5.\n");
    }
  }
  printf("\n");
  player = discard_and_draw(player, head, disc);

  win_lose = check_round_winner(player, computer, user_name);

  effects_of_bet(win_lose, current_bet, &coins); //updates coins
  printf("Number of Coins Left: %d\n", coins);
}
