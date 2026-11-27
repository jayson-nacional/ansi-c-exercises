#include <stdio.h>

int main() {
  int is_equal(char s1[], char s2[]);

  char s1[] = "sin";
  char s2[] = "sin";

  printf("Test comparison: %d\n", is_equal(s1, s2));
  return 0;
}

int is_equal(char s1[], char s2[]) {
  int i = 0;
  while (s1[i] == s2[i]) {
    i++;
  }

  if (s1[i - 1] == '\0' && s2[i - 1] == '\0')
    return 1;

  return 0;
}
