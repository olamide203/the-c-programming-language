#include <stdio.h>

/* echo command-line arguments*/

int main(int argc, char *argv[]) {
  argv++;
  while (*argv) {
    printf("%s", *argv++);
    if (*argv != NULL) {
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}
