// Exercise 3
// Given the basic framework, it's straightforward to extend the calculator. Add
// the modulus (%) operator and provisions for negative numbers.

// Exercise 4
// Add the commands to print the top elements of the stack without popping, to
// duplicate it, and to swap the top two elements. Add a command to clear the
// stack.

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define SIN '1'
#define EXP '2'
#define POW '3'

int getop(char[]);
void push(double);
double pop(void);
double peek(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%': /* Exercise 3 */
      op2 = pop();
      if (op2 != 0.0)
        push(fmod(pop(), op2));
      else
        printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }

  return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

void duplicate(double copyfrom[], double copyto[]) { /* Exercise 4 */
  if (sp > 0) {
    int i = 0;
    while (i < sp) {
      copyto[i] = copyfrom[i];
      i++;
    }

    copyto[i] = '\0';
  } else {
    printf("error: stack is empty\n");
  }
}

void swap() { /* Exercise 4 */
  if (sp >= 2) {
    double temp1 = pop();
    double temp2 = pop();
    push(temp1);
    push(temp2);
  } else {
    printf("error: cannot swap on a stack that has less than two items\n");
  }
}

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* peek: return the top element of the stack */
double peek(void) { /* Exercise 4 */
  if (sp > 0) {
    return val[sp - 1];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* clear: clear the stack */
void clear(void) { /* Exercise 4 */
  while (sp > 0) {
    pop();
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]) {
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c; /* not a number */
  i = 0;
  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '-') { /* Exercise 3 */
    if (isdigit(s[++i] = c = getchar())) {
      while (isdigit(s[++i] = c = getch()))
        ;
    } else {
      ungetch(c);
      return '-';
    }
  }

  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
/* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
