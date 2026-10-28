// Write a program to print a histogram of the lengths of words in its input. It
// is easy to draw the histogram with the bars horizontal; a vertical
// orientation is more challenging.
#include <stdio.h>

int main() {
  int c, p; /* c = current, p = previous char */
  int nc, index;
  int wlength[1000];

  for (int i = 0; i < 1000; i++)
    wlength[i] = 0;

  nc = index = 0;
  p = -1; /* later used on condition p != -1, trims starting spaces, blanks,
             newlines */
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == ' ' || c == '\t' || c == '\n') {
      if (p != ' ' && p != '\t' && p != '\n' && p != -1)
        ++index;
    } else {
      ++wlength[index];
    }

    p = c;
  }

  /* horizontal histogram */
  printf("HORIZONTAL HISTOGRAM\n");
  for (int i = 0; wlength[i] > 0; i++) {
    for (int j = 0; j < wlength[i]; j++)
      putchar('*');

    putchar('\n');
  }

  for (int i = 0; i < nc; i++)
    putchar('*');

  putchar('\n');

  /* vertical histogram */
  printf("VERTICAL HISTOGRAM\n");
  for (int i = nc; i > 0; --i) { /* iterate through length of input */
    putchar('*');                /* represent input */

    for (int j = 0; j < index; j++) { /* iterate through words */
      if (i > wlength[j])
        putchar(' ');
      else
        putchar('*');
    }

    putchar('\n');
  }

  return 0;
}
