// Our binary search makes two tests inside the loop, when one would suffice (at
// the price of more tests outside.) Write a version with only one test inside
// the loop and measure the difference in run-time.

#include <stdio.h>
#include <time.h>

#define LIMIT 1000000

int binsearch(int x, int v[], int n);

int main() {
  int v[LIMIT];

  for (int i = 0; i < LIMIT; i++) {
    v[i] = i;
  }

  clock_t start = clock();
  int result = binsearch(2468, v, LIMIT);
  clock_t end = clock();

  double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("CPU time: %f seconds\n", cpu_time_used);

  printf("%d\n", result);

  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;

  while (low < high) {
    mid = (low + high) / 2;
    if (x <= v[mid])
      high = mid;
    else
      low = mid + 1;
  }

  if (x == v[mid]) {
    return mid;
  } else if (x == v[mid + 1]) {
    return mid + 1;
  }

  return -1;
}
