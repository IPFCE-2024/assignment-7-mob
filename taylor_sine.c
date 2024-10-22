#include "taylor_sine.h"
#include <math.h>

// Function to calculate the factorial of a number
double factorial(int num) {
    double result = 1.0; // Initialize result to 1.0 since factorial of 0 is 1
    for (int i = 1; i <= num; i++) { // Loop from 1 to num
        result *= i; // Multiply result by i in each iteration
    }
    return result; // Return the calculated factorial value
}

// Function to calculate sine using the Taylor series
double taylor_sine(double x, int n) {
    double sine_value = 0.0; // Initialize the sine value to 0.0
    for (int i = 0; i < n; i++) { // Loop to calculate each term of the Taylor series
        int term_index = 2 * i + 1; // Calculate the exponent for the term (1, 3, 5, ...)
        // Calculate the value of the term:
        // (i % 2 == 0 ? 1 : -1) decides the sign based on whether the index is even or odd
        // pow(x, term_index) calculates x raised to the power of term_index
        // factorial(term_index) calculates the factorial of term_index
        double term = (i % 2 == 0 ? 1 : -1) * (pow(x, term_index) / factorial(term_index));
        sine_value += term; // Add the term value to sine_value
    }

  return sine_value;
}


