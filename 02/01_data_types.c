// Write a program to determine the ranges of char, short, int, and long
// variables, both signed and unsigned, by printing appropriate values from
// standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types.

#include <float.h>
#include <limits.h>
#include <stdio.h>

int ipower(int base, int exponent);
long lpower(long base, long exponent);

int main() {
  printf("\n*********************************\n");

  printf("\n--- CHAR ---\n");
  printf("Signed min: %d\n", CHAR_MIN);
  printf("Signed max: %d\n", CHAR_MAX);
  printf("Unsigned min: %d\n", 0);
  printf("Unsigned max: %d\n", UCHAR_MAX);

  printf("\n--- CHAR computed ---\n");
  printf("Signed min: %d\n", -ipower(2, 7));
  printf("Signed max: %d\n", ipower(2, 7) - 1);
  printf("Unsigned min: %d\n", 0);
  printf("Unsigned max: %d\n", ipower(2, 8) - 1);

  printf("\n*********************************\n");

  printf("\n--- SHORT ---\n");
  printf("Signed min: %d\n", SHRT_MIN);
  printf("Signed max: %d\n", SHRT_MAX);
  printf("Unsigned min: %d\n", 0);
  printf("Unsigned max: %d\n", USHRT_MAX);

  printf("\n--- SHORT computed ---\n");
  printf("Signed min: %d\n", -ipower(2, 15));
  printf("Signed max: %d\n", ipower(2, 15) - 1);
  printf("Unsigned min: %d\n", 0);
  printf("Unsigned max: %d\n", ipower(2, 16) - 1);

  printf("\n*********************************\n");

  printf("\n--- INT ---\n");
  printf("Signed min: %d\n", INT_MIN);
  printf("Signed max: %d\n", INT_MAX);
  printf("Unsigned min: %d\n", 0);
  printf("Unsigned max: %ld\n", UINT_MAX);

  printf("\n--- INT computed ---\n");
  printf("Signed min: %d\n", -ipower(2, 31));
  printf("Signed max: %d\n", ipower(2, 31) - 1);
  printf("Unsigned min: %d\n", 0);
  printf("Unsigned max: %ld\n", lpower(2, 32) - 1);

  printf("\n*********************************\n");

  printf("\n--- LONG ---\n");
  printf("Signed min: %ld\n", LONG_MIN);
  printf("Signed max: %ld\n", LONG_MAX);
  printf("Unsigned min: %d\n", 0);
  printf("Unsigned max: %lu\n", ULONG_MAX);

  printf("\n--- LONG computed ---\n");
  printf("Signed min: %ld\n", -lpower(2, 63));
  printf("Signed max: %ld\n", lpower(2, 63) - 1);
  printf("Unsigned min: %d\n", 0);
  printf("Unsigned max: %lu\n", lpower(2, 64) - 1);

  printf("\n*********************************\n");

  printf("\n--- FLOAT ---\n");
  printf("Min: %f\n", FLT_MIN);
  printf("Max: %f\n", FLT_MAX);

  return 0;
}

int ipower(int base, int exponent) {
  int result = 1;

  while (exponent-- > 0) {
    result = result * base;
  }

  return result;
}

long lpower(long base, long exponent) {
  long result = 1;

  while (exponent-- > 0) {
    result = result * base;
  }

  return result;
}
