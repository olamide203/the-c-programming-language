#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length   */

int getnewline(char line[], int max);
char *strindex(const char source[], const char searchfor[]);

int main() {
  char line[MAXLINE];
  int found = 0;
  char pattern[] = "ould";

  while (getnewline(line, MAXLINE) > 0) {
    if (strindex(line, pattern) != NULL) {
      printf("%s", line);
      found++;
    }
  }
  return found;
}

/* getnewline: get line into s, return length*/
int getnewline(char s[], int max) {
  int c, i;
  i = 0;

  while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = '\n';
  }

  s[i] = '\0';

  return i;
}

/*strindex: return pointer to first occurence of t in s.
 * return s if t is an empty string
 * return NULL if t is not in s
 */

char *strindex(const char *s, const char *t) {
  if (*t == '\0') {
    return (char *)s;
  }

  for (; *s != '\0'; ++s) {
    const char *p = s;
    const char *q = t;

    while (*p != '\0' && *q != '\0' && *p++ == *q++)
      ;
    if (*q == '\0')
      return (char *)s;
  }
  return NULL;
}
