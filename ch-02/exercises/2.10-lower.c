#include <stdio.h>

int lower(char c) { return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c; }

int main() {
  printf("%c", lower('A'));
  return 0;
}
