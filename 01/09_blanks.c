// Write a program to copy its input to its output, replacing each string of one
// or more blanks by a single blank.
#include <stdio.h>

int main() {
  int c, p; /* c = current, p = previous char */

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (p != ' ')
        putchar(c);
    } else {
      putchar(c);
    }

    p = c;
  }

  return 0;
}
