#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

#define MAXLEN 1000 /* max length of any input line */
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
int getnewline(char *, int);
void qsort2(char *lineptr[], int left, int right);

char *lineptr[MAXLINES];

int main() {
  int nlines;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort2(lineptr, 0, nlines - 1);
    printf("\n");
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = getnewline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = (char *)malloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

int getnewline(char *arr, int maxlength) {
  int i, c;
  for (i = 0; i < maxlength - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    arr[i] = c;
  if (c == '\n')
    arr[i++] = c;

  arr[i] = '\0';
  return i;
}

void writelines(char *lineptr[], int nlines) {
  while (nlines--) {
    printf("%s\n", *lineptr++);
  }
}

void swap(char **i, char **j) {
  char *temp = *i;
  *i = *j;
  *j = temp;
}

void qsort2(char *lineptr[], int left, int right) {
  if (left >= right) {
    return; // Base case: 0 or 1 element left in array
  }
  int pivot = left;
  int mid = left + (right - left) / 2;
  swap(lineptr + mid, lineptr + right);
  for (int i = left; i < right; i++) {
    if (strcmp(lineptr[i], lineptr[right]) < 0) {
      swap(lineptr + pivot++, lineptr + i);
    }
  }
  swap(lineptr + pivot, lineptr + right);
  qsort2(lineptr, left, pivot - 1);
  qsort2(lineptr, pivot + 1, right);
}
