// Write a program that prints its input one word per line.
#include <stdio.h>

/* count lines, words, and characters in input */
int main() {
  int c, p; /* c = current, p = previous char */

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (p != ' ' && p != '\n' && p != '\t')
        putchar('\n');
    } else {
      putchar(c);
    }

    p = c;
  }

  return 0;
}
