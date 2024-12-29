#include <stdio.h>

/* Rewrite the function lower which converts upper case letters to lower case,
 * with a conditional expression insted of if-else*/

int lower(char c) { return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; }

int main() {
  printf("%c\n", lower('A'));
  return 0;
}
