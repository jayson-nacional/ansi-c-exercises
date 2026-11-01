// Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
// every n columns. Should n be a variable or a symbolic parameter?

#include <stdio.h>

#define TABSTOP 4

void print_space(int count);

int main() {
  int c, cursor_index;

  cursor_index = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      cursor_index = 0;
    else if (c == '\t') {
      print_space(TABSTOP - cursor_index);
      cursor_index = 0;
    } else {
      putchar(c);
      ++cursor_index;

      if (TABSTOP == cursor_index)
        cursor_index = 0;
    }
  }

  return 0;
}

void print_space(int count) {
  while (count-- > 0)
    putchar(' ');
}
