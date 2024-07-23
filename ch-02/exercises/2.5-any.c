#include <limits.h>
#include <stdio.h>

/* Write the function any(s1, s2) which returns the first location in a string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2.*/

int any(const char s1[], const char s2[]) {
  int i, j;
  for (i = 0; s1[i] != '\0'; ++i) {
    for (j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }

  return -1;
}

int any2(const char s1[], const char s2[]) {
  int i;
  // use a lookup table for characters in s2
  int char_set[UCHAR_MAX + 1] = {0};

  for (i = 0; s2[i] != '\0'; ++i)
    char_set[(unsigned char)s2[i]] = 1;

  for (i = 0; s1[i] != '\0'; ++i) {
    if (char_set[(unsigned char)s1[i]])
      return i;
  }

  return -1;
}

int main() {
  const char s1[] = "Hello world";
  const char s2[] = "lo";

  printf("%d\n", any2(s1, s2));

  return 0;
}
