#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }

  sign = c == '-' ? -1 : 1;

  if ((c == '-' || c == '+') && !isdigit(c = getch())) {
    ungetch(c);
  }
  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = *pn * 10 + (c - '0');
  }

  *pn *= sign;

  if (c != EOF)
    ungetch(c);

  return c;
}
