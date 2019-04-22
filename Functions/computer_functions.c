void computer_move(int disc[], card *pt) {
  int jack_count, queen_count, king_count, ace_count, max_count, i, j, score;
  card *temp, *temp2;

  //Get the value of the computer's hand.
  score = check_score(pt);

  //Reset card swap choices for computer move. (0 - DELETE CARD, 1 - KEEP CARD)
  for (i = 0; i < 5; i++) {
    disc[i] = 0;
  }

  if (score == 1) {
    temp = pt;
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

    temp = pt;
    for (i = 0; i < 5; i++) {
      if (temp->number == max_count) {
        disc[i] = 1;
      }
      temp = temp->next;
    }
  } else if (score == 2 || score == 3 || score == 7) {
    temp = pt;
    for (i = 0; i < 4; i++) {
      temp2 = temp->next;
      for (j = i + 1; j < 5; j++) {
        if (temp->number == temp2->number) {
          disc[i] = 1;
          disc[j] = 1;
        }
        temp2 = temp2->next;
      }
      temp = temp->next;
    }
  } else if (score == 4 || score == 5 || score == 6 || score == 8 || score == 9) {
    for (i = 0; i < 5; i++) {
      disc[i] = 1;
    }
  }
}
