// Write an alternative version of squeeze(s1,s2) that deletes each character in
// s1 that matches any character in the string s2.

#include <stdio.h>

int find_index(char s[], char a);
void squeeze(char s1[], char s2[]);

int main() {
  int c;

  char test1[] = "Jayson Nacional";
  char test2[] = "ab";

  squeeze(test1, test2);
  printf("%s", test1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j;

  i = j = 0;

  while (s1[i] != '\0') {
    if (find_index(s2, s1[i]) < 0)
      s1[j++] = s1[i];

    i++;
  }

  s1[j] = '\0';
}

int find_index(char s[], char a) {
  int i = 0;

  while (s[i] != '\0') {
    if (s[i] == a)
      return i;

    i++;
  }

  return -1;
}
