#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "../build/sorted.h"


void printer(const int len, const int *x)
{
  int i;

  for (i=0; i<len; i++)
    printf("%d ", x[i]);
  
  putchar('\n');
}

int is_sorted(int len, int *x)
{
  int i;
  
  for (i=0; i<len-1; i++)
  {
    if (x[i] > x[i+1])
      return 0;
  }
  
  return 1;
}



#define CHECK(expr, fail_message) \
if (expr){ \
  fprintf(stderr, "FAILED: %s() when len=%d\n", fail_message, len); \
  exit(-1);}

void test(const int len, int *x)
{
  int *orig = malloc(len * sizeof(*orig));
  memcpy(orig, x, len * sizeof(*orig));
  
  sorted_bs(len, x);
  CHECK(!is_sorted(len, x), "sorted_bs");
  
  memcpy(x, orig, len * sizeof(*orig));
  sorted_bdbs(len, x);
  CHECK(!is_sorted(len, x), "sorted_bdbs");
  
  memcpy(x, orig, len * sizeof(*orig));
  sorted_is(len, x);
  CHECK(!is_sorted(len, x), "sorted_is");
  
  memcpy(x, orig, len * sizeof(*orig));
  sorted_qs(len, x);
  CHECK(!is_sorted(len, x), "sorted_qs");
  
  free(orig);
  printf("PASSED: sorts when len=%d\n", len);
}



int main()
{
  int n;
  int *x;
  
  n = 5;
  x = malloc(n * sizeof(*x));
  
  x[0] = 5;
  x[1] = 2;
  x[2] = 1;
  x[3] = 3;
  x[4] = 4;
  
  test(n, x);
  
  free(x);
  
  n = 512;
  x = malloc(n * sizeof(*x));
  
  srand(time(NULL));
  for (int i=0; i<n; i++)
    x[i] = rand() % 100;
  
  test(n, x);
  
  return 0;
}
