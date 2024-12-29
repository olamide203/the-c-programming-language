#include <stdio.h>
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int *arr, int left, int right);
void swap(int *i, int *j);

int main() {
  int arr[] = {5, 3, 9, 4, 2, 12, 15, 8, 10, 1, 5, 20};
  int length = (sizeof arr / sizeof arr[0]);
  qsort(arr, 0, length - 1);

  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void qsort(int *arr, int left, int right) {
  // Base case: 0 or 1 element in subarray
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;

  swap(arr + mid, arr + right);

  int pivot = left;

  for (int i = left; i < right; i++) {
    if (arr[i] < arr[right]) {
      swap(arr + i, arr + pivot++);
    }
  }

  swap(arr + pivot, arr + right);
  qsort(arr, left, pivot - 1);
  qsort(arr, pivot + 1, right);
}

void swap(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}
