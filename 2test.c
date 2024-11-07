#include "stack.h"
#include <stdio.h>

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