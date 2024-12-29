#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

struct key {
  char *word;
  int count;
} keytab[] = {"auto",  0, "break",    0, "case",    0, "char",     0,
              "const", 0, "continue", 0, "default", 0, "unsigned", 0,
              "void",  0, "volatile", 0, "while",   0};

#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

int main() {

  char c;
  char word[MAXWORD];
  struct key *n;

  while ((c = getword(word, MAXWORD)) != EOF) {
    if (isalpha(c)) {
      if ((n = binsearch(word, keytab, NKEYS))) {
        n->count++;
      }
    }
  }

  for (n = keytab; n < keytab + NKEYS; ++n) {
    if (n->count > 0)
      printf("%s - %4d\n", n->word, n->count);
  }

  return 0;
}

/* binsearch: find word in tab[0]......tab[n-1]*/

struct key *binsearch(char *word, struct key tab[], int n) {
  int cond;
  struct key *low = &tab[0];
  struct key *high = &tab[n - 1];
  struct key *mid;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if ((cond = strcmp(word, mid->word)) < 0) {
      high = mid - 1;
    } else if (cond > 0) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return NULL;
}

int getword(char *word, int lim) {
  char *p = word;
  int c, getch(void);
  void ungetch(int);

  while (isspace(c = getch()))
    ;

  if (c != EOF)
    *p++ = c;

  if (!isalpha(c)) {
    *p = '\0';
    return c;
  }

  for (; --lim > 0; p++) {
    if (!isalnum(*p = getch())) {
      ungetch(*p);
      break;
    }
  }

  *p = '\0';

  return word[0];
}
