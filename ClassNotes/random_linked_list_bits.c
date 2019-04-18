#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
  int value;
  struct node_s *next;
} node;

void find_age(node *pt, int min, int max) {
  while (pt != NULL) {
    if (pt->age < max && pt->age > min) {
      printf("%s, %d", pt->name, pt->age);
    }
    pt = pt->next;
  }
}

void print_list(node *pt) {
  while (pt != NULL) {
    printf("%d\n", pt->value);
    pt = pt->next;
  }
}

void main(void) {
  node *headp = NULL, *temp, *tail = NULL;
  int i;

  for (i = 0; i < 10; i++) {
    temp = (node*)malloc(sizeof(node));
    temp->value = i;
    if (headp == NULL) {
      headp = temp;
    } else {
      tail->next = temp;
    }
    tail = temp;
    tail->next = NULL;
  }

  print_list(headp);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
  char name[10];
  int age;
  struct node_s *next;
} node;

void main(void) {
  char name[] = "Jack";
  node *targetp = head;
  node *prev = head;
  while (targetp != NULL) {
    if (strcmp(targetp->name, name) == 0) {
      break;
    } else {
      targetp = targetp->next;
    }
  }
  if (targetp == NULL) {
    printf("There is no node with name %s.\n", name);
  } else {
    if (targetp == headp) {
      headp = headp->next;
      free(targetp);
    } else if (targetp->next != NULL) {
      prev = headp;

      while (prev->next != targetp) {
        prev = prev->next;
      }

      prev->next = targetp->next;
      free(targetp);
    } else {
      prev = headp;
      while (prev->next != targetp) {
        prev = prev->next;
      }
      tail = prev;
      tail->next = NULL;
      free(target);
    }
  }
}
