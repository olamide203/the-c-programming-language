#include <stdio.h>
#define MAXLINE 1000

int getnewline(char line[], int max);
int strindex(char source[], char searchfor[]);

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  int found = 0;

  if (argc != 2) {
    printf("Usage: find pattern\n");
    return -1;
  }

  while (getnewline(line, MAXLINE) > 0) {
    if (strindex(line, argv[1]) >= 0) {
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

/*strindex: return index of t in s, -1 if none*/
int strindex(char s[], char t[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; ++i) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}