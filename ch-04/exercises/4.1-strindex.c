#include <stdio.h>
#include <string.h>
/* Write the function strindex(s, t) which returns the position of the rightmost
 * occurence of t in s or -1 if there is none */

int strindex(char s[], char t[]) {
  int i, j, k;

  for (i = strlen(s) - 1; i >= 0; --i) {
    for (j = i, k = strlen(t) - 1; k >= 0 && s[j] == t[k]; --k, --j)
      ;
    if (k < 0) {
      return j + 1;
    }
  }
  return -1;
}

int main() {
  char s[] = "Hello world";
  char t[] = " wo";
  int pos = strindex(s, t);

  printf("%d\n", pos);
  return 0;
}
