#include <limits.h>
#include <stdio.h>
#include <string.h>

/* Write a version of itoa that accepts three arguments instead of two. the
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough*/

#define MAXLENGTH 100

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[], int min) {
  int i;
  unsigned int un;

  if (n < 0) {
    if (n == INT_MIN) {
      un = (unsigned int)INT_MAX + 1;
    } else {
      un = -n;
    }
  } else {
    un = n;
  }

  i = 0;

  do {
    s[i++] = un % 10 + '0';
  } while ((un /= 10) > 0);

  if (n < 0)
    s[i++] = '-';

  while (i < min) {
    s[i++] = ' ';
  }

  s[i] = '\0';

  reverse(s);
}

int main() {
  int n = 500;
  char s[MAXLENGTH];

  itoa(n, s, 20);

  printf("%d -> %s\n", n, s);

  return 0;
}
