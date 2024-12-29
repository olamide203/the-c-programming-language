/* strcat: copy string t to the end of s  */

void stringcat(char *s, const char *t) {
  while (*s)
    s++;
  while (*t) {
    *s++ = *t++;
  }

  *s = '\0';
}
