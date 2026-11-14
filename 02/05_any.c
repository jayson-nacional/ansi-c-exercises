// Write the function any(s1,s2), which returns the first location in a string
// s1 where any character from the string s2 occurs, or -1 if s1 contains no
// characters from s2 . (The standard library function strpbrk does the same job
// but returns a pointer to the location.)

// get the find index
// loop through the s1 char and match it to s2

#include <stdio.h>

int find_index(char s[], char a);
int any(char s1[], char s2[]);

int main() {
  int c;

  char test1[] = "Jayson Nacional";
  char test2[] = "xz";

  printf("%d", any(test1, test2));

  return 0;
}

int any(char s1[], char s2[]) {
  int i = 0;
  while (s1[i] != '\0') {
    if (find_index(s2, s1[i]) >= 0)
      return i;

    i++;
  }

  return -1;
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
