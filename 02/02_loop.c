// Write a loop equivalent to the for loop below without using && or ||.

/*
 for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
  int c, i;
  int lim = 1000;
  char s[lim];

  int status = TRUE;
  while (status) {
    if (i < lim - 1) {
      if ((c = getchar()) != '\n') {
        if (c == EOF) {
          status = FALSE;
        }
      } else {
        status = FALSE;
      }
    } else {
      status = FALSE;
    }

    if (status) {
      s[i++] = c;
    }
  }

  s[i] = '\0';

  printf("%s", s);

  return 0;
}
