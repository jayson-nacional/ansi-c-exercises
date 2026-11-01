// Write a program to ``fold'' long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of
// input. Make sure your program does something intelligent with very long
// lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>

#define FOLD_LIMIT 10

int get_line(int start, char s[], int lim);
int gbreak_index(char s[], int len);

int main() {
  int len, prev_len; /* prev_len validates whether dash(-) is required */
  int starting_index;
  int break_index;
  char line[FOLD_LIMIT + 1];

  starting_index = 0;
  while ((len = get_line(starting_index, line, FOLD_LIMIT + 1)) > 0) {
    if (len == FOLD_LIMIT) {
      break_index = gbreak_index(line, len);
      line[break_index] = '\0';
      printf("%s", line);

      if (break_index > 0) {
        ++break_index;
        for (starting_index = 0; line[break_index] != '\0'; break_index++) {
          line[starting_index++] = line[break_index];
        }
      } else {
        starting_index = 0;
      }

      putchar('\n');
      prev_len = len;
    } else {
      if (len == 1 && line[0] == '\n')
        ; // do nothing
      else {
        if (prev_len == FOLD_LIMIT)
          putchar('-');

        printf("%s\n", line);
        starting_index = 0;
      }
    }
  }

  return 0;
}

int get_line(int start, char s[], int lim) {
  int c, i;
  for (i = start; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

int gbreak_index(char s[], int len) {
  while (s[--len] != ' ' && len >= 0)
    ;

  return len;
}
