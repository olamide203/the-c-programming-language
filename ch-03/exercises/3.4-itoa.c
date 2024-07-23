#include <limits.h>
#include <stdio.h>
#include <string.h>

/* Exercise 3-4. In a twos commplement number representation, our version of the
 *itoa does not handle the largest negative number. Explain why. modify it to
 *print the value correctly, regardless of the machine on which it runs.

 * in a two's complement number system, the largest negative number does not
 have a *positive counterpart (-2^(n-1) - 2^(n-1)-1
 */

#define MAXLENGTH 100

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[]) {
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

  s[i] = '\0';

  reverse(s);
}

int main() {
  int n = INT_MIN;
  char s[MAXLENGTH];

  itoa(n, s);

  printf("%d -> %s\n", n, s);

  return 0;
}
