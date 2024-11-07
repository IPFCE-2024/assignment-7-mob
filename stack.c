#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void initialize(stack *s) {
  s->head = NULL; // Initialize stack head
}

void push(int x, stack *s) {
  node *new = (node *)malloc(sizeof(node)); // create new node
  new->data = x; // Add data to new node
  new->next = s->head; // Set next to NULL
  s->head = new; // Point header to newest node
}

int pop(stack *s) {
  // implement pop here
  if (s->head == NULL) {
    return -1;
  }
  int pop_value = s->head->data; // Variable for value stored in popped node
  node *temp = s->head; // Save pointer for node for free()
  s->head = s->head->next; // Set header to point to new newest
  free(temp); // Free memory from popped node
  return pop_value; // Return popped value
}

bool empty(stack *s) {
  return s->head == NULL; // Return wether empty
}

bool full(stack *s) {
  // implement full here
  return false; // The stack cant be full.
}

int main(void) {
    stack *s = malloc(sizeof(stack));
    initialize(s);
    if (empty(s)) {
        printf("1: Test passed: stack is empty\n");
    }

    int x = 2;
    int y = x;
    push(x, s);
    if (pop(s) == y) {
        printf("2: Test passed: x is equal to y\n");
    }

    int x0 = 2;
    int x1 = 3;
    int y0 = x1;
    int y1 = x0;
    push(x0, s);
    push(x1, s);
    if (pop(s) == y0) {
        printf("3: Test passed: x1 is equal to y0\n");
    }
    if (pop(s) == y1) {
        printf("4: Test passed: x0 is equal to y1\n");
    }
    return 0;
}