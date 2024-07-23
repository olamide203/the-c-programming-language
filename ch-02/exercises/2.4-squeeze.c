#include <stdio.h>

/* Write an alternatve version of the squeeze(s1, s2) that deletes character in
 * s1 that matches any character in string s2*/

enum boolean { FALSE, TRUE };

void squeeze(char s1[], const char s2[]) {
  int i, j, k;

  enum boolean matches = FALSE;

  for (i = k = 0; s1[i] != '\0'; i++) {
    matches = FALSE;
    for (j = 0; s2[j] != '\0'; j++)
      if (s1[i] == s2[j]) {
        matches = TRUE;
        break;
      }
    if (!matches)
      s1[k++] = s1[i];
  }
  s1[k] = '\0';
}

int main() {
  char s1[] = "Hello world";
  const char s2[] = "lo";

  squeeze(s1, s2);
  printf("%s\n", s1);

  return 0;
}
