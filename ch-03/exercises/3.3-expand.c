#include <ctype.h>
#include <stdio.h>

/* Write a function expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for
 * letters of either case, and digits and be prepared to handle cases like a-b-c
 * and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally.*/

#define MAXLENGTH 100

int isvalid_range(char start, char end) {
  return ((islower(start) && islower(end)) ||
          (isupper(start) && isupper(end)) || (isdigit(start) && isdigit(end)));
}

void expand(char s1[], char s2[]) {

  int i, j, k;
  for (i = 0, j = 0; s1[i] != '\0' && j < MAXLENGTH - 1; ++i) {
    if (s1[i] == '-' && i != 0 && s1[i + 1] != '\0' &&
        isvalid_range(s1[i - 1], s1[i + 1])) {
      char start = s1[i - 1];
      char stop = s1[i + 1];
      char step = start <= stop ? 1 : -1;
      for (k = start + step; k != stop && j < MAXLENGTH - 1; k += step) {
        s2[j++] = k;
      }
    } else {
      s2[j++] = s1[i];
    }
  }
  s2[j] = '\0';
}

int main() {
  char s1[] = "-a-z0-9Z-A";
  char s2[MAXLENGTH];

  expand(s1, s2);
  printf("%s\n", s2);
  return 0;
}
