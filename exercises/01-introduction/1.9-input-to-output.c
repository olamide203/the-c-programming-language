#include <stdio.h>

/*Exercise 1-9. copy input to output replacing each string of one or more blanks
 * by a single blank  */

int main() {
  int curr_char, prev_char = '\n';
  while ((curr_char = getchar()) != EOF) {
    if (curr_char == ' ' && prev_char == ' ')
      continue;
    prev_char = curr_char;
    putchar(curr_char);
  }

  return 0;
}
