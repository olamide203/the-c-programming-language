#include <stdio.h>

int main() {
  /*program to count blanks, tabs and newlines  */
  int x;
  int c;
  long nb, nt, nn;

  nb = 0;
  nt = 0;
  nn = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++nb;
    else if (c == '\t')
      ++nt;
    else if (c == '\n')
      ++nn;
  }
  printf("blanks: %ld, tabs: %ld, newlines: %ld\n", nb, nt, nn);
  return 0;
}
