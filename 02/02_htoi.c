// Write a function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The
// allowable digits are 0 through 9, a through f, and A through F.

#include <ctype.h>
#include <stdio.h>

int power(int base, int n);
int htoi(char s[]);

int main() {
  int c, index, result;
  char hex[1000];

  index = 0;
  while ((c = getchar()) != '\n') {
    hex[index++] = c;
  }

  hex[index] = '\0';
  result = htoi(hex);

  printf("Decimal: %d\n", result);
}

int power(int base, int n) {
  int result = 1;
  while (n-- > 0) {
    result = result * base;
  }

  return result;
}

int htoi(char s[]) {
  int length, result, index;

  length = result = index = 0;
  while (s[length] != '\0')
    length++;

  while (--length >= 0 && s[length] != 'x' && s[length] != 'X') {
    if (isdigit(s[length])) {
      result = result + ((s[length] - '0') * power(16, index++));
    } else if (s[length] >= 'a' && s[length] <= 'f') {
      result = result + ((s[length] - 'a' + 10) * power(16, index++));
    } else if (s[length] >= 'A' && s[length] <= 'F') {
      result = result + ((s[length] - 'A' + 10) * power(16, index++));
    } else {
      printf("Invalid index\n");
      return 0;
    }
  }

  if (s[length] == 'x' || s[length] == 'X') {
    if (length != 1 || s[length - 1] != '0') {
      printf("Invalid index\n");
      return 0;
    }
  }

  return result;
}
