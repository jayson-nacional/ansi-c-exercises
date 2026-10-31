// Write a function reverse(s) that reverses the character string s. Use it to
// write a program that reverses its input a line at a time.
#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[]);
int get_line(char s[], int lim);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }

  return 0;
}

void reverse(char s[]) {
  char temp;
  int last_index = 0;

  while (s[last_index] != '\n' && s[last_index] != '\0') {
    ++last_index;
  }

  for (int i = 0; i <= (last_index / 2); i++) {
    temp = s[i];
    s[i] = s[last_index - i];
    s[last_index - i] = temp;
  }
}

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
