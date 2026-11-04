// Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments don't
// nest.

#define IN_CODE 1
#define IN_SINGLE_COMMENT 2
#define IN_MULTI_COMMENT 3

#include <stdio.h>

int main() {
  int c, p; /* c = current, p = previous char */
  int state;

  state = IN_CODE;
  while ((c = getchar()) != EOF) {
    if (state == IN_CODE) {
      if (c == '/') {
        if (p == '/') {
          state = IN_SINGLE_COMMENT;
        }
      } else if (c == '*') {
        if (p == '/') {
          state = IN_MULTI_COMMENT;
        } else {
          putchar(c);
        }
      } else {
        if (p == '/') {
          putchar(p);
        }

        putchar(c);
      }
    } else if (state == IN_SINGLE_COMMENT && c == '\n') {
      state = IN_CODE;
    } else if (state == IN_MULTI_COMMENT && c == '/' && p == '*') {
      state = IN_CODE;
    }

    p = c;
  }

  return 0;
}
