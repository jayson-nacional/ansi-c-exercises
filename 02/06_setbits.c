// Write a function setbits(x,p,n,y) that returns x with the n bits that begin
// at position p set to the rightmost n bits of y, leaving the other bits
// unchanged.

#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main() {
  unsigned int x = 615;
  unsigned int y = 38;
  int p = 5;
  int n = 3;

  printf("%b\n", setbits(x, p, n, y));
  return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
  return x | ((y & ~(~0 << n)) << (p - n + 1));
}
