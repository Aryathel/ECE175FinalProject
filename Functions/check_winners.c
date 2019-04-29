#include <stdio.h>
#include "types.h"

//Function to sort a hand of cards into two arrays (one for face value, one for suit) and then sort those arrays from
//Least to greatest.
void sort_cards(int numbers[], int suits[], card *pt) {
  int temp_num, temp_suit, i, j;

  //Read hand into arrays.
  for (i = 0; i < 5; i++) {
    numbers[i] = pt->number;
    suits[i] = pt->suit;
    pt = pt->next;
  }

  //Sort the arrays based on face value (making sure that numbers[i] will have its suit correspondingly stored in suits[i])
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
}

//Function to get the value of the hand from the head pointer of the hand.  This function works by assigning an integer
//value to eaach hand, a "score". If the hand does not match any winning cases, it is scored at 0. Jacks or Better is 1,
//Two Pair is 2, and so on until Royal Flush is 9. Then the score is returned.
int check_score(card *pt) {
  int score = 0, i, j, jack_count, queen_count, king_count, ace_count, pair_count, three_count, straight_count, four_count, royal_count;
  int numbers[5], suits[5];

  //Read cards into two arrays, for numbers and suits, and sort by face value (least to greatest).
  sort_cards(numbers, suits, pt);

  //Check for Jacks or Better Case.
  jack_count = 0;
  queen_count = 0;
  king_count = 0;
  ace_count = 0;
  for (i = 0; i < 5; i++) {
    if (numbers[i] == 11) {
      jack_count += 1;
    } else if (numbers[i] == 12) {
      queen_count += 1;
    } else if (numbers[i] == 13) {
      king_count += 1;
    } else if (numbers[i] == 1) {
      ace_count += 1;
    }
  }
  if (jack_count >= 2 || queen_count >= 2 || king_count >= 2 || ace_count >= 2) {
    score = 1;
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
  }

  //Check for Flush Case.
  if (suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] && suits[3] == suits[4] && suits[4] == suits[5]) {
    score = 5;
  }

  //Check for Full House Case.
  for (i = 2; i < 5; i++) {
    if (numbers[i] == numbers[i-1] && numbers[i-1] == numbers[i-2]) {
      for (j = 1; j < 5; j++){
        if (numbers[j] != numbers[i] && numbers[j] == numbers[j-1]){
          score = 6;
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
    }
  }

  //Check for Straight Flush Case.
  straight_count = 0;
  for (i = 0; i < 4; i++) {
    if ((numbers[i] + 1) == numbers[i+1]) {
      straight_count += 1;
    }
  }
  if ((straight_count >= 4) && (suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] && suits[3] == suits[4] && suits[4] == suits[5])) {
    score = 8;
  }

  //Check for a Royal Flush Case.
  if ((numbers[0] == 1) && (numbers[1] == 10) && (numbers[2] == 11) && (numbers[3] == 12) && (numbers[4] == 13) && (suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] && suits[3] == suits[4] && suits[4] == suits[5])) {
    score = 9;
  }

  return score;
}

//Prints the string that shows the players what each hand has, based on given score.
void print_hand_type(int score) {
  switch (score) {
    case 1:
      printf("Jacks or Better");
      break;
    case 2:
      printf("Two Pair");
      break;
    case 3:
      printf("Three of a Kind");
      break;
    case 4:
      printf("Straight");
      break;
    case 5:
      printf("Flush");
      break;
    case 6:
      printf("Full House");
      break;
    case 7:
      printf("Four of a Kind");
      break;
    case 8:
      printf("Straight Flush");
      break;
    case 9:
      printf("Royal Flush");
      break;
    default:
      break;
  }
}

