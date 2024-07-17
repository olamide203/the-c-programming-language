#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 100
/* A program to print a histogram of the lengths of words in ints input with
 * horizontal bars  */

int main() {

  int c, length, max, state, i, j;
  int count[MAX_WORD_LENGTH + 1];
  state = OUT;
  length = 0;
  max = 0;

  for (i = 0; i < MAX_WORD_LENGTH + 1; ++i) {
    count[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        state = OUT;
        // TODO: handle length > MAX_WORD_LENGTH
        if (length > max)
          max = length;
        count[length]++;
        length = 0;
      }
    } else {
      if (state == OUT)
        state = IN;
      ++length;
    }
  }

  // handle case where last character is not a whitespace

  if (state == IN) {

    // TODO: handle length > MAX_WORD_LENGTH
    if (length > max)
      max = length;

    count[length]++;
    putchar('\n');
  }

  for (i = 1; i < max + 1; ++i) {
    printf("%3d", i);
    for (j = 0; j < count[i]; ++j) {
      putchar('#');
    }
    putchar('\n');
  }
  return 0;
}
