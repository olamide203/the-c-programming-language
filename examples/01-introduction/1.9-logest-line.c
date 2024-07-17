#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

/* A program that reads a set of text lines and prints the longest */

/* Function prototypes */
int getnewline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getnewline(line, MAXLINE)) != 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0)
    printf("%s", longest);
  return 0;
}

/* getline: read a line into s, return length */
int getnewline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }

  s[i] = '\0';
  return i;
}

/* copy: copy `from` into `to`; assume to is big enough */

void copy(char to[], char from[]) {
  int i;

  for (i = 0; (to[i] = from[i]) != '\0'; ++i)
    ;
}
