#include <stdio.h>

int str_len(char s[]);

int main() {
  char test[] = "Hello, world!";
  printf("Length: %d\n", str_len(test));

  return 0;
}

int str_len(char s[]) {
  int i = 0;
  while (s[i] != '\0')
    i++;

  return i;
}
