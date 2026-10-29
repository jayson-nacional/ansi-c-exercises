// Revise the main routine of the longest-line program so it will correctly
// print the length of arbitrary long input lines, and as much as possible of
// the text.
#include <stdio.h>

#define MAXLINE 1000
#define YES 1
#define NO 0

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
  int line_ended;           /* identifier whether current line has terminated */
  int prev_len;             /* current line length accumulator */
  int curr_len;             /* current line length base on get_line */
  int max;                  /* maximum length seen so far */
  char line[MAXLINE];       /* current input line */
  char line_start[MAXLINE]; /* placeholder for line start */
  char longest[MAXLINE];    /* longest line saved here */

  line_ended = YES;
  max = prev_len = 0;
  while ((curr_len = get_line(line, MAXLINE)) > 0) {
    if (line_ended) { /* store start of current line when previous ends */
      copy(line_start, line);
    }

    if (curr_len == MAXLINE - 1 && line[MAXLINE - 1] == '\0' &&
        line[MAXLINE - 2] != '\n') {
      line_ended = NO;
    } else {
      line_ended = YES;
    }

    if (line_ended) {
      curr_len = curr_len + prev_len;
      if (curr_len > max) {
        max = curr_len;
        copy(longest, line_start);
        prev_len = 0;
      }
    } else {
      prev_len = prev_len + curr_len;
    }
  }

  if (max > 0) /* there was a line */
    printf("%s", longest);

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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
