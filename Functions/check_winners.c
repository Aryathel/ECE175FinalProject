#include <stdio.h>
#include "types.h"

int check_score(card *pt) {
  int score = 0, i, j, jack_count, pair_count, three_count, straight_count, four_count, royal_count, temp_num, temp_suit;
  int numbers[5], suits[5];

  //Read cards into two arrays, for numbers and suits.
  for (i = 0; i < 5; i++) {
    numbers[i] = pt->number;
    suits[i] = pt->suit;
    pt = pt->next;
  }

  for (i = 0; i < 4; i++) {
    for (j = i+1; j < 5; j++) {
      if (numbers[i] > numbers[j]) {
        temp_num = numbers[i];
        temp_suit = suits[i];

        numbers[i] = numbers[j];
        suits[i] = suits[j];

        numbers[j] = temp_num;
        suits[j] = temp_suit;
      }
    }
  }

  //Check for Jacks or Better Case.
  jack_count = 0;
  for (i = 0; i < 5; i++) {
    if (numbers[i] == 11) {
      jack_count += 1;
    }
  }
  if (jack_count >= 2) {
    score = 1;
    printf("Jacks or Better");
  }

  //Check for Two Pair Case.
  pair_count = 0;
  for (i = 0; i < 4; i++) {
    for (j = i + 1; j < 5; j++) {
      if (numbers[i] == numbers[j]) {
        pair_count += 1;
      }
    }
  }
  if (pair_count >= 2) {
    score = 2;
    printf("Two Pair");
  }

  //Check for Three of a Kind Case.
  for (i = 0; i < 3; i++) {
    three_count = 1;
    for (j = i + 1; j < 5; j++) {
      if (numbers[i] == numbers[j]) {
        three_count += 1;
      }
    }
    if (three_count >= 3) {
      score = 3;
      printf("Three of a Kind");
    }
  }

  //Check for Straight Case.
  straight_count = 0;
  for (i = 0; i < 4; i++) {
    if ((numbers[i] + 1) == numbers[i+1]) {
      straight_count += 1;
    }
  }
  if (straight_count >= 4) {
    score = 4;
    printf("Straight");
  }

  //Check for Flush Case.
  if (suits[0] == suits[1] == suits[2] == suits[3] == suits[4] == suits[5]) {
    score = 5;
    printf("Flush");
  }

  //Check for Full House Case.
  for (i = 2; i < 5; i++) {
    if (numbers[i] == numbers[i-1] == numbers[i-2]) {
      for (j = 1; j < 5; j++){
        if (numbers[j] != numbers[i] && numbers[j] == numbers[j-1]){
          score = 6;
          printf("Full House");
        }
      }
    }
  }

  //Check for Four of a Kind Case.
  four_count = 0;
  for (i = 0; i < 2; i++) {
    for (j = i + 1; j < 5; j++) {
      if (numbers[i] == numbers[j]) {
        four_count += 1;
      }
    }
    if (four_count >= 4){
      score = 7;
      printf("Four of a Kind");
    }
  }

  //Check for Straight Flush Case.
  straight_count = 0;
  for (i = 0; i < 4; i++) {
    if ((numbers[i] + 1) == numbers[i+1]) {
      straight_count += 1;
    }
  }
  if ((straight_count >= 4) && (suits[0] == suits[1] == suits[2] == suits[3] == suits[4] == suits[5])) {
    score = 8;
    printf("Straight Flush");
  }

  //Check for a Royal Flush Case.
  if ((numbers[0] == 1) && (numbers[1] == 10) && (numbers[2] == 11) && (numbers[3] == 12) && (numbers[4] == 13) && (suits[0] == suits[1] == suits[2] == suits[3] == suits[4] == suits[5])) {
    score = 9;
    printf("Royal Flush");
  }

  return score;
}

int check_round_winner(card *player, card *computer, char user_name[]) {
  int player_score, computer_score;

  printf("Computer's Hand: (");
  computer_score = check_score(computer);
  printf(")\n");
  print_cards(computer);

  printf("%s's Hand: (", user_name);
  player_score = check_score(player);
  printf(")\n");
  print_cards(player);

  if (computer_score < player_score) {
    return 0;
  } else {
    return 1;
  }
}
