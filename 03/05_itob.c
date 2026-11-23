// Write the function itob(n,s,b) that converts the integer n into a base b
// character representation in the string s. In particular, itob(n,s,16) formats
// s as a hexadecimal integer in s.

#include <stdio.h>
#include <string.h>

#define LIMIT 1000

void itob(int n, char s[], int base);
void reverse(char s[]);

int main() {
  char s[LIMIT];

  itob(1234, s, 16);
  printf("%s\n", s);

  return 0;
}

void itob(int n, char s[], int base) {
  int quotient, remainder;
  int i = 0;

  do {
    quotient = n / base;
    remainder = n - (base * quotient);

    if (remainder >= 0 && remainder <= 9)
      s[i++] = remainder % 10 + '0';
    else
      s[i++] = remainder + 'A' - 10;

    n = quotient;
  } while (quotient != 0);

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
