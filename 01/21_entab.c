//  Write a program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing. Use the same tab stops as for
// detab. When either a tab or a single blank would suffice to reach a tab stop,
// which should be given preference?

#include <stdio.h>

#define TABSTOP 4

void print_space(int count);

int main() {
  int c, p; /* c = current, p = previous char */
  int space_count;

  space_count = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++space_count;
    } else {
      if (p == ' ') {
        while (space_count >= 4) {
          putchar('\t');
          space_count = space_count - 4;
        }

        if (space_count > 0) {
          print_space(space_count);
          space_count = 0;
        }
      }

      putchar(c);
    }

    p = c;
  }

  return 0;
}

void print_space(int count) {
  while (count-- > 0)
    putchar(' ');
}
