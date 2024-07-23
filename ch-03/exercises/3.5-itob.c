#include <limits.h>
#include <stdio.h>
#include <string.h>

/* Write a function itob(n, s, b) that converts the integers n to a base b
 * character represented in the string s. In particular, itob(n, s, 16) formats
 * s as a hexadecimal interger in s*/

#define MAXLENGTH 100

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itob(int n, char s[], int b) {

  // TODO: Error checking for invalid base b < 2 or b > 36

  int i;
  unsigned int un, r;

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
    r = un % b;
    if (r < 10) {
      s[i++] = '0' + r;
    } else {
      s[i++] = 'A' + r - 10;
    }
    un /= b;
  } while (un > 0 && i < MAXLENGTH);

  if (n < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}

int main() {
  int n = 127;
  char s[MAXLENGTH];

  itob(n, s, 16);
  printf("%d -> %s\n", n, s);

  n = INT_MIN;
  itob(n, s, 16);
  printf("%d -> %s\n", n, s);
  return 0;
}
