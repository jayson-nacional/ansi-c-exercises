// Rewrite the function lower, which converts upper case letters to lower case,
// with a conditional expression instead of if - else.

#include <stdio.h>

void lower(char s[]);

int main() {
  char s[] = "JoHN SMith";
  lower(s);
  printf("%s\n", s);

  return 0;
}
void lower(char s[]) {
  int i = 0;

  while (s[i] != '\0') {
    s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] += 'a' - 'A' : s[i];
    i++;
  }
}
