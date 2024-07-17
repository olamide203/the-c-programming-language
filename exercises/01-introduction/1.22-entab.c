#include <stdio.h>

/* A program entab that replaces single blanks by the minimum number of blanks
 * and spaces to achieve the same spacing.*/

#define TAB_STOB 8

int main() {
  int c, spaces, pos;
  c = 0;
  spaces = 0;
  pos = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++pos;
      ++spaces;
    } else if (c == '\n') {
      spaces = 0;
      pos = 0;
    } else {
      // calculate spaces to next tab stop
      int x = TAB_STOB - (pos - spaces) % TAB_STOB;
      while (spaces > 0) {
        if (spaces >= x) {
          putchar('\t');
          spaces -= x;
        } else {
          putchar(' ');
          --spaces;
        }
      }
      putchar(c);
      ++pos;
    }
  }
  return 0;
}
