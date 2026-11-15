// Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
// others unchanged.

#include <stdio.h>

unsigned int invert(unsigned x, int p, int n);

int main() {
  unsigned int x = 187;
  int p = 4;
  int n = 2;

  printf("%b\n", invert(x, p, n));
  return 0;
}

unsigned int invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n) << (p - n + 1));
}
