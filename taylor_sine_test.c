#include <stdio.h>
#include <math.h>         // For the ANSI C sin function
#include "taylor_sine.h"  // Include the custom sine function

int main() {
    // Array of test values for x (small and large values)
    double test_values[] = {0.0, M_PI / 6, M_PI / 4, M_PI / 2, M_PI, 2 * M_PI, 10.0, 100.0};
    int n_terms = 10; // Number of terms for the Taylor series approximation

    // Iterate through the test values
    for (int i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++) {
        double x = test_values[i];
        double taylor_result = taylor_sine(x, n_terms); // Calculate using Taylor series
        double math_result = sin(x); // Calculate using ANSI C sin function

        // Print the results for comparison
        printf("x = %.2f\n", x);
        printf("Taylor series result: %.8f\n", taylor_result);
        printf("ANSI C sin result: %.8f\n", math_result);
        printf("Difference: %.8f\n\n", fabs(taylor_result - math_result));
    }

    return 0;
}

/* 1. c) answer
1. Which intervals of input x did your function give a similar result to the ANSI C sin function?

   - The Taylor series approximation gives similar results to the ANSI C sin function when x is small, 
     specifically in the range of -2π to 2π. For these values, the difference between the Taylor series 
     result and the ANSI C sin function result is very small (often close to zero).
   - For larger values of x (e.g., x = 10.0 or x = 100.0), the Taylor series approximation starts to deviate 
     significantly from the ANSI C sin function. This is because the Taylor series converges slowly for larger 
     input values, and more terms are needed for accurate results.

2. What impact did increasing the precision have (i.e., increasing the number of Taylor series terms)?

   - Increasing the number of terms (n_terms) in the Taylor series improves the accuracy of the approximation. 
     For smaller values of x, even a few terms (e.g., n_terms = 5) yield accurate results. 
     However, for larger values of x, increasing the number of terms (e.g., n_terms = 20 or more) is necessary 
     to reduce the difference between the Taylor series result and the ANSI C sin function.
   - The more terms included, the more accurate the result becomes, but at the cost of increased computation time. 
     There's a balance between accuracy and efficiency when choosing the number of terms for different input ranges.
*/ 
