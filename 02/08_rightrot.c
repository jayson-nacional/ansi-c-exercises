// Write a function rightrot(x,n) that returns the value of the integer x
// rotated to the right by n positions.

#include <stdio.h>

int bit_count(unsigned int x);
unsigned int rightrot(unsigned int x, int n);

int main() {
  unsigned int x = 311;
  printf("%b\n", rightrot(x, 3));

  return 0;
}

unsigned int rightrot(unsigned int x, int n) {
  int b_count = bit_count(x);

  while (n-- > 0) {
    if ((x >> (b_count - 1)) == 1) {
      x = (x >> 1) ^ (1 << (b_count - 1));
    } else {
      x = x >> 1;
    }
  }

  return x;
}

int bit_count(unsigned int x) {
  int i = 0;
  while (x != 0) {
    x = x >> 1;
    i++;
  }

  return i;
}
