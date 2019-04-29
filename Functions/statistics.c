#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

void save_stats(int games_played, int rounds_total, int comp_wins, int player_wins, int other, int jacks_or_better, int two_pair, int three_of_a_kind, int straight, int flush, int full_house, int four_of_a_kind, int straight_flush, int royal_flush) {
  FILE *stats = fopen("./Data/stats.txt", "w");
  fprintf(stats, "%d\n%d\n%d\n%d\n\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", games_played, rounds_total, comp_wins, player_wins, other, jacks_or_better, two_pair, three_of_a_kind, straight, flush, full_house, four_of_a_kind, straight_flush, royal_flush);
  fclose(stats);
}

void update_wins_stat(int *player_wins, int *comp_wins, int win_lose){
  if (win_lose == 1){
    *player_wins += 1;
  }
  else {
    *comp_wins += 1;
  }
}

void print_statistics(int games_played, int rounds_total, int comp_wins, int player_wins, int other, int jacks_or_better, int two_pair, int three_of_a_kind, int straight, int flush, int full_house, int four_of_a_kind, int straight_flush, int royal_flush){
  int count;

  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
  printf("%c                _____                           _____ _        _                     %c\n", 186, 186);
  printf("%c               |  __ \\                         /  ___| |      | |                    %c\n", 186, 186);
  printf("%c               | |  \\/ __ _ _ __ ___   ___     \\ `--.| |_ __ _| |_ ___               %c\n", 186, 186);
  printf("%c               | | __ / _` | '_ ` _ \\ / _ \\     `--. \\ __/ _` | __/ __|              %c\n", 186, 186);
  printf("%c               | |_\\ \\ (_| | | | | | |  __/    /\\__/ / || (_| | |_\\__ \\              %c\n", 186, 186);
  printf("%c                \\____/\\__,_|_| |_| |_|\\___|    \\____/ \\__\\__,_|\\__|___/              %c\n", 186, 186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
  printf("%c                 GENERAL                  %c              WIN PERCENTAGES             %c\n", 186, 186, 186);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);

  printf("%c", 186);
  count = num_digits(games_played);
  if (count % 2 == 1) {
    print_multi(' ', 12 - count/2);
  } else {
    print_multi(' ', 13 - count/2);
  }
  printf("Number of Games: %d", games_played);
  print_multi(' ', 12 - count/2);

  printf("%c", 186);
  count = num_digits((int) ((((double) comp_wins) / rounds_total) * 100));
  if (count % 2 == 1) {
    print_multi(' ', 12 - count/2);
  } else {
    print_multi(' ', 13 - count/2);
  }
  printf("Computer Wins: %.1lf%%", (((double) comp_wins) / rounds_total) * 100);
  print_multi(' ', 11 - count/2);
  printf("%c\n", 186);

  printf("%c", 186);
  count = num_digits(games_played);
  if (count % 2 == 1) {
    print_multi(' ', 10 - count/2);
  } else {
    print_multi(' ', 11 - count/2);
  }
  printf("Total Rounds Played: %d", rounds_total);
  print_multi(' ', 10 - count/2);

  printf("%c", 186);
  count = num_digits((int) ((((double) player_wins) / rounds_total) * 100));
  if (count % 2 == 1) {
    print_multi(' ', 13 - count/2);
  } else {
    print_multi(' ', 14 - count/2);
  }
  printf("Player Wins: %.1lf%%", (((double) player_wins) / rounds_total) * 100);
  print_multi(' ', 12 - count/2);
  printf("%c\n", 186);

  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);

  printf("%c            WINNING HAND TYPES            %c               TOP PLAYERS                %c\n", 186, 186, 186);

  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
}

//These parameters keep track of number of winning hands for each type of winning hand (ex. If the winnings score is a Full House, the # of winning Full House hands is incremented by 1).
void update_winning_hands(card *player, card *computer, int *other, int *royal_flush, int *straight_flush, int *four_of_a_kind, int *full_house, int *flush, int *straight, int *three_of_a_kind, int *two_pair, int *jacks_or_better){
  int win_score, comp_score, player_score, win_lose;

  comp_score = check_score(player);
  player_score = check_score(computer);

  if (player_score > comp_score){
    win_score = player_score;
  }
  else {
    win_score = comp_score;
  }

  switch (win_score) {
    case 0:
      *other += 1;
    case 1:
      *jacks_or_better += 1;
      break;
    case 2:
      *two_pair += 1;
      break;
    case 3:
      *three_of_a_kind += 1;
      break;
    case 4:
      *straight += 1;
      break;
    case 5:
      *flush += 1;
      break;
    case 6:
      *full_house += 1;
      break;
    case 7:
      *four_of_a_kind += 1;
      break;
    case 8:
      *straight_flush += 1;
      break;
    case 9:
      *royal_flush += 1;
      break;
  }

}
