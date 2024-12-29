/* strcpy: copy t to s; array subscript version */

void strcopy(char *s, char *t) {
  while ((*s++ = *t++))
    ;
}

/* strcomp: return < if s < t, o if s == t, > 0 if s > t*/
int strcomp(const char *s, const char *t) {
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}
