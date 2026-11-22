// Write a function escape(s,t) that converts characters like newline and tab
// into visible escape sequences like \n and \t as it copies the string t to s.
// Use a switch. Write a function for the other direction as well, converting
// escape sequences into the real characters.

#include <stdio.h>

#define LIMIT 1000

void escape(char s[], char t[]);
void nonescape(char s[], char t[]);

int main() {
  char s1[LIMIT];
  char t1[] = "Test string";
  t1[2] = '\n';
  t1[3] = '\t';

  escape(s1, t1);
  printf("%s\n", s1);

  char s2[LIMIT];
  char t2[] = "Hello\t\nworld!";

  nonescape(s2, t2);
  printf("%s\n", s2);

  return 0;
}

void escape(char s[], char t[]) {
  int i = 0;
  int j = 0;

  while (t[i] != '\0') {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    default:
      s[j++] = t[i];
      break;
    }

    i++;
  }

  s[j] = '\0';
}

void nonescape(char s[], char t[]) {
  int p;
  int i = 0;
  int j = 0;

  while (t[i] != '\0') {
    switch (t[i]) {
    case '\\':
      break;
    case 'n':
      if (p == '\\') {
        s[j++] = '\n';
      }
      break;
    case 't':
      if (p == '\\') {
        s[j++] = '\t';
      }
      break;
    default:
      s[j++] = t[i];
      break;
    }

    p = t[i];
    i++;
  }

  s[j] = '\0';
}
