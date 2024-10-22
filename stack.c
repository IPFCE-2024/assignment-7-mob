#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

// Function to initialize the stack
void initialize(stack *s) {
  s->head = NULL;        // The stack starts empty
}

// Function to push an element onto the stack
void push(int element, stack *s) {
    node *new_node = (node*)malloc(sizeof(node)); // Allocate memory for the new node
    assert(new_node != NULL);                     // Ensure memory allocation is successful
    new_node->data = element;                     // Set the new node's data to the element value
    new_node->next = s->head;                     // Point the new node's next to the current head
    s->head = new_node;                            // Update the head of the stack to be the new node
}

int pop(stack *s) {
    assert(!empty(s));        // Ensure the stack is not empty before popping
    node *temp = s->head;     // Store the current head node in a temporary variable
    int value = temp->data;   // Get the value from the node to return
    s->head = temp->next;     // Move the head to the next node in the stack
    free(temp);               // Free the memory allocated for the old head node
    return value;             // Return the value from the popped node
}

bool empty(stack *s) {
  return s->head == NULL; // Return true if the head is NULL, indicating the stack is empty
}

// Function to check if the stack is full (always returns false for a linked list implementation)
bool full(stack *s) {
    return false; // A linked list implementation of a stack is never full unless memory is exhausted
}
