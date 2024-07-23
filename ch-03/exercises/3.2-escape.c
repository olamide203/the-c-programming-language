#include <stdio.h>

/* write a function escape(s, t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t into
 * s. write a function for the other direction as well, converting escape
 * sequences into the real characters*/

#define MAXLENGTH 1000

void escape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  while (t[i] != '\0') {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    default:
      s[j++] = t[i];
      break;
    }
    ++i;
  }
  s[j] = '\0';
}

void descape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  while (t[i] != '\0') {
    switch (t[i]) {
    case '\\':
      switch (t[++i]) {
      case 'n':
        s[j++] = '\n';
        break;
      case 't':
        s[j++] = '\t';
        break;
      default:
        s[j++] = '\\';
        break;
      }
      break;
    default:
      s[j++] = t[i];
      break;
    }
    ++i;
  }
  s[j] = '\0';
}

int main() {

  char s[MAXLENGTH];
  char d[MAXLENGTH];
  char t[] = "Hello world\nHi there\tTab here";

  escape(s, t);
  printf("%s -> %s\n", t, s);

  descape(d, s);
  printf("%s -> %s\n", s, d);
  return 0;
}
