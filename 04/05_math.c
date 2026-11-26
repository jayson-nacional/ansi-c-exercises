// Add access to library functions like sin, exp, and pow.

#include <math.h>
#include <stdio.h>

double sin(double x);
double pow(double x, double y);

int main() {
  double x = 10.3;
  printf("Sine: %f\n", sin(x));

  double b = 3;
  printf("Exp: %f\n", exp(b));

  double c = 2;
  double d = 8;
  printf("Pow: %f\n", pow(c, d));

  return 0;
}
