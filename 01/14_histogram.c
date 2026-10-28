// Write a program to print a histogram of the frequencies of different
// characters in its input.
#include <stdio.h>

#define ASCII 255 /* ASCII standard characters */

int main() {
  int c;
  int chars[ASCII + 1];

  for (int i = 0; i <= ASCII; i++)
    chars[i] = 0;

  while ((c = getchar()) != EOF) {
    ++chars[c];
  }

  for (int i = 0; i <= ASCII; i++) {
    if (chars[i] > 0) {
      if (i == '\n') {
        printf("[\\n ]");
      } else if (i == '\t') {
        printf("[\\t ]");
      } else {
        printf("[ %c ]", i);
      }

      for (int j = 0; j < chars[i]; j++)
        putchar('*');

      putchar('\n');
    }
  }

  return 0;
}
