#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

/* Write a program to determine the range of char, short, int, and long
 * variables, both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation.  */

int main() {

  printf("unsigned char: %d - %.0f\n", 0,
         pow(2, sizeof(unsigned char) * 8) - 1);
  printf("signed char: %.0f - %.0f\n", -pow(2, sizeof(char) * 8 - 1),
         pow(2, sizeof(char) * 8 - 1) - 1);
  return 0;
}
