// Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines.
#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int rtrim(int len, char s[]); /* remove trailing blanks and tabs */

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if ((len = rtrim(len, line)) > 0) {
      printf("%s\n", line);
    }
  }

  return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

int rtrim(int len, char s[]) {
  for (--len; s[len] == ' ' || s[len] == '\n' || s[len] == '\t'; --len)
    ;

  s[++len] = '\0';

  return len;
}
