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

//Function to shuffle a deck of 52 cards given head.
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

//Prints cards with ASCII art in a horizontal fashion given the head of a hand.
void print_cards(card *pt) {
  int i;
  int numbers[5], suits[5];

  for (i = 0; i < 5; i++) {
    numbers[i] = pt->number;
    suits[i] = pt->suit;
    pt = pt->next;
  }

  //Print tops of the cards.
  printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187, 201, 205, 205, 205, 205, 205, 187);

  //Print the second row of each card (the top left face value) and vertical card edges.
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

  //Print whitespace with vertical card edges.
  printf("%c     %c %c     %c %c     %c %c     %c %c     %c\n", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);

  //Print card suits with vertical card edges.
  for (i = 0; i < 5; i++) {
    printf("%c  %c  %c ", 186, suits[i], 186);
  }
  printf("\n");

  //Print more whitespace with vertical card edges.
  printf("%c     %c %c     %c %c     %c %c     %c %c     %c\n", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);

  //Print final face value numbers along with, you guess it, more vertical card edges.
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

  //Print bottom card edges.
  printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c\n\n", 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188, 200, 205, 205, 205, 205, 205, 188);
}

//Nearly identical to he print function directly above, but leaves the last two cards in a hand blank.
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

  //All whitespace for last two cards become  filled in, and facevalues and suits are also overwritten by the in-fill.
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

//Deal a card to a hand given the top of the deck and the head of the hand.
card *deal_card(card **head, card *hand) {
  card *temp1, *temp2, *temp3;

  //Allocate room for the card
  temp1 = (card*) malloc(sizeof(card));

  //Set value of new card from top of deck.
  temp1->number = (*head)->number;
  temp1->suit = (*head)->suit;

  //If there are not cards in hand:
  if (hand == NULL) {
    temp1->next = NULL;
    hand = temp1;
  //If there are cards in hand
  } else {
    temp2 = hand;
    //Find next empty card location.
    while(temp2->next != NULL) {
      temp2 = temp2->next;
    }
    //Fill in that card with the card created above.
    temp2->next = temp1;
    temp2 = temp2->next;
    temp2 = temp1;
    temp2->next = NULL;
  }

  //Discard that card from the top of the deck.
  temp3 = (*head);
  (*head) = (*head)->next;
  free(temp3);

  return hand;
}

//Discards a set of card and frees its memory given any head location (is used for both hands and discarding remainder of deck).
void discard_cards(card **head) {
  card *temp;

  //Frees cards until none are left to free.
  while ((*head) != NULL) {
    temp = (*head);
    (*head) = (*head)->next;
    free(temp);
  }

  //esets the head to null.
  (*head) = NULL;
}

//Function to discard a card and draw a new one from a hand based on either computer or player selections.
card *discard_and_draw(card *player, card **head, int disc[]){
  int i, j;

  card *temp;


  for (i = 0; i < 5; i++) {
    temp = player;
    //If card is marked for swapping:
    if (disc[i] == 0) {
      //Get to card location.
      for (j = 0; j < i; j++) {
        temp = temp->next;
      }

      //Swap taht value with values form the top of the deck.
      temp->number = (*head)->number;
      temp->suit = (*head)->suit;

      //Discard the card from the top of the deck.
      temp = (*head);
      (*head) = (*head)->next;
      free(temp);
    }
    //Otherwise don't do anything.
  }

  //Return pointer to the hand.
  return player;
}
