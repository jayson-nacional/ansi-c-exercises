// Write the function strindex(s,t) which returns the position of the rightmost
// occurrence of t in s, or -1 if there is none.

#include <stdio.h>
#include <string.h>

int r_strindex(char s[], char t[]);

int main() {
  char source[] = "This is a sample test program. This is another test text.";
  char searchfor[] = "test";

  printf("Rightmost index: %d\n", r_strindex(source, searchfor));

  return 0;
}

int r_strindex(char s[], char t[]) {
  int s_len = strlen(s);
  int t_len = strlen(t);

  int j, k;
  for (--s_len; s_len >= 0; s_len--) {
    for (j = s_len, k = t_len - 1; k >= 0 && s[j] == t[k]; j--, k--)
      ;

    if (k < 0)
      return s_len - t_len + 1;
  }

  return -1;
}
