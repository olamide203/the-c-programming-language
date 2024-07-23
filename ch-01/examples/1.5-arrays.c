#include <stdio.h>

/* A program that counts the number of occurences of each digit, white space
 * characters (blank, tab, newline), and of all other characters */

int main() {
  int c, i, nother, nwhite;

  int ndigit[10];
  for (i = 0; i < 10; ++i) {
    ndigit[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= 10)
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  }
  printf("digits=");

  for (i = 0; i < 10; ++i) {
    printf("%d", ndigit[i]);
  }

  printf("white spaces = %d, others = %d\n", nwhite, nother);
  return 0;
}
