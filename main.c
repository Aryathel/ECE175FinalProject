#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Functions/deck_functions.c"
#include "./Functions/types.h"
#include "./Functions/start_game.c"
#include "./Functions/check_winners.c"
#include "./Functions/betting.c"
#include "./Functions/computer_functions.c"

void main(void) {
  //Seed random number functions
  srand(time(0));

  card *head = NULL, *tail = NULL, *player = NULL, *computer = NULL, *temp_computer, *temp_player, *temp;
  int i, j, disc[5], coins, current_bet, win_lose = 0, score, game = 0, round=0;
  char user_name[40];
  char cont = 'y';

  //Games continue until user quits.
  while (cont != 'Q' && cont != 'q') {
    //Every game starts at 100 coins.
    coins = 100;

    //Keeps track of game number (getting user name input breaks otherwise).
    if (round > 0) {
      game = 1;
    }

    //Reset game round counter.
    round = 0;

    //Start the game (get user name, print info)
    start_game(user_name, game);

    //Crete deck to start
    head = create_deck();

    //Shuffle deck (obviously)
    shuffle_deck(head);

    //Loop until player runs out of coins.
    while (coins > 0) {
      //Reset for newest round of play.
      for (i = 0; i < 5; i++) {
        disc[i] = 0;
      }
      round++;

      //Count number of cards left in deck.
      i = 1;
      temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
        i++;
      }
      //printf("\n------\nNum Cards Left: %d\n", i);

      //Re-create deck if there are not enough cards.
      if (i <= 20) {
        //printf("Redealing...\n");
        discard_cards(&head);

        head = create_deck();
        shuffle_deck(head);
      }
      //printf("------\n");

      //Deal cards in an alternating fashion to both players.
      for (i = 0; i < 5; i++) {
        player = deal_card(&head, player);

        computer = deal_card(&head, computer);
      }

      //Prints Computer hand (with last two cards hidden) then player hand.
      printf("Computer's Hand:\n");
      print_computer_hidden(computer);
      printf("%s's Hand:\n", user_name);
      print_cards(player);

      //Makes user place their bet for the round.
      current_bet = place_bet(&coins);

      //User selecting which cards to keep. (0 - DELETE CARD, 1 - KEEP CARD)
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
        }
      }
      printf("\n");

      //Swap out cards that were not selected to be held.
      player = discard_and_draw(player, &head, disc);

      //Set up computer move.
      computer_move(disc, computer);

      //Make computer move.
      computer = discard_and_draw(computer, &head, disc);

      //Get value of who won the round. (1 = Player wins, 2 = Computer Wins)
      win_lose = check_round_winner(player, computer, user_name);

      //Updating Coins
      effects_of_bet(win_lose, current_bet, &coins);

      //Resetting Player Hands
      discard_cards(&player);
      discard_cards(&computer);
    }
    //Print the end of game message, and ask player to play again.
    printf("You LOST all your coins. Game Over!\n\nDo you want to start a new game? (q to Quit): ");
    scanf(" %c", &cont);
  }

  printf("See you next time!");
}
