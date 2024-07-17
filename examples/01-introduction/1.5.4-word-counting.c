#include <stdio.h>

#define IN 1
#define OUT 0

/*count lines words and characters in input*/

int main() {
  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = 0;
  for (nc = 0; (c = getchar()) != EOF; ++nc) {
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      ++nw;
      state = IN;
    }
  }
  printf("%d, %d, %d\n", nl, nw, nc);
  return 0;
}
