// Write a function expand(s1,s2) that expands shorthand notations like a-z in
// the string s1 into the equivalent complete list abc...xyz in s2. Allow for
// letters of either case and digits, and be prepared to handle cases like a-b-c
// and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.

#include <stdio.h>
#include <string.h>

#define LIMIT 1000

void expand(char s1[], char s2[]);

int main() {
  char s1[] = "a-z0-9a-b-cA-Z--";
  char s2[LIMIT];

  expand(s1, s2);

  printf("%s\n", s2);

  return 0;
}

void expand(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s1[i] == '-'; i++)
    ; // removes leading '-'

  for (j = strlen(s1) - 1; s1[j] == '-'; j--)
    ; // removes trailing '-'

  s1[++j] = '\0';

  int p;
  for (j = 0; s1[i] != '\0'; i++) {
    if (s1[i] != '-') {
      if (p == '-') {            // check if for expansion
        if (s1[i] > s1[i - 2]) { // valid range
          for (char k = s1[i - 2] + 1; k <= s1[i]; k++) {
            s2[j++] = k; // expand
          }
        } else { // print as is, invalid range
          s2[j++] = '-';
          s2[j++] = s1[i];
        }
      } else {
        s2[j++] = s1[i];
      }
    }

    p = s1[i];
  }

  s2[j] = '\0';
}
