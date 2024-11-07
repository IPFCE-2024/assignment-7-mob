#include "taylor_sine.h"
#include <math.h>

double taylor_sine(double x, int n) {
  double sine = 0.0, top, bottom; // Define variables; result, numerator, demoninator
  int sign; // Define sign
  for (int k = 0; k < n; k++) { // Calculate n parts of taylor series for x
    sign = (k % 2 == 0) ? 1 : -1; // Calculate sign for part
    top = pow(x, 2 * k + 1); // Calculate x^k+1
    bottom = tgamma(2 * k + 2); // Calculate (2k+1)!
    sine += sign * top / bottom; // Add to taylor series
  }
  return sine; // Return result
}
