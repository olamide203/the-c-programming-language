#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

int main() {
  char s[] = "123.45e-6";

  printf(" %s - %.9f\n", s, atof(s));
}

/* expand atof to handle scientific notation of the form 123.45e-6 */
double atof(char s[]) {
  double val, power;
  int i, sign, exp, expsign;

  /* skip white space*/
  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  expsign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (exp = 0; isdigit(s[i]); i++)
    exp = 10 * exp + (s[i] - '0');
  exp *= expsign;

  while (exp > 0) {
    power /= 10.0;
    exp--;
  }
  while (exp < 0) {
    power *= 10;
    exp++;
  }
  return sign * val / power;
}
