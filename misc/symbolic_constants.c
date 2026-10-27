#include <stdio.h>

#define LOWER 0   /* lower limit of temperature scale */
#define UPPER 300 /* upper limit */
#define STEP 20   /* step size */

int main() {
  float fahr, celsius;

  printf("Fahr Celsius\n");
  fahr = UPPER;
  while (fahr >= LOWER) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%4.0f %7.1f\n", fahr, celsius);
    fahr = fahr - STEP;
  }

  return 0;
}
