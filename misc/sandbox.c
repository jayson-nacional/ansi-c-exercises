#include <stdio.h>

int main() {
  unsigned int num = ~(~0 << 2);
  printf("%b\n", num);
  printf("%b\n", 0177 >> 3);
  return 0;
}
