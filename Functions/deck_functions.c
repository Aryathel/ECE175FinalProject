#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

//Creates a full deck from scratch.
card *create_deck() {
  card *head = NULL, *tail = NULL, *temp;

  //Loops through 1-13 (A, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K)
  for (int i = 1; i <= 13; i++) {

    //Loops through suit (♠, ♣, ♥, ♦)
    for (int j = 3; j<=6; j++) {

      //Allocate memory for card.
      temp = (card*)malloc(sizeof(card));

      //Assign number and suit for card.
      temp->number = i;
      temp->suit = j;

      //List linking.
      if (head == NULL) {
        head = temp;
      } else {
        tail->next = temp;
      }
      tail = temp;
      tail->next = NULL;
    }
  }
  return head;
}

card *get_tail(card *head) {
  card *temp, *tail = NULL;
  temp = head;

  while(temp->next != NULL) {
    temp = temp->next;
  }
  tail = temp;

  return tail;
}

void shuffle_deck(card *head) {
  int i, j, card1, card2;
  card *temp1, *temp2;
  int temp_num, temp_suit;

  //Swap cards 10,000 times
  for (i = 0; i < 10000; i++){
    //Start temp 1 and 2 at the first node in the linked list.
    temp1 = head;
    temp2 = head;

    //Get random cards.
    card1 = rand() % 52;
    card2 = rand() % 52;

    //Make sure card 2 is not the same as card 1.
    while (card2 == card1) {
      card2 = rand() % 52;
    }

    //Set temp1 to the proper card.
    for (j = 0; j < card1; j++){
      temp1 = temp1->next;
    }

    //Store values for card into atemporary storage
    temp_num = temp1->number;
    temp_suit = temp1->suit;

    //Set temp2 to the proper card.
    for (j = 0; j < card2; j++){
      temp2 = temp2->next;
    }

    //Swap card values.
    temp1->number = temp2->number;
    temp1->suit = temp2->suit;

    temp2->number = temp_num;
    temp2->suit = temp_suit;
  }
}

void print_cards(card *pt) {
  int i;
  int numbers[5], suits[5];

  for (i = 0; i < 5; i++) {
    numbers[i] = pt->number;
    suits[i] = pt->suit;
    pt = pt->next;
  }

  printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187);
  for (i = 0; i < 5; i++) {
    printf("%c", 186);
    switch (numbers[i]) {
      case 1:
        printf("%c", 'A');
        break;
      case 11:
        printf("%c", 'J');
        break;
      case 12:
        printf("%c", 'Q');
        break;
      case 13:
        printf("%c", 'K');
        break;
      default:
        printf("%d", numbers[i]);
        break;
    }
    if (numbers[i] != 10) {
      printf(" ");
    }
    printf("   %c ", 186);
  }
  printf("\n");

  printf("%c     %c %c     %c %c     %c %c     %c %c     %c\n", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);

  for (i = 0; i < 5; i++) {
    printf("%c  %c  %c ", 186, suits[i], 186);
  }
  printf("\n");

  printf("%c     %c %c     %c %c     %c %c     %c %c     %c\n", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);

  for (i = 0; i < 5; i++) {
    printf("%c   ", 186);
    if (numbers[i] != 10) {
      printf(" ");
    }
    switch (numbers[i]) {
      case 1:
        printf("%c", 'A');
        break;
      case 11:
        printf("%c", 'J');
        break;
      case 12:
        printf("%c", 'Q');
        break;
      case 13:
        printf("%c", 'K');
        break;
      default:
        printf("%d", numbers[i]);
        break;
    }
    printf("%c ", 186);
  }
  printf("\n");

  printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n\n", 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188);
}

void print_computer_hidden(card *pt) {
  int i;
  int numbers[3], suits[3];

  for (i = 0; i < 3; i++) {
    numbers[i] = pt->number;
    suits[i] = pt->suit;
    pt = pt->next;
  }

  printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187);
  for (i = 0; i < 3; i++) {
    printf("%c", 186);
    switch (numbers[i]) {
      case 1:
        printf("%c", 'A');
        break;
      case 11:
        printf("%c", 'J');
        break;
      case 12:
        printf("%c", 'Q');
        break;
      case 13:
        printf("%c", 'K');
        break;
      default:
        printf("%d", numbers[i]);
        break;
    }
    if (numbers[i] != 10) {
      printf(" ");
    }
    printf("   %c ", 186);
  }
  for (i = 0; i < 2; i++) {
    printf("%c%c%c%c%c%c%c ", 186, 177, 177, 177, 177, 177, 186);
  }
  printf("\n");

  printf("%c     %c %c     %c %c     %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n", 186, 186, 186, 186, 186, 186, 186, 177, 177, 177, 177, 177, 186, 186, 177, 177, 177, 177, 177, 186);

  for (i = 0; i < 3; i++) {
    printf("%c  %c  %c ", 186, suits[i], 186);
  }
  for (i = 0; i < 2; i++) {
    printf("%c%c%c%c%c%c%c ", 186, 177, 177, 177, 177, 177, 186);
  }
  printf("\n");

  printf("%c     %c %c     %c %c     %c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n", 186, 186, 186, 186, 186, 186, 186, 177, 177, 177, 177, 177, 186, 186, 177, 177, 177, 177, 177, 186);

  for (i = 0; i < 3; i++) {
    printf("%c   ", 186);
    if (numbers[i] != 10) {
      printf(" ");
    }
    switch (numbers[i]) {
      case 1:
        printf("%c", 'A');
        break;
      case 11:
        printf("%c", 'J');
        break;
      case 12:
        printf("%c", 'Q');
        break;
      case 13:
        printf("%c", 'K');
        break;
      default:
        printf("%d", numbers[i]);
        break;
    }
    printf("%c ", 186);
  }
  for (i = 0; i < 2; i++) {
    printf("%c%c%c%c%c%c%c ", 186, 177, 177, 177, 177, 177, 186);
  }
  printf("\n");

  printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n\n", 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188);

}

card *deal_card(card *head, card *hand) {
  card *temp1, *temp2;

  temp1 = (card*) malloc(sizeof(card));
  temp1->number = head->number;
  temp1->suit = head->suit;

  if (hand == NULL) {
    temp1->next = NULL;
    hand = temp1;
  } else {
    temp2 = hand;
    while(temp2->next != NULL) {
      temp2 = temp2->next;
    }
    temp2->next = temp1;
    temp2 = temp2->next;
    temp2 = temp1;
    temp2->next = NULL;
  }
  return hand;
}

card *discard_and_draw(card *player, card *head, int disc[]){
  int i, j;

  card *temp, *temp2;

  for (i = 0; i < 5; i++) {
    temp = player;
    if (disc[i] == 0) {
      for (j = 0; j < i; j++) {
        temp = temp->next;
      }

      temp->number = head->number;
      temp->suit = head->suit;

      temp2 = head;
      head = head->next;
      free(temp2);
    }
  }

  return player;
}
