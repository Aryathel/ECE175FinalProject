void computer_move(int disc[], int score, card *pt) {
  int jack_count, queen_count, king_count, ace_count, max_count;
  card *temp;


  if (score == 0) {
    for (i = 0; i < 5; i++) {
      disc[i] = 0;
    }
  } else if (score == 1) {
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
      if (temp->number != max_count) {
        disc[i] = 0;
      }
    }
  } else if (score == 2) {
    break;
  }
}
