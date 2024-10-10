#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void initialize(stack *s) {

s->head = NULL; // Sætter head til NULL, hvilket betyder at stacken er tom.
  
}

void push(int x, stack *s) {
  // Opret en ny node og alloker hukommelse til den
    node *new_node = malloc(sizeof(node));

    // Indsæt element på toppen af stacken
    new_node->data = x;

    // Den nye node peger på den nuværende head (eller tidligere top af stacken)
    new_node->next = s->head;

    // Opdater head(top) til at pege på den nye node
    s->head = new_node; 
}

int pop(stack *s) {
   if (s->head == NULL) // Tjek om stacken er tom
    {
        printf("Stack is empty\n"); // Udskriv
        return -1; // Retuner ingenting hvis tom
    }
    
    node *temp = s->head;  // Gemmer en midlertidig pointer til den nuværende top-node
    int value = temp->data;  // Gemmer dataen fra den nuværende top-node

    s->head = s->head->next;  // Opdaterer head til at pege på den næste node (Den under den nuværende)
    free(temp);  // Frigør hukommelsen for den gamle top-node

    return value;  // Returner den værdi, der blev poppet fra stacken
}

bool empty(stack *s) {
  return s->head == NULL; // Retunuer true/false afhængigt om stacken er tom eller ej
}

bool full(stack *s) {
   node *new_node = malloc(sizeof(node)); // opret ny node og allokker hukommelse til den

    if (new_node == NULL) // Tjek om malloc har retuneret NULL (dvs. ikke mere plads i hukommelsen)
    {


        return true; // Retuner true for at stacken er fuld
    }
    
    free(new_node); // Hvis ikke så frigør pladsen i hukommelsen igen
    return false; // Retuner false 
}
