/* write a function strend(s, t) which returns 1 if string t occurs at the end
 * of string s and zero otherwise */

int strend(char *s, char *t) {
  /*make copies of pointers s and t*/
  char *ps = s;
  char *pt = t;
  /* move to the end of s */
  while (*ps)
    ps++;

  /* move to the end of t*/
  while (*pt)
    pt++;

  /* compare characters from the back*/
  for (; ps >= s && pt >= t; --ps, --pt)
    if (*pt != *ps) {
      return 0;
    }

  return pt < t ? 1 : 0;
}
