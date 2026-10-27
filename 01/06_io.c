// Verify that the expression getchar() != EOF is 0 or 1.
#include <stdio.h>

int main() {
  int c;
  int d;

  while ((d = ((c = getchar()) != EOF))) {
    printf("The expression getchar() != EOF is %d\n", d);
  }

  printf("The expression getchar() != EOF is %d\n", d);

  return 0;
}