//Function to break a tie given the two hands and the hand value (both hands have same value, hence the tie).
int break_tie(card *player, card *computer, int score) {
  int player_nums[5], player_suits[5], computer_nums[5], computer_suits[5];
  int max_comp_face, max_comp_suit, max_player_face, max_player_suit, i;

  //Create two arrays for each hands, to store face value and suit, sorted in order of increasing face value.
  sort_cards(player_nums, player_suits, player);
  sort_cards(computer_nums, computer_suits, computer);

  //Since out suits are stored as 3, 4, 5, 6 = ♠, ♣, ♥, ♦, but the priority for tie breakers goes ♣ < ♦ < ♥ < ♠ = 4 < 6 < 5 < 3,
  //I overwrite the suit values with new values in order to easily determine priority in this function. This ia another advantage of creating a standalone array.
  for (i = 0; i < 5; i++) {
    //4 6 5 3
    if (computer_suits[i] == 3) {
      computer_suits[i] = 6;
    } else if (computer_suits[i] == 4) {
      computer_suits[i] = 3;
    } else if (computer_suits[i] == 6) {
      computer_suits[i] = 4;
    }
  }

  //Just some pre-definitions for ease of access later on.
  max_comp_face = computer_nums[0];
  max_comp_suit = computer_suits[0];
  max_player_face = player_nums[0];
  max_player_suit = player_suits[0];

  if (score == 0) {
    //If this is the case, the player did not get Jacks or Better, so they lose.
    return 0;
  } else if (score == 1 || score == 2) {
    //Handles the Jacks or Better or the Two Pair tie case.
    //Find the max face value for each hand that is in a pair. Set the max suit value for each hand to the suit at the same index.
    for (i = 0; i < 4; i++) {
      if (computer_nums[i] == computer_nums[i+1] && (computer_nums[i] > max_comp_face || computer_nums[i] == 1)) {
        max_comp_face = computer_nums[i];
        max_comp_suit = computer_suits[i];
      }
      if (player_nums[i] == player_nums[i+1] && (player_nums[i] > max_player_face || computer_nums[i] == 1)) {
        max_player_face = player_nums[i];
        max_player_suit = player_suits[i];
      }
    }

    //Handling results:
    //If max computer value > max player value, computer wins. If vice versa, player wins. If tied, same but with suit values.
    //Similar handlers like this will be used in every case.
    if (max_comp_face > max_player_face || (max_comp_face == 1 && max_player_face != 1)) {
      return 0;
    } else if (max_comp_face == max_player_face) {
      if (max_comp_suit > max_player_suit) {
        return 0;
      } else {
        return 1;
      }
    } else {
      return 1;
    }
  } else if (score == 3) {
    //Handles Three of a Kind case.
    //Get max face values (the three of a kind value). Suit values are unnecessary.
    for (i = 0; i < 4; i++) {
      if (computer_nums[i] == computer_nums[i+1]) {
        max_comp_face = computer_nums[i];
      }
      if (player_nums[i] == player_nums[i+1]) {
        max_player_face = player_nums[i];
      }
    }

    //Handle results from max values.
    if (max_comp_face > max_player_face || (max_comp_face == 1 && max_player_face != 1)) {
      return 0;
    } else {
      return 1;
    }
  } else if (score == 4) {
    //Handles Straight case.
    //Get max face and suit values again.
    for (i = 0; i < 5; i++) {
      if (computer_nums[i] > max_comp_face || computer_nums[i] == 1) {
        max_comp_face = computer_nums[i];
        max_comp_suit = computer_suits[i];
      }
      if (player_nums[i] > max_player_face || player_nums[i] == 1) {
        max_player_face = player_nums[i];
        max_player_suit = player_suits[i];
      }
    }

    //Handle them based on the Straight case.
    if (max_comp_face > max_player_face || (max_comp_face == 1 && max_player_face != 1)) {
      return 0;
    } else if (max_comp_face == max_player_face) {
      if (max_comp_suit > max_player_suit) {
        return 0;
      } else {
        return 1;
      }
    } else {
      return 1;
    }
  } else if (score == 5) {
    //Handles Flush case.
    //Get max values.
    for (i = 0; i < 5; i++) {
      if (computer_nums[i] > max_comp_face || computer_nums[i] == 1) {
        max_comp_face = computer_nums[i];
        max_comp_suit = computer_suits[i];
      }
      if (player_nums[i] > max_player_face || player_nums[i] == 1) {
        max_player_face = player_nums[i];
        max_player_suit = player_suits[i];
      }
    }

    //Return winner based on Flush case.
    if (max_comp_suit > max_player_suit) {
      return 0;
    } else if (max_comp_suit == max_player_suit){
      if (max_comp_face > max_player_face || (max_comp_face == 1 && max_player_face != 1)   ) {
        return 0;
      } else {
        return 1;
      }
    } else {
      return 1;
    }
  } else if (score == 6) {
    //Handles Full House case.
    //Get max face value (don't care about suit).
    for (i = 0; i < 3; i++) {
      if (player_nums[i] == player_nums[i+1] && player_nums[i+1] == player_nums[i+2]) {
        max_player_face = player_nums[i];
      }
      if (computer_nums[i] == computer_nums[i+1] && computer_nums[i+1] == computer_nums[i+2]) {
        max_comp_face = computer_nums[i];
      }
    }

    //Return values.
    if (max_comp_face > max_player_face || max_comp_face == 1) {
      return 0;
    } else {
      return 1;
    }
  } else if (score == 7) {
    //Handles Four of a Kind case.
    //Get value of four of a kind.
    for (i = 0; i < 5; i++) {
      if (computer_nums[i] > max_comp_face || computer_nums[i] == 1) {
        max_comp_face = computer_nums[i];
      }
      if (player_nums[i] > max_player_face || player_nums[i] == 1) {
        max_player_face = player_nums[i];
      }
    }

    //Return winner.
    if (max_comp_face > max_player_face) {
      return 0;
    } else {
      return 1;
    }
  } else if (score == 8) {
    //Handles Straight Flush case.
    //Set max values (easy, because Ace will never be the highest value here, only lowest - if Ace is highest, its a Royal Flush)
    max_comp_face = computer_nums[4];
    max_comp_suit = computer_suits[4];
    max_player_face = player_nums[4];
    max_player_suit = player_suits[4];

    //Handle the results.
    if (max_comp_face > max_player_face) {
      return 0;
    } else if (max_comp_face == max_player_face) {
      if (max_comp_suit > max_player_suit) {
        return 1;
      } else {
        return 0;
      }
    } else {
      return 1;
    }
  } else if (score == 9) {
    //Handles Royal Flush case (the only deciding factor is suit here).
    max_comp_suit = computer_suits[0];
    max_player_suit = player_suits[0];

    //Return result.
    if (max_comp_suit > max_player_suit) {
      return 0;
    } else {
      return 1;
    }
  }
}

//Implements the above functions to check the score of the round given the head points for the player and the computer,
//as well as the username (for the sake of printing cleanly).
int check_round_winner(card *player, card *computer, char user_name[]) {
  int player_score, computer_score, win_lose;

  //Print Computer hand's cards after swaps (in full, not hidden), and what hand type it had.
  printf("Computer's Hand: (");
  computer_score = check_score(computer);
  print_hand_type(computer_score);
  printf(")\n");
  print_cards(computer);

  //Print player's hand after card swaps, as well as the hand type.
  printf("%s's Hand: (", user_name);
  player_score = check_score(player);
  print_hand_type(player_score);
  printf(")\n");
  print_cards(player);

  //Returns 0 if the computer wins, or 1 if the player wins.
  if (computer_score > player_score) {
    return 0;
  } else if (computer_score == player_score){
    win_lose = break_tie(player, computer, computer_score);
    return win_lose;
  } else {
    return 1;
  }
}
