#ifndef __TYPES_H
#define __TYPES_H

typedef struct cards{
  int number; //1-13
  int suit; //3, 4, 5, 6 (♠, ♣, ♥, ♦)
  struct cards *next;
} card;

#endif
