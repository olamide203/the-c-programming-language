#include "calc.h"
#include <ctype.h>
#include <stdio.h>

/* getop: get next character or numeric operand*/
int getop(char s[]) {
  int i, c;
  // skipp space and tabs
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  if (!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}
