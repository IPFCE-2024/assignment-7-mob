#include <taylor_sine.h>
#include <math.h>
#include <stdio.h>

int main(void) {
    double pi = 3.14; // define pi
    
    printf("sin(pi)= %lf\n", sin(pi));
    printf("taylor_sine(pi)= %lf\n", taylor_sine(pi, 10));

    return 0;
}