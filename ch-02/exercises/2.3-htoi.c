#include <ctype.h>
#include <stdio.h>

long htoi(const char s[]);

int main() {
  char s[] = "0xABCD";
  char s2[] = "125F";

  printf("%s -> %ld\n", s, htoi(s));
  printf("%s -> %ld\n", s2, htoi(s2));

  return 0;
}

long htoi(const char s[]) {
  long result = 0;
  int i = 0;

  if (s[0] == '0' && s[1] == 'X' || s[1] == 'x')
    i = 2;

  while (s[i] != '\0') {
    result *= 16;

    if (isdigit(s[i]))
      result += s[i] - '0';
    else if (s[i] >= 'A' && s[i] <= 'F')
      result += s[i] - 'A' + 10;
    else if (s[i] >= 'a' && s[i] <= 'f')
      result += s[i] - 'a' + 10;
    else
      return -1;

    ++i;
  }

  return result;
}
