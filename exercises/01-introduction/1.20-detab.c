#include <stdio.h>

/* A program that replaces tabs in input with proper number of blanks to space
 * to the next tab stop. assuem a fixed set of tab stops, say every n columns.
 */

#define TAB_STOP 12 /* Assuming there is a tab stop after every n columns  */
void detab(void);

int main() {
  detab();
  return 0;
}
void detab() {
  int c, i, spaces, j;
  i = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      spaces = TAB_STOP - (i % TAB_STOP);
      for (j = 0; j < spaces; ++j) {
        putchar(' ');
        ++i;
      }
    } else if (c == '\n') {
      putchar('\n');
      i = 0;
    } else {
      putchar(c);
      ++i;
    }
  }
}
