#include <ctype.h>

/* atoi: converts s to integer  */

int atoi(char s[]) {
  int n, i;
  n = 0;
  for (i = 0; isdigit(s[i]) && s[i] != '\0'; ++i)
    n = 10 * n + s[i] - '0';
  return n;
}
