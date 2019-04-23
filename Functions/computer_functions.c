//Function to make the computer keep or discard cards based on what it has in its hand currently.
void computer_move(int disc[], card *pt) {
  int jack_count, queen_count, king_count, ace_count, max_count, i, j, score;
  card *temp, *temp2;

  //Get the value of the computer's hand.
  score = check_score(pt);

  //Reset card swap choices for computer move. (0 - DELETE CARD, 1 - KEEP CARD)
  for (i = 0; i < 5; i++) {
    disc[i] = 0;
  }

  //Act for Jacks of Better case (hold the pair that is a Jack or Better, discard everything else.)
  if (score == 1) {
    temp = pt;
    //Figure out which card is making up the pair (Jakcs, Queens, Kings, or Aces).
    for (i = 0; i < 5; i++) {
      if (temp->number == 11) {
        jack_count += 1;
      } else if (temp->number == 12) {
        queen_count += 1;
      } else if (temp->number == 13) {
        king_count += 1;
      } else if (temp->number == 1) {
        ace_count += 1;
      }
      temp = temp->next;
    }

    if (jack_count > queen_count && jack_count > king_count && jack_count > ace_count) {
      max_count = 11;
    } else if (queen_count > jack_count && queen_count > king_count && queen_count > ace_count){
      max_count = 12;
    } else if (king_count > jack_count && king_count > queen_count && king_count > ace_count) {
      max_count = 13;
    } else {
      max_count = 1;
    }

    //Creating the array to keep the important pair and discard everything else.
    temp = pt;
    for (i = 0; i < 5; i++) {
      if (temp->number == max_count) {
        disc[i] = 1;
      }
      temp = temp->next;
    }
  //Case for Two Pair, Three of a Kind, or for Four of a Kind (Keep the two pairs, three of a kind, or four of a kind.)
  //For each of these cases the only time a card is repeated is if it is to fulfill part of the requirements for each case,
  //so keep all repeated cards.
  } else if (score == 2 || score == 3 || score == 7) {
    temp = pt;
    for (i = 0; i < 4; i++) {
      temp2 = temp->next;
      for (j = i + 1; j < 5; j++) {
        //If the number is repeated at any point further on, keep both of those cards.
        if (temp->number == temp2->number) {
          disc[i] = 1;
          disc[j] = 1;
        }
        temp2 = temp2->next;
      }
      temp = temp->next;
    }
  //Case for Straight, Flush, Full House, Straight Flush, and Royal Flush (Keep all of the cards)
  } else if (score == 4 || score == 5 || score == 6 || score == 8 || score == 9) {
    for (i = 0; i < 5; i++) {
      disc[i] = 1;
    }
  }
}
