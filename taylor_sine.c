#include "taylor_sine.h"

double taylor_sine(double x, int n) {
  double taylor_sum = 0; 
  double term = x; // Første term er x (da x^1 / 1! = x)
    
  int sign = 1; // Fortegnet starter som positivt for første term
  double fact_value = 1; // Start med 1! = 1

    for (int i = 0; i < n; i++) {
       // Tilføj den aktuelle term til summen af Taylor-serien
       //int factorial = fact((2*i) + 1);
       taylor_sum += sign * (term/ fact_value); 

       // Opdater potensen af x: Hver iteration ganger x med x^2
       term *=  x*x; 

       // Skift fortegn for næste term
       sign = -sign; 
       
       // Beregn næste faktorialværdi (2i + 1)! ved at gange de to næste tal i rækken
       fact_value *= (2*i + 2) * (2*i + 3);
    }

    return taylor_sum; // Returner den samlede sum af Taylor-serien
}
