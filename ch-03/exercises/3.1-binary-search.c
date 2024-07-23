#include <stdio.h>

int bsearch(int x, int v[], int n) {
  int high, low, mid;
  low = 0;
  high = n - 1;

  while (low < high) {
    mid = low + (high - low) / 2;
    if (x > v[mid])
      low = mid + 1;
    else
      high = mid;
  }

  return (x == v[low]) ? low : -1;
}

int main() {
  int v[] = {2, 2, 4, 7, 9, 9, 11, 15, 17};
  printf("%d\n", bsearch(9, v, 9));
  return 0;
}
