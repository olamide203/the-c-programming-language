/* write version os of the library functions strncpy, strncat and strncmp which
 * operates on at most the first n characters of their argument strings. For
 * example, strncpy(s, t, n) copies at most n characters of t to s*/

/*stringncpy: copy at most n characters of t to s*/
void stringncpy(char *s, char *t, int n) {
  int i;
  for (i = 0; i < n && (*s++ = *t++); ++i)
    ;
  if (i < n)
    *s = '\0';
}

/* stringncat: concatenate at most  first n characters from t to the end of s */
void stringncat(char *s, char *t, int n) {
  /* move to the end of s*/
  while (*s)
    s++;
  /* copy at most n characters of t to s  */
  for (int i = 0; i < n && (*s = *t); ++s, ++t, ++i)
    ;

  *s = '\0';
}

/* stringncmp: return < if s < t, o if s == t, > 0 if s > t for the first n
 * characters */
int stringncmp(char *s, char *t, int n) {
  for (; n && *s == *t; s++, t++, --n)
    if (*s == '\0')
      return 0;
  ;
  if (n == 0)
    return 0;

  return *s - *t;
}
