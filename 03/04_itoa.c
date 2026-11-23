// In a two's complement number representation, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to
// -(2^wordsize-1). Explain why not. Modify it to print that value correctly,
// regardless of the machine on which it runs.

/* Explanation: The function itoa first converts negative number to a positive
 * equivalent. The negative min however exceeds the type capacity that an int
 * can hold when converted to positive. To print the value correctly, the
 * parameter that itoa accepts needs to be a long integer so that it is able to
 * hold the converted min value.
 */

#include <limits.h>
#include <stdio.h>
#include <string.h>

void reverse(char s[]);

#define LIMIT 1000

void itoa(long n, char s[]);

int main() {
  char s[LIMIT];

  itoa(INT_MIN, s);
  printf("Original min %d\n", INT_MIN);
  printf("%s\n", s);

  return 0;
}

void itoa(long n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;           /* make n positive */

  i = 0;
  do {
    /* generate digits in reverse order */
    s[i++] = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';

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
