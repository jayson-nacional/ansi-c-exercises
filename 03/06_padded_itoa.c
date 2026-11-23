// Write a version of itoa that accepts three arguments instead of two. The
// third argument is a minimum field width; the converted number must be padded
// with blanks on the left if necessary to make it wide enough.

#include <stdio.h>
#include <string.h>

#define LIMIT 1000

void itoa(long n, char s[], int width);
void reverse(char s[]);

int main() {
  char s[LIMIT];
  itoa(123, s, 8);
  printf("%s\n", s);

  itoa(4579, s, 8);
  printf("%s\n", s);

  return 0;
}

void itoa(long n, char s[], int width) {
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;           /* make n positive */

  i = 0;
  do {
    s[i++] = n % 10 + '0'; /* generate digits in reverse order */
  } while ((n /= 10) > 0); /* get next digit */

  if (sign < 0)
    s[i++] = '-';

  if (width > i) { /* add blanks */
    for (width -= i; width > 0; width--)
      putchar(' ');
  }

  s[i] = '\0';

  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
