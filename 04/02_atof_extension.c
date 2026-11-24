// Extend atof to handle scientific notation of the form
// 123.45e-6
// where a floating-point number may be followed by e or E and an optionally
// signed exponent.

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

int main() {
  double atof(char[]);
  char s[] = "123.45E-6";
  printf("%g\n", atof(s));

  return 0;
}

double atof(char s[]) {
  double pow(double base, double exponent);
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }

  int notation = 1;
  if (s[i] == 'e' || s[i] == 'E' && s[i + 1] == '-' && isdigit(s[i + 2])) {
    notation = pow(10, (s[i + 2] - '0') % 10);
  }

  return sign * val / power / notation;
}

double pow(double base, double exponent) {
  double result = 1;

  while (exponent-- > 0) {
    result = result * base;
  }

  return result;
}
