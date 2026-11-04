// Write a program to check a C program for rudimentary syntax errors like
// unmatched parentheses, brackets and braces. Don't forget about quotes, both
// single and double, escape sequences, and comments. (This program is hard if
// you do it in full generality.)

#define IN_CODE 1
#define IN_SINGLE_COMMENT 2
#define IN_MULTI_COMMENT 3
#define IN_CHAR 4
#define IN_STRING 5

#include <stdio.h>

int main() {
  int c, p; /* c = current, p = previous char */
  int state;
  char grouping[1000];
  int grouping_index;

  state = IN_CODE;
  grouping_index = 0;
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
      } else if (c == '\'') {
        state = IN_CHAR;
        putchar(c);
      } else if (c == '"') {
        state = IN_STRING;
        putchar(c);
      } else {
        if (p == '/') {
          putchar(p);
        }

        putchar(c);

        if (c == '(' || c == '{' || c == '[') {
          grouping[grouping_index++] = c;
        } else if (c == ')' || c == '}' || c == ']') {
          if (c == ')' && grouping[grouping_index - 1] == '(') {
            --grouping_index;
          } else if (c == '}' && grouping[grouping_index - 1] == '{') {
            --grouping_index;
          } else if (c == ']' && grouping[grouping_index - 1] == '[') {
            --grouping_index;
          }
        }
      }
    } else if (state == IN_SINGLE_COMMENT && c == '\n') {
      state = IN_CODE;
    } else if (state == IN_MULTI_COMMENT && c == '/' && p == '*') {
      state = IN_CODE;
    } else if (state == IN_CHAR) {
      putchar(c);

      if (c == '\'' && p != '\\') {
        state = IN_CODE;
      }
    } else if (state == IN_STRING) {
      putchar(c);

      if (c == '"' && p != '\\') {
        state = IN_CODE;
      }
    }

    p = c;
  }

  if (state != IN_CODE) {
    printf("Invalid syntax: open comments, chars or strings");
  } else if (grouping_index > 0) {
    printf("Invalid syntax: unpaired grouping symbols");
  } else {
    printf("Valid code!");
  }

  return 0;
}
