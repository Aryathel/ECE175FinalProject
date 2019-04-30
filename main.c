#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./Functions/misc_functions.c"
#include "./Functions/deck_functions.c"
#include "./Functions/types.h"
#include "./Functions/start_game.c"
#include "./Functions/check_winners.c"
#include "./Functions/betting.c"
#include "./Functions/computer_functions.c"
#include "./Functions/statistics.c"

void main(void) {
  //In order to view all ASCII art and printed statistics neatly, the program asks the user to expand their console window
  printf("Please make sure you can see the entire line below on a single line before continuing:\n%c", 204);
  print_multi(205, 103);
  printf("%c\nPress Enter to Continue...", 185);
  while(getchar() != '\n');

  //Seed random number functions
  srand(time(0));

  //Per run variables.
  card *head = NULL, *tail = NULL, *player = NULL, *player2 = NULL, *computer = NULL, *temp_computer, *temp_player, *temp;
  int i, j, disc[5], coins, coins2, current_bet, win_lose = 0, round = 0, game = 0;
  char cont = 'y', user_name[20], user_name2[20];

  //Stats variables.
  int num_players, games_played = 0, comp_wins = 0, player_wins = 0, rounds_total = 0, other = 0, jacks_or_better = 0, two_pair = 0, three_of_a_kind = 0, straight = 0, flush = 0, full_house = 0, four_of_a_kind = 0, straight_flush = 0, royal_flush = 0;

  //Try to open the stats text file.
  FILE *stats = fopen("./Data/stats.txt", "r");
  if (stats == NULL) {
    //Try to create the file if it doesn't exist
    stats = fopen("./Data/stats.txt", "w");
    fclose(stats);
    //Try to open it again.
    stats = fopen("./Data/stats.txt", "r");
    while (stats == NULL) {
      //This loop will run while the file still does not exist, most likely because the proper folder does not exist.
      //Note - this is changed in the d2l submission version, the proper version is on Github - https://github.com/HeroicosHM/ECE175FinalProject.
      printf("Stats file inaccessible.\nPlease create a folder called Data within the program folder.\n");
      printf("Press Enter to Continue");
      while(getchar() != '\n');
      //Try to create the file again.
      stats = fopen("./Data/stats.txt", "w");
    }
    //Since the file had to be created, initialize all the values to 0 in the file.
    fprintf(stats, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", games_played, rounds_total, comp_wins, player_wins, other, jacks_or_better, two_pair, three_of_a_kind, straight, flush, full_house, four_of_a_kind, straight_flush, royal_flush);
    fclose(stats);
    cont = 'y';
  } else {
    //if the file does exist, overwrite the stats variables with values from the file.
    fscanf(stats, "%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &games_played, &rounds_total, &comp_wins, &player_wins, &other, &jacks_or_better, &two_pair, &three_of_a_kind, &straight, &flush, &full_house, &four_of_a_kind, &straight_flush, &royal_flush);
    fclose(stats);
  }

  //Games continue until user quits.
  while (cont != 'Q' && cont != 'q') {
    games_played += 1;

    if (round > 0) {
      game = 1;
    }

    //Every game starts at 100 coins.
    coins = 100;

    //Reset game round counter.
    round = 0;

    //Start the game (get user name, print info)
    start_game(user_name, game);

    //Create deck to start
    head = create_deck();

    //Shuffle deck (obviously)
    shuffle_deck(head);

    //Loop until player runs out of coins.
    while (coins > 0) {
      rounds_total += 1;

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

      //Re-create deck if there are not enough cards.
      if (i <= 20) {
        printf("Redealing...\n");
        discard_cards(&head);

        head = create_deck();
        shuffle_deck(head);
      }

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

      //Get value of who won the round. (1 = Player wins, 0 = Computer Wins)
      win_lose = check_round_winner(player, computer, user_name);

      //Updates # of types of winning hands
      update_winning_hands(player, computer, &other, &royal_flush, &straight_flush, &four_of_a_kind, &full_house, &flush, &straight, &three_of_a_kind, &two_pair, &jacks_or_better);

      //Updates round statistics
      update_wins_stat(&player_wins, &comp_wins, win_lose);

      //Updating Coins
      effects_of_bet(win_lose, current_bet, &coins);

      //Resetting Player Hands
      discard_cards(&player);
      discard_cards(&computer);
    }

    //Update the game's stats files.
    //Originally we wanted to create a leaderboard for the longest number of rounds a person lasted, but were unable to complete in time.
    save_stats(games_played, rounds_total, comp_wins, player_wins, other, jacks_or_better, two_pair, three_of_a_kind, straight, flush, full_house, four_of_a_kind, straight_flush, royal_flush);

    //Print the end of game message and statistics, and ask player to play again.
    print_game_over();
    print_statistics(games_played, rounds_total, comp_wins, player_wins, other, jacks_or_better, two_pair, three_of_a_kind, straight, flush, full_house, four_of_a_kind, straight_flush, royal_flush);
    printf("\nDo you want to start a new game? (q to Quit): ");
    scanf(" %c", &cont);
}
  //"See you next time!". Clearly.
  printf("See you next time!");
}
