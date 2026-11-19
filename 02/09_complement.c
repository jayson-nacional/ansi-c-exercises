// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
// in x. Explain why. Use this observation to write a faster version of
// bitcount.

// Explanation - The expression (x - 1) finds the first 1 bit from the rightmost
// then toggles it to 0 while toggling all remaining 0 bits to the right to 1.
// Given that we perform an & to x, all 0 bits to the right of x will remain 0.
// Therefore, to count the number of 1 bits, we just need to repeat the
// expression x &= (x - 1) until x becomes 0.

int bitcount(unsigned x);

#include <stdio.h>

int main() {
  unsigned int x = 43;
  printf("%d\n", bitcount(x));

  return 0;
}

int bitcount(unsigned x) {
  int i = 0;

  while (x != 0) {
    x &= (x - 1);
    i++;
  }

  return i;
}
