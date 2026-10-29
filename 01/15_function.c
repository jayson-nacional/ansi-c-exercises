// Rewrite the temperature conversion program of Section 1.2 to use a function
// for conversion.
#include <stdio.h>

float fahr_to_cel(float fahr);

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;   /* lower limit of temperature scale */
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  printf("Fahr Celsius\n");
  fahr = lower;
  while (fahr <= upper) {
    celsius = fahr_to_cel(fahr);
    printf("%4.0f %7.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}

float fahr_to_cel(float fahr) { return (5.0 / 9.0) * (fahr - 32.0); }
